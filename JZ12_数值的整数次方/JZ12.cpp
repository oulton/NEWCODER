#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		if (base == 0) return 0;
		if (exponent == 0) return 1;
		return pow(base, exponent);
	}
};

int main()
{
	Solution res;

	cout << res.Power(13, 2) << endl;

	system("pause");
	return 0;
}