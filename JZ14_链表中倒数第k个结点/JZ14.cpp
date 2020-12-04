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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k <= 0) return nullptr;

		ListNode* p = pListHead;
		ListNode* temp = pListHead;
		int listConut = 0;                   //计算链表的长度
		while (p != NULL)
		{
			p = p->next;
			listConut++;
		}

		if (listConut < k) return nullptr;   //必须加，随意给的k可能比链表长度大

		for (size_t i = 0; i < listConut - k; i++)
			temp = temp->next;

		return temp;
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

	cout << res.FindKthToTail(head->next, 1)->val << endl;

	system("pause");
	return 0;
}