#include <iostream>
#include <string>

class Solution {
public:

	int get_int_from_romanChar(const char& c) {
		switch (c)
		{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return -1;
		}
	}

	int romanToInt(std::string s) {

		int i_prev = 0, i_return = 0;
		for (const char& c : s) {

			int i_ = get_int_from_romanChar(c);

			if (i_prev < i_) {
				i_return += (i_ - 2 * i_prev);
			}
			else {
				i_return += i_;
			}

			i_prev = i_;

		}

		return i_return;

	}
};

int main() {

	Solution sol;
	
	// Example 1:
	std::string ex_1 = "III";
	int answer_1 = sol.romanToInt(ex_1);

	// Example 2:
	std::string ex_2 = "LVIII";
	int answer_2 = sol.romanToInt(ex_2);

	// Example 3:
	std::string ex_3 = "MCMXCIV";
	int answer_3 = sol.romanToInt(ex_3);

	std::cout << "\nanswer_1 = " << answer_1 << "\n";
	std::cout << "answer_2 = " << answer_2 << "\n";
	std::cout << "answer_3 = " << answer_3 << "\n";

}