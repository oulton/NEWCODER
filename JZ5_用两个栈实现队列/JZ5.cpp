#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack1.empty())
			return 0;

		//从stack1中pop到stack2中，就实现了倒序
		//队列进入顺序  1->2->3->4->5
		//stack1 = [1,2,3,4,5] ---> stack2 = [5,4,3,2,1]
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}

		//pop出stack2的栈顶即可   pop一次后, stack2 = [5,4,3,2], 即实现了队列的FIFO
		int res = stack2.top();
		stack2.pop();

		//pop出一个后，还需要将原来的再压入stack1中，为后续stack1中继续加入数据做准备
		//将stack2再压入stack1中   stack2 = [5,4,3,2] --->  stack1 = [2,3,4,5]可以继续队列元素进入
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}

		return res;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	vector<int> inArray = { 1, 2, 3, 4, 5 };
	Solution testSatck;
	for (size_t i = 0; i < inArray.size(); i++)
	{
		testSatck.push(inArray[i]);
	}

	testSatck.pop();
	testSatck.push(6); //此时队列元素应该为2->3->4->5->6

	for (size_t j = 0; j < 10; j++)
	{
		int res = testSatck.pop();
		if (res)
			cout << res << endl;
		else
			cout << "The Stack is empty!" << endl;	
	}

	system("pause");
	return 0;
}