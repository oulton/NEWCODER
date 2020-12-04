#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode* pre = NULL;
		ListNode* cur = pHead;
		ListNode* nex = NULL;
		while (cur != NULL)
		{
			nex = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nex;
		}
		return pre;
	}
};

void createNode(ListNode* pHead, vector<int> inputArray)
{
	ListNode* p = pHead;
	for (size_t i = 0; i < inputArray.size(); i++)
	{
		ListNode* pNewNode = NULL;
		pNewNode = new ListNode(inputArray[i]);
		p->next = pNewNode;
		p = pNewNode;
	}
}

int main()
{
	Solution res;
	vector<int> inArray = { 1, 2, 3, 4, 5 };
	
	ListNode* head = NULL;
	head = new ListNode(0);
	createNode(head, inArray);

	ListNode* reNode = res.ReverseList(head->next);
	while (reNode != NULL)
	{
		cout << reNode->val << endl;
		reNode = reNode->next;
	}
	

	system("pause");
	return 0;
}