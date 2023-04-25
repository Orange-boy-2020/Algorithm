#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
#if 0
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		node->val = INT_MIN;
		node->next = list1;
		list1 = node;


		ListNode* cur1 = list1;
		ListNode* cur2 = list2;
		while (cur1 || cur2) {
			if (cur1 && cur2) {
				if (cur1->val <= cur2->val) {
					while (cur1->next && cur1->next->val < cur2->val) {
						cur1 = cur1->next;
					}
					ListNode* tmp1 = cur1->next;
					ListNode* tmp2 = cur2->next;
					cur1->next = cur2;
					cur2->next = tmp1;
					cur2 = tmp2;
					cur1 = cur1->next;
				}
				else {

					ListNode* tmp2 = cur2->next;
					cur2->next = cur1;
					cur1 = cur2;
					cur2 = tmp2;
				}
			}
			else if (cur1) {
				return list1->next;
			}
			else {
				return list1->next;
			}
		}

		return list1->next;
}

#else
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == nullptr)
			return list2;
		if (list2 == nullptr)
			return list1;

		if (list1->val < list2->val) {
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}else{
			list2->next = mergeTwoLists(list1, list2->next);
			return list2;
		}

	}


#endif
	
};


int main() {

	vector<int>data1, data2;
	int tmp;
	while (cin >> tmp) {
		data1.push_back(tmp);
		if (cin.get() == '\n')
			break;
	}

	ListNode* head, * node, * cur;
	head = node = (ListNode*)malloc(sizeof(ListNode));
	node->val = -1;
	node->next = nullptr;
	for (auto i : data1) {
		cur = (ListNode*)malloc(sizeof(ListNode));
		cur->val = i;
		cur->next = nullptr;
		node->next = cur;
		node = cur;
	}

	while (cin >> tmp) {
		data2.push_back(tmp);
		if (cin.get() == '\n')
			break;
	}
	ListNode* head1, * node1, * cur1;
	head1 = node1 = (ListNode*)malloc(sizeof(ListNode));
	node1->val = -1;
	node1->next = nullptr;
	for (auto i : data2) {
		cur1 = (ListNode*)malloc(sizeof(ListNode));
		cur1->val = i;
		cur1->next = nullptr;
		node1->next = cur1;
		node1 = cur1;
	}
	Solution sol;
	auto res = sol.mergeTwoLists(head->next, head1->next);


	while (res)
	{
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;


	system("pause");
	return 0;
}