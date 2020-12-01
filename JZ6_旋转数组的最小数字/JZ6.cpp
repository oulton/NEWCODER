#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		////暴力解法
		//for (int i = 0; i<rotateArray.size() - 1; i++)
		//{
		//	if (rotateArray[i] == 0)
		//		return 0;
		//	else
		//	{
		//		if (rotateArray[i]>rotateArray[i + 1])
		//			return rotateArray[i + 1];
		//	}
		//}

		//二分解法
		int left = 0;
		int right = rotateArray.size() - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (rotateArray[mid] >= rotateArray[right])
				left = mid + 1;
			else
				right = mid;
		}
		return rotateArray[right];
	}
};

int main()
{
	vector<int> rotateArray = { 3, 4, 5, 1, 2 };   //{ 8, 4, 5, 6, 7 };

	Solution minNumArray;
	cout << minNumArray.minNumberInRotateArray(rotateArray) << endl;

	system("pause");
	return 0;
}