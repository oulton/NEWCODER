#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rectCover(int number) {
		
		////ตÝน้
		//if (number == 0) return 0;
		//if (number == 1) return 1;
		//if (number == 2) return 2;
		////return rectCover(number - 1) + rectCover(number - 2);

		if (number == 0)
			return 0;
		int rect[2] = { 0, 1 };
		int count = 1;
		while (count <= number)
		{
			int temp = rect[1];
			rect[1] = rect[1] + rect[0];
			rect[0] = temp;
			count++;
		}
		return rect[1];
	}
};

int main()
{
	Solution res;

	cout << res.rectCover(3) << endl;

	system("pause");
	return 0;
}