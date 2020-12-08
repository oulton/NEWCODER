#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	void push(int value) {
		stk1.push(value);

		if (stk2.empty() || stk2.top() >= value)
			stk2.push(value);
	}
	void pop() {
		if (stk1.top() == stk2.top())
		{
			stk1.pop();
			stk2.pop();
		}
		else
			stk1.pop();
		
	}
	int top() {
		return stk1.top();
	}
	int min() {
		return stk2.top();
	}

private:
	stack<int> stk1, stk2;
};

int main()
{
	Solution res;
	vector<int> inArray = {13,21,7,5,7,11,4,45};
	for (size_t i = 0; i < inArray.size(); i++)
		res.push(inArray[i]);

	cout << res.min() << endl;
	res.pop();
	res.pop();
	cout << res.min() << endl;

	system("pause");
	return 0;
}