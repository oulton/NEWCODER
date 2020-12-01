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

		//��stack1��pop��stack2�У���ʵ���˵���
		//���н���˳��  1->2->3->4->5
		//stack1 = [1,2,3,4,5] ---> stack2 = [5,4,3,2,1]
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}

		//pop��stack2��ջ������   popһ�κ�, stack2 = [5,4,3,2], ��ʵ���˶��е�FIFO
		int res = stack2.top();
		stack2.pop();

		//pop��һ���󣬻���Ҫ��ԭ������ѹ��stack1�У�Ϊ����stack1�м�������������׼��
		//��stack2��ѹ��stack1��   stack2 = [5,4,3,2] --->  stack1 = [2,3,4,5]���Լ�������Ԫ�ؽ���
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
	testSatck.push(6); //��ʱ����Ԫ��Ӧ��Ϊ2->3->4->5->6

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