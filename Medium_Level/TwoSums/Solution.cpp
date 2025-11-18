#include <iostream>



// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


// Fabric func to quick create of list
ListNode* get_list_node(std::initializer_list<int> values) {
	ListNode* ret_node = new ListNode();

	if (values.size() == 0) {
		return ret_node;
	}

	auto it = values.begin();
	ret_node->val = *it;
	ret_node->next = nullptr;

	ListNode* current = ret_node;
	for (++it; it != values.end(); ++it) {
		current->next = new ListNode(*it);
		current = current->next;
	}

	return ret_node;
}

// Helper func to close list
void close_list_node(ListNode* head) {
	while (head) {
		ListNode* _nptr = head->next;
		delete head;
		head = _nptr;
	}
}

// Simple output
std::ostream& operator << (std::ostream& out, const ListNode* node) {
	if (node) {
		const ListNode* ptr = node;
		while (ptr) {
			out << ptr->val;
			ptr = ptr->next;
			if (ptr) out << " ";
		}
		return out;
	}
}



class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ans = new ListNode();

		ListNode* ln_next = ans;
		int to_next = 0;
		while (l1 != nullptr || l2 != nullptr) {
			int sum = 0;
			if (l1 != nullptr) {
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) {
				sum += l2->val;
				l2 = l2->next;
			}

			ln_next->val = (sum + to_next) % 10;
			to_next = (sum + to_next) / 10;

			if (l1 || l2) {
				ln_next->next = new ListNode();
				ln_next = ln_next->next;
			}
			else if (to_next > 0) {
				ln_next->next = new ListNode();
				ln_next = ln_next->next;
				ln_next->val = to_next;
			}
		}

		return ans;
	}
};



int main() {
	Solution sol;

	// Example 1:
	ListNode* l1_1 = get_list_node({ 2, 4, 3 });
	ListNode* l2_1 = get_list_node({5, 6, 4});
	ListNode* l_ans1 = sol.addTwoNumbers(l1_1, l2_1);

	// Example 2:
	ListNode* l1_2 = get_list_node({ 0 });
	ListNode* l2_2 = get_list_node({ 0 });
	ListNode* l_ans2 = sol.addTwoNumbers(l1_2, l2_2);

	// Example 3:
	ListNode* l1_3 = get_list_node({ 9, 9, 9, 9, 9, 9, 9 });
	ListNode* l2_3 = get_list_node({ 9, 9, 9, 9 });
	ListNode* l_ans3 = sol.addTwoNumbers(l1_3, l2_3);

	// Output:
	std::cout << "Ex1: '" << l_ans1 << "'\n";
	std::cout << "Ex2: '" << l_ans2 << "'\n";
	std::cout << "Ex3: '" << l_ans3 << "'\n";

	close_list_node(l1_1);
	close_list_node(l2_1);
	close_list_node(l_ans1);

	close_list_node(l1_2);
	close_list_node(l2_2);
	close_list_node(l_ans2);

	close_list_node(l1_3);
	close_list_node(l2_3);
	close_list_node(l_ans3);
}