#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jumpFloor(int number) {
		////ตÝน้
		//if (number == 1)return 1;
		//if (number == 2)return 2;
		//return jumpFloor(number - 1) + jumpFloor(number - 2);

		int jump[2] = { 0, 1 };
		int count = 1;
		while (count <= number)
		{
			int temp = jump[1];
			jump[1] = jump[0] + jump[1];
			jump[0] = temp;
			count++;
		}
		return jump[1];
	}
};

int main()
{
	Solution res;

	cout << res.jumpFloor(2) << endl;

	system("pause");
	return 0;
}