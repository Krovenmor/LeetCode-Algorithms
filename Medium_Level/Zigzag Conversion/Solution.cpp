#include <iostream>
#include <string>

class Solution {
public:
    // Optimal solution ~ O(N)
	std::string convert(std::string s, int numRows) {

		std::string r_string(s.size(), '#');
		size_t current_index = 0;

		int max_skip_value = 2 * numRows - 2;
		if (max_skip_value == 0) max_skip_value++;
		
		for (int i = 0; i != numRows; ++i) {

			if (i == 0 || i + 1 == numRows) {
				size_t index = i;
				while (index < s.size()) {
					r_string[current_index] = s[index];
					index += max_skip_value;
					current_index++;
				}
			}
			else {
				size_t index = i;
				int current_skip_value = max_skip_value - (i * 2);
				bool flag = true;

				while (index < s.size()) {

					r_string[current_index] = s[index];
					
					if (flag) {
						index += current_skip_value;
					}
					else {
						index += (max_skip_value - current_skip_value);
					}

					flag = !flag;
					current_index++;
				}
			}
		}
		return r_string;
	}
};

int main() {

	Solution sol;

	// Example 1:
	std::string ex_1 = "PAYPALISHIRING";
	int numRows_1 = 3;
	std::string answer_1 = sol.convert(ex_1, numRows_1);

	// Example 2:
	std::string ex_2 = "PAYPALISHIRING";
	int numRows_2 = 4;
	std::string answer_2 = sol.convert(ex_2, numRows_2);

	// Example 3:
	std::string ex_3 = "A";
	int numRows_3 = 1;
	std::string answer_3 = sol.convert(ex_3, numRows_3);

	// Example 4:
	std::string ex_4 = "AB";
	int numRows_4 = 1;
	std::string answer_4 = sol.convert(ex_4, numRows_4);

	std::cout << "\nanswer_1 = " << answer_1 << "\n";
	std::cout << "answer_2 = " << answer_2 << "\n";
	std::cout << "answer_3 = " << answer_3 << "\n";
	std::cout << "answer_4 = " << answer_4 << "\n";

}