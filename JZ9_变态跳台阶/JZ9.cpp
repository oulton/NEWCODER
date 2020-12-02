#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jumpFloorII(int number) {
		
		if (number == 1) return 1;
		if (number == 2) return 2;
		////ตÝน้
		//return jumpFloorII(number - 1) + 2 * jumpFloorII(number - 2);


		int jump[2] = { 1, 2 };
		int count = 3;
		while (count <= number)
		{
			int temp = jump[1];
			jump[1] = jump[1] + 2 * jump[0];
			jump[0] = temp;
			count++;
		}
		return jump[1];
	}
};

int main()
{
	Solution res;

	cout << res.jumpFloorII(4) << endl;

	system("pause");
	return 0;
}