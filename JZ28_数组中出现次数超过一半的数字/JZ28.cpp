#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0) return 0;
		//if (numbers.size() == 1) return numbers[0];

		sort(numbers.begin(), numbers.end());        //对numbers排序
		int mid_data = numbers[numbers.size() / 2];  //取排序后的中间的元素
		int counter = 0;
		for (size_t i = 0; i < numbers.size(); i++)
			if (mid_data == numbers[i])
				counter++;
		if (counter > numbers.size() / 2) return mid_data;
		else return 0;

	}
};


int main()
{
	Solution res;
	vector<int> inArray = { 5, 4, 2, 3, 2, 2, 2};

	cout << res.MoreThanHalfNum_Solution(inArray) << endl;

	system("pause");
	return 0;
}