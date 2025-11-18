#include <iostream>
#include <string>


class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {

		int max_value = 0, i1 = 0;
		int symbols[128] = {0};

		for (int i2 = 0; i2 != s.size(); ++i2) {

			symbols[s[i2]]++;

			while (symbols[s[i2]] > 1) {
				symbols[s[i1]]--;
				i1++;
			}

			max_value = std::max(max_value, i2 - i1 + 1);

		}

		return max_value;

	}
};


int main() {

	Solution s;

	// Example 1:
	std::string s1 = "abcabcbb";
	int res1 = s.lengthOfLongestSubstring(s1);

	// Example 2:
	std::string s2 = "bbbbb";
	int res2 = s.lengthOfLongestSubstring(s2);

	// Example 3:
	std::string s3 = "pwwkew";
	int res3 = s.lengthOfLongestSubstring(s3);

	// Example 4:
	std::string s4 = "dvdf";
	int res4 = s.lengthOfLongestSubstring(s4);

	// Example 5:
	std::string s5 = "aab";
	int res5 = s.lengthOfLongestSubstring(s5);

	// Out:
	std::cout << "Res1: '" << res1 << "'\n";
	std::cout << "Res2: '" << res2 << "'\n";
	std::cout << "Res3: '" << res3 << "'\n";
	std::cout << "Res4: '" << res4 << "'\n";
	std::cout << "Res5: '" << res5 << "'\n";

}