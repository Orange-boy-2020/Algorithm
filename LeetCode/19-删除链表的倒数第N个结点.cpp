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
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		ListNode* cur = head->next;
		int count = 0;
		while (cur) {
			++count;
			cur = cur->next;
		}
		
		int offset = count - n;
		cur = head->next;
		ListNode* pre = head;
		for (int i = 0; i < offset; i++) {
			cur = cur->next;
			pre = pre->next;
		}

		pre->next = cur->next;

	
		return head->next;
	}
};

int main() {
	vector<int>data;
	int tmp;
	while (cin >> tmp) {
		data.push_back(tmp);
		if (cin.get() == '\n')
			break;
	}
	int n;
	cin >> n;

	ListNode* head, * next, * cur;
	head = next = (ListNode*)malloc(sizeof(ListNode));
	next->val = -1;
	next->next = nullptr;
	for (auto i : data) {
		cur = (ListNode*)malloc(sizeof(ListNode));
		cur->val = i;
		cur->next = nullptr;
		next->next = cur;
		next = cur;
	}


	Solution sol;
	auto res = sol.removeNthFromEnd(head, n);

	while (res != nullptr) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
	system("pause");
	return 0;
}
