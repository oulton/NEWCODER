#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> reMatrix = {};
		if (matrix.empty()) return reMatrix;

		int upRow = 0, downRow = matrix.size() - 1;
		int leftCol = 0, rightCol = matrix[0].size() - 1;

		while (upRow <= downRow && leftCol <= rightCol) 
		{
			for (int j = leftCol; j <= rightCol; j++) 
				reMatrix.push_back(matrix[upRow][j]);

			for (int i = upRow + 1; i <= downRow; i++) 
				reMatrix.push_back(matrix[i][rightCol]);

			if (upRow != downRow)
				for (int j = rightCol - 1; j >= leftCol; j--) 
					reMatrix.push_back(matrix[downRow][j]);

			if (leftCol != rightCol)
				for (int i = downRow - 1; i > upRow; i--) 
					reMatrix.push_back(matrix[i][leftCol]);
			upRow++;
			downRow--;
			leftCol++;
			rightCol--;
		}
		return reMatrix;
	}
};

int main()
{
	Solution res;
	vector<vector<int>> inArray = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 } };

	vector<int> outMatrix = res.printMatrix(inArray);

	for (size_t i = 0; i < outMatrix.size(); i++)
		cout << outMatrix[i] << endl;

	system("pause");
	return 0;
}