#include <iostream>
#include <vector>

using namespace std;

bool Find(int target, vector<vector<int> > array) {
	int row = 0;
	int col = array[0].size();
	while (row < array.size())
	{
		if (target > array[row][col - 1])
			row++;
		else if (target == array[row][col - 1])
			return true;
		else
			col--;
	}
	cout << row << "   " << col << "  " << endl;
	return false;
}

int main()
{
	int target = 13;
	vector<vector<int>> array = {	{ 1, 2, 8, 9, 14 }, 
					{ 2, 4, 9, 12, 15 }, 
					{ 4, 6, 10, 13, 21 }, 
					{ 6, 8, 11, 15, 25 } };
	cout << Find(target, array) << endl;
	system("pause");
	return 0;
}
