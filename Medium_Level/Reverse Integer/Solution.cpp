#include <iostream>

class Solution {
public:

	int reverse(int x) {

		int r_val = 0;
		short int to_add;

		while (x != 0) {
			to_add = x % 10;
			
			if (r_val > INT_MAX / 10 || (r_val == INT_MAX / 10 && to_add > 7)) {
				return 0;
			}
			if (r_val < INT_MIN / 10 || (r_val == INT_MIN / 10 && to_add < -8)) {
				return 0;
			}

			x /= 10;
			r_val = r_val * 10 + to_add;
		}

		return r_val;

	}

};

int main() {

	Solution sol;
	
	// Example 1:
	int ex_1 = 2147483647;
	int answer_1 = sol.reverse(ex_1);

	// Example 2:
	int ex_2 = 214748364;
	int answer_2 = sol.reverse(ex_2);

	// Example 3:
	int ex_3 = -123;
	int answer_3 = sol.reverse(ex_3);

	std::cout << "\nanswer_1 = " << answer_1 << "\n";
	std::cout << "answer_2 = " << answer_2 << "\n";
	std::cout << "answer_3 = " << answer_3 << "\n";
}