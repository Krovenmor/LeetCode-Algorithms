#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int r_value = 0;

		for (int i_left = 0, i_right = height.size() - 1; i_left < i_right;){
			
			int value = std::min(height[i_left], height[i_right]) * (i_right - i_left);
			if (value > r_value) r_value = value;

			if (height[i_left] < height[i_right]){
				i_left++;
			}else{
				i_right--;
			}

		}
        
		return r_value;
    }
};

int main(){

	Solution sol;

    // Example 1:
	std::vector<int> ex_1 = {1,8,6,2,5,4,8,3,7};
	int ans_1 = sol.maxArea(ex_1);

	// Example 2:
	std::vector<int> ex_2 = {1,1};
	int ans_2 = sol.maxArea(ex_2);

	// Out:
	std::cout << "\nExample 1: '" << ans_1 << "'\n";
	std::cout << "Example 2: '" << ans_2 << "'\n";

}