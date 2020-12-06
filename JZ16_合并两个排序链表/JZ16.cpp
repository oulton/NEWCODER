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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* p1 = pHead1; //定义p1，p2，不改变pHead
		ListNode* p2 = pHead2;
		ListNode* head, *tail;
		head = new ListNode(0);
		tail = head;
		while (p1 != NULL && p2 != NULL)
		{
			if (p1->val <= p2->val)
			{
				tail->next = p1;
				p1 = p1->next;
			}
			else
			{
				tail->next = p2;
				p2 = p2->next;
			}
			tail = tail->next;
		}
		if (p1 == NULL)       //若p1先空，则把p2直接拼在tail后面即可
			tail->next = p2;
		if (p2 == NULL)
			tail->next = p1;
		return head->next;
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
	vector<int> inArray1 = { 1, 3, 5, 8 };
	vector<int> inArray2 = { 2, 4, 6 };
	
	ListNode* head1 = NULL;
	head1 = new ListNode(0);
	createNode(head1, inArray1);

	ListNode* head2 = NULL;
	head2 = new ListNode(0);
	createNode(head2, inArray2);

	ListNode* reNode = res.Merge(head1->next, head2->next);
	while (reNode != NULL)
	{
		cout << reNode->val << endl;
		reNode = reNode->next;
	}

	system("pause");
	return 0;
}