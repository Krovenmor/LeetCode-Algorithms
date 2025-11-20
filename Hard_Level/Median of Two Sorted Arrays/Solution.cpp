#include <iostream>
#include <vector>



template <class A>
std::ostream& operator << (std::ostream& out, const std::vector<A>& vector_to_print) {
	for (const A& a : vector_to_print) {
		out << a << " ";
	}
	out << "\n";
	return out;
}

class Solution {
public:
	// Just brute force, O(N + M) + extra memory (N + M)
	double findMedianSortedArrays_stupid(std::vector<int>& nums1, std::vector<int>& nums2) {
		
		double d_return = 0.0;

		size_t all_size = nums1.size() + nums2.size();
		size_t index = all_size / 2;

		std::vector<int> stupid_vector;
		stupid_vector.reserve(index + 1);

		size_t i1 = 0, i2 = 0;
		while ((i1 < nums1.size() || i2 < nums2.size()) && stupid_vector.size() != index + 1) {

			if (i1 < nums1.size() && i2 < nums2.size()) {

				if (nums1[i1] <= nums2[i2]) {
					stupid_vector.push_back(nums1[i1]);
					i1++;
				}
				else {
					stupid_vector.push_back(nums2[i2]);
					i2++;
				}

			}
			else if (i1 < nums1.size()) {
				stupid_vector.push_back(nums1[i1]);
				i1++;
			}
			else {
				stupid_vector.push_back(nums2[i2]);
				i2++;
			}

		}

		if (all_size % 2 == 0) {
			d_return = (stupid_vector[index] + stupid_vector[index - 1]) / 2.0;
		}
		else {
			d_return = stupid_vector[index];
		}

		return d_return;

	}

	// It's ok, but still O((N + M) / 2) ...
	double findMedianSortedArrays_not_so_stupid(std::vector<int>& nums1, std::vector<int>& nums2) {

		size_t n = nums2.size(), m = nums1.size();
		size_t all_size = n + m;
		size_t index = all_size / 2;

		int i = 0, j = 0;
		int prev = 0, curr = 0;

		for (int count = 0; count <= index; count++) {
			prev = curr;

			if (i < m && (j >= n || nums1[i] <= nums2[j])) {
				curr = nums1[i++];
			}
			else {
				curr = nums2[j++];
			}
		}

		if (all_size % 2 == 0) {
			return (prev + curr) / 2.0;
		}
		else {
			return curr;
		}

	}

	std::pair<int, int> get_min_max(const std::vector<int>& nums,const int& index) {
		std::pair<int, int> p_return = { INT32_MAX, INT32_MIN };
		if (index < nums.size()) {
			p_return.first = nums[index];
		}
		if (index > 0) {
			p_return.second = nums[index - 1];
		}
		return p_return;
	}

	// This is ideal solution O(log(N + M))
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

		if (nums1.size() > nums2.size()) std::swap(nums1, nums2);

		int t_size = nums1.size() + nums2.size();
		int half = t_size / 2;

		int left = 0, right = nums1.size();
		while (left <= right) {

			int index_1 = (left + right) / 2;
			int index_2 = half - index_1;

			std::pair<int, int> p_1st = get_min_max(nums1, index_1);
			std::pair<int, int> p_2nd = get_min_max(nums2, index_2);

			if (p_1st.first >= p_2nd.second && p_1st.second <= p_2nd.first) {
				if (t_size % 2 == 0) {
					return (std::max(p_1st.second, p_2nd.second) + std::min(p_1st.first, p_2nd.first)) / 2.0;
				}
				return std::min(p_1st.first, p_2nd.first);
			}

			if (p_1st.second > p_2nd.first) {
				right = index_1 - 1;
			}
			else {
				left = index_1 + 1;
			}

		}
		return 0.0;
	}

};



int main() {

	Solution sol;

	// Example 1:
	std::vector<int> nums1_1 = { 1,3 };
	std::vector<int> nums2_1 = { 2 };
	double ans_1 = sol.findMedianSortedArrays(nums1_1, nums2_1);

	// Example 2:
	std::vector<int> nums1_2 = { 1,2 };
	std::vector<int> nums2_2 = { 3,4 };
	double ans_2 = sol.findMedianSortedArrays(nums1_2, nums2_2);

	// Example 3:
	std::vector<int> nums1_3 = { 1,10,15,16 };
	std::vector<int> nums2_3 = { 1,2,3,4 };
	double ans_3 = sol.findMedianSortedArrays(nums1_3, nums2_3);

	// Example 4:
	std::vector<int> nums1_4 = {  };
	std::vector<int> nums2_4 = { 1 };
	double ans_4 = sol.findMedianSortedArrays(nums1_4, nums2_4);

	// Example 5:
	std::vector<int> nums1_5 = { -10,-9,-8 };
	std::vector<int> nums2_5 = { 1,2 };
	double ans_5 = sol.findMedianSortedArrays(nums1_5, nums2_5);

	// Example 6:
	std::vector<int> nums1_6 = { 1,2,3,4,5 };
	std::vector<int> nums2_6 = { 6,7,8,9,10,11,12,13,14,15,16,17 };
	double ans_6 = sol.findMedianSortedArrays(nums1_6, nums2_6);

	// Out:
	std::cout << "\nExample 1: '" << ans_1 << "' must be '2'\n";
	std::cout << "Example 2: '" << ans_2 << "' must be '2.5'\n";
	std::cout << "Example 3: '" << ans_3 << "' must be '3.5'\n";
	std::cout << "Example 4: '" << ans_4 << "' must be '1'\n";
	std::cout << "Example 5: '" << ans_5 << "' must be '-8'\n";
	std::cout << "Example 6: '" << ans_6 << "' must be '9'\n";
}