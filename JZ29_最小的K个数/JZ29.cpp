#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> ref = {};
		if ( k <= 0 || k > input.size()) return ref;
		if ( k == input.size() ) return input;
		sort(input.begin(), input.end());
		ref.assign(input.begin(), input.begin() + k);
		return ref;
	}
};


int main()
{
	Solution res;
	vector<int> inArray = { 5, 4, 1, 3, 7, 6, 8 };

	vector<int> outArray = res.GetLeastNumbers_Solution(inArray, 4);
	for (size_t i = 0; i < outArray.size(); i++)
		cout << outArray[i] << endl;

	system("pause");
	return 0;
}