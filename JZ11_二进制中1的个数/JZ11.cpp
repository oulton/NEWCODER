#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		int flag = 0x00000001;
		while (flag != 0)
		{
			if (flag & n)
				count++;
			flag <<= 1;
		}
		return count;
	}
};

int main()
{
	Solution res;

	cout << res.NumberOf1(104534637457) << endl;

	system("pause");
	return 0;
}