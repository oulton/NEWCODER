#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty()) return false;
		stack<int> stk;
		int k = 0;
		for (size_t i = 0; i < pushV.size(); i++)
		{
			stk.push(pushV[i]);
			while (k < popV.size() && stk.top() == popV[k])
			{
				stk.pop();
				k++;
			}
		}
		return stk.empty();
	}
};

int main()
{
	Solution res;
	vector<int> pushV = { 1, 2, 3, 4, 5 };
	vector<int> popV =  { 4, 3, 5, 2, 1 };

	cout << res.IsPopOrder(pushV, popV) << endl;

	system("pause");
	return 0;
}