#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
		if (head == NULL) return result;
		//链表转置
		ListNode* new_head = head;
		ListNode* old_head = head->next;
		head->next = NULL;
		while (old_head != NULL)
		{
			ListNode* temp = old_head->next;
			old_head->next = new_head;
			new_head = old_head;
			old_head = temp;
		}
		//将新链表赋值给result
		while (new_head != NULL)
		{
			result.push_back(new_head->val);
			new_head = new_head->next;
		}
		return result;
	}
};

int main()
{
	ListNode node1(1); ListNode* p_node1 = &node1;
	ListNode node2(2); ListNode* p_node2 = &node2;
	ListNode node3(3); ListNode* p_node3 = &node3;
	ListNode node4(4); ListNode* p_node4 = &node4;
	ListNode node5(5); ListNode* p_node5 = &node5;
	p_node1->next = p_node2;
	p_node2->next = p_node3;
	p_node3->next = p_node4;
	p_node4->next = p_node5;
	p_node5->next = NULL;
	Solution solve;

	vector<int> result = solve.printListFromTailToHead(p_node1);

	return 0;
}