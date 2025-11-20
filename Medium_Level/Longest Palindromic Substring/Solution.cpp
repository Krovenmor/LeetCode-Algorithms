#include <iostream>
#include <string>
#include <vector>

class Solution {
public:

	std::string check_palindrome(const std::string& string, size_t index_l, size_t index_r, const size_t& current_size) {

		while (index_l > 0 && index_r + 1 < string.size() && string[index_l - 1] == string[index_r + 1]) {
			index_l--, index_r++;
		}
		if (current_size > index_r - index_l + 1) return "";
		return string.substr(index_l, index_r - index_l + 1);

	}

    // In worst scenario ~ O(N^2) like "aaaaaaaa...aaaaaa"
	std::string longestPalindrome_dumb(std::string s) {

		std::string longest_polindrome = { s[0] };
		size_t current_size = 1;

		for (size_t i = 0; i < s.size(); ++i) {

			if (i != 0 && i + 1 < s.size() && s[i - 1] == s[i + 1]) {
				std::string timeless(check_palindrome(s, i - 1, i + 1, current_size));
				if (timeless != "") {
					longest_polindrome = std::move(timeless);
					current_size = longest_polindrome.size();
				}
			}

			if (i + 1 < s.size() && s[i] == s[i + 1]) {
				std::string timeless(check_palindrome(s, i, i + 1, current_size));
				if (timeless != "") {
					longest_polindrome = std::move(timeless);
					current_size = longest_polindrome.size();
				}
			}

			if (current_size / 2 > s.size() - i) {
				return longest_polindrome;
			}

		}

		return longest_polindrome;
	}

	std::string get_formatted(const std::string s) {
		std::string s_formatted(s.size() * 2 + 3, '#');
		s_formatted[0] = '$';
		s_formatted[s.size() * 2 + 2] = '@';

		size_t index_to_formatted = 2;
		for (const char& c : s) {
			s_formatted[index_to_formatted] = c;
			index_to_formatted += 2;
		}
		return s_formatted;
	}

	// Manacher's Algorithm ~ O(N)
	std::string longestPalindrome(std::string s) {

		std::string T = get_formatted(s);
		
		int n = T.size();
		std::vector<int> P(n, 0);

		int C = 0, R = 0;

		for (int i = 1; i < n - 1; ++i) {
			int mirror = 2 * C - i;

			if (i < R) {
				P[i] = std::min(R - i, P[mirror]);
			}

			while (T[i + (1 + P[i])] == T[i - (1 + P[i])]) {
				P[i]++;
			}

			if (i + P[i] > R) {
				C = i;
				R = i + P[i];
			}
		}

		int max_len = 0;
		int center_index = 0;
		for (int i = 1; i < n - 1; i++) {
			if (P[i] > max_len) {
				max_len = P[i];
				center_index = i;
			}
		}

		int start = (center_index - max_len) / 2;
		return s.substr(start, max_len);
	}
};


int main() {
	
	Solution sol;

	// Example 1:
	std::string ex_1 = "babad";
	std::string answer_1 = sol.longestPalindrome(ex_1);

	// Example 2:
	std::string ex_2 = "cbbd";
	std::string answer_2 = sol.longestPalindrome(ex_2);

	// Example 3:
	std::string ex_3 = "bb";
	std::string answer_3 = sol.longestPalindrome(ex_3);

	// Example 4:
    std::string ex_4 = "amabobamchl";
    std::string answer_4 = sol.longestPalindrome(ex_4);

    std::cout << "\nanswer_1 = " << answer_1 << "\n";
    std::cout << "answer_2 = " << answer_2 << "\n";
    std::cout << "answer_3 = " << answer_3 << "\n";
    std::cout << "answer_4 = " << answer_4 << "\n";

}