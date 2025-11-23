#include <iostream>
#include <string>

class Solution {
public:
	int myAtoi(std::string s) {

		short int i_signedness = 1;
		int i_value = 0;
		int step = 1;

		for (const char& c : s) {

			switch (step) {
			case 1:
			{
				if (c == ' ') continue;
				step++;
				[[fallthrough]];
			}
			case 2:
			{
				if (c == '-' || c == '+') {
					if (c == '-') {
						i_signedness *= -1;
					}
					step++;
					break;
				}
				step++;
				[[fallthrough]];
			}
			case 3:
			{
				if (static_cast<short int>(c) == 48) continue;
				step++;
				[[fallthrough]];
			}
			case 4:
			{
				short int i_ascii_code = static_cast<short int>(c);
				if (i_ascii_code < 48 || i_ascii_code > 57) {
					return i_value;
				}

				short int to_add = (i_ascii_code - 48) * i_signedness;

				if (i_value > INT_MAX / 10 || (i_value == INT_MAX / 10 && to_add > 7)) {
					return INT_MAX;
				}
				else if (i_value < INT_MIN / 10 || (i_value == INT_MIN / 10 && to_add < -8)) {
					return INT_MIN;
				}
				else {
					i_value = i_value * 10 + to_add;
				}
				break;
			}

			default:
				break;
			}

		}

		return i_value;

	}
};

int main() {

	Solution sol;
	
	// Example 1:
	std::string ex_1 = "42";
	int answer_1 = sol.myAtoi(ex_1);

	// Example 2:
	std::string ex_2 = " -042";
	int answer_2 = sol.myAtoi(ex_2);

	// Example 3:
	std::string ex_3 = "1337c0d3";
	int answer_3 = sol.myAtoi(ex_3);

	// Example 4:
	std::string ex_4 = "0-1";
	int answer_4 = sol.myAtoi(ex_4);

	// Example 5:
	std::string ex_5 = "words and 987";
	int answer_5 = sol.myAtoi(ex_5);

	// Example 6:
	std::string ex_6 = "-2147483648";
	int answer_6 = sol.myAtoi(ex_6);

	std::cout << "\nanswer_1 = " << answer_1 << "\n";
	std::cout << "answer_2 = " << answer_2 << "\n";
	std::cout << "answer_3 = " << answer_3 << "\n";
	std::cout << "answer_4 = " << answer_4 << "\n";
	std::cout << "answer_5 = " << answer_5 << "\n";
	std::cout << "answer_6 = " << answer_6 << "\n";
}