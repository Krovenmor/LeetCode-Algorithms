#include <iostream>
#include <string>

class Solution {
public:

	std::string intToRoman(int num) {

		std::string thousands[] = { "", "M", "MM", "MMM" };
		std::string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		std::string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		std::string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

		return thousands[num / 1000] +
			hundreds[(num % 1000) / 100] +
			tens[(num % 100) / 10] +
			ones[num % 10];

	}

};

int main() {

	Solution sol;
	
	// Example 1:
	int ex_1 = 3749;
	std::string answer_1 = sol.intToRoman(ex_1);

	// Example 2:
	int ex_2 = 58;
	std::string answer_2 = sol.intToRoman(ex_2);

	// Example 3:
	int ex_3 = 1994;
	std::string answer_3 = sol.intToRoman(ex_3);

	std::cout << "\nanswer_1 = " << answer_1 << "\n";
	std::cout << "answer_2 = " << answer_2 << "\n";
	std::cout << "answer_3 = " << answer_3 << "\n";

}