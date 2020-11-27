#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> ref;
	ListNode* p = head;
	while (p != NULL)
	{
		ref.insert(ref.begin(), p->val);
		p = p->next;
	}
	return ref;
}

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
	vector<int> InputArray = { 67, 0, 24, 58, 33, 25 };
	ListNode* head = NULL;
	head = new ListNode(0);
	createNode(head, InputArray);

	vector<int> outRef = printListFromTailToHead(head->next);
	
	system("pause");
	return 0;
}