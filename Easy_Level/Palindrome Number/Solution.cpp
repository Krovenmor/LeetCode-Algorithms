#include <iostream>

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x < 10) return true;

		int original = x;
		long long reversed = 0;

		while (x > 0) {
			reversed = reversed * 10 + x % 10;
			x /= 10;
		}

		return original == reversed;
	}
};

int main() {

	Solution sol;

	// Example 1:
	int ex_1 = 121;
	std::string answer_1 = (sol.isPalindrome(ex_1)) ? "true" : "false";

	// Example 2:
	int ex_2 = -121;
	std::string answer_2 = (sol.isPalindrome(ex_2)) ? "true" : "false";

	// Example 3:
	int ex_3 = 10;
	std::string answer_3 = (sol.isPalindrome(ex_3)) ? "true" : "false";

	// Example 4:
	int ex_4 = 1000030001;
	std::string answer_4 = (sol.isPalindrome(ex_4)) ? "true" : "false";

	std::cout << "\nanswer_1 = " << answer_1 << "\n";
	std::cout << "answer_2 = " << answer_2 << "\n";
	std::cout << "answer_3 = " << answer_3 << "\n";
	std::cout << "answer_4 = " << answer_4 << "\n";
}