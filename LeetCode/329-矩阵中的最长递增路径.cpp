#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	int Rows, Cols;
	int longestIncreasingPath(vector<vector<int> >& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		Rows = matrix.size();
		Cols = matrix[0].size();
		auto memo = vector<vector<int> >(Rows, vector<int>(Cols));
		int ans = 0;
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				ans = max(ans, dfs(matrix, i, j, memo));
			}
		}
		return ans;
	}
	int dfs(vector<vector<int> >& matrix, int row, int col, vector<vector<int> >& memo) {
		if (memo[row][col] != 0) {
			return memo[row][col];
		}
		++memo[row][col];
		for (int i = 0; i < 4; i++) {
			int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
			if (newRow >= 0 && newRow < Rows && newCol>=0 && newCol<Cols && matrix[newRow][newCol]>matrix[row][col]) {
				memo[row][col] = max(memo[row][col], dfs(matrix, newRow, newCol, memo) + 1);
			}
		}
		return memo[row][col];
	}
};
int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int> >matrix;
	for (int i = 0; i < m; i++) {
		int tmp;
		vector<int>row;
		for (int j = 0; i < n; j++) {
			cin >> tmp;
			row.push_back(tmp);
			if(cin.get() == '\n')
				break;
		}
		matrix.push_back(row);
	}
	
	Solution sol;
	int res = sol.longestIncreasingPath(matrix);
	cout << res << endl;
	
	system("pause");
	return 0;
}

