#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int Fibonacci(int n) {
		
		if (n == 0)return 0;
		if (n == 1)return 1;
		////µÝ¹é
		//return Fibonacci(n - 1) + Fibonacci(n - 2);

		//Ñ­»·
		int count = 2;
		int a = 0, b = 1;
		while (count <= n)
		{
			int temp = b;
			b = a + b;
			a = temp;
			count++;
		}
		return b;
	}
};

int main()
{
	Solution res;

	cout << res.Fibonacci(6) << endl;

	system("pause");
	return 0;
}