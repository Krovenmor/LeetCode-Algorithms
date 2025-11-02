#include <iostream>
#include <vector>
#include <unordered_map>

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

    static std::vector<int> twoSum(std::vector<int>& nums, int target) {

        // First int to store substraction ( target - nums[i] ), second to store index i
        std::unordered_map<int, int> hash_map;

        for (int i = 0; i != nums.size(); ++i) {
            if (hash_map.contains(nums[i])) {
                return { hash_map[nums[i]], i };
            }
            int value = target - nums[i];
            hash_map[value] = i;
        }

        return { -1,-1 };

    }

};

int main() {

    std::vector test_1{ 2,7,11,15 };
    std::vector test_2{ 3,2,4 };
    std::vector test_3{ 3,3 };

    std::cout << "\nTest1 vector: " << test_1 << "Result: " << Solution::twoSum(test_1, 9);
    std::cout << "\nTest2 vector: " << test_2 << "Result: " << Solution::twoSum(test_2, 6);
    std::cout << "\nTest3 vector: " << test_3 << "Result: " << Solution::twoSum(test_3, 6);

}