#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> odd = {}, even = {};
		for (size_t i = 0; i < array.size(); i++)
		{
			if (array[i] % 2)
				odd.push_back(array[i]);
			else
				even.push_back(array[i]);
		}
		array.clear();

		//ray.insert(array.begin(), odd.begin(), odd.end());
		//ray.insert(array.begin() + odd.size(), even.begin(), even.end());

		for (size_t j = 0; j < odd.size(); j++)
			array.push_back(odd[j]);
		for (size_t j = 0; j < even.size(); j++)
			array.push_back(even[j]);
	}
};

int main()
{
	Solution res;
	vector<int> inArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	res.reOrderArray(inArray);

	for (size_t i = 0; i < inArray.size(); i++)
		cout << inArray[i] << endl;

	system("pause");
	return 0;
}