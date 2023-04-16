#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	
	int minPathSum(vector<vector<int> >& grid) {
		int Rows = grid.size();
		int Cols = grid[0].size();
		vector<vector<int> >dp(Rows, vector<int>(Cols));
		dp[0][0] = grid[0][0];
		//grid[0][0] = 0;
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				if (i != 0 || j != 0) {
					if (i == 0) {
						dp[i][j] = dp[i][j - 1] + grid[i][j];
						continue;
					}
					if (j == 0) {
						dp[i][j] = dp[i - 1][j] + grid[i][j];
						continue;
					}
					dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
				}
			}
		}
		return dp[Rows - 1][Cols - 1];
	}
};

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int> >input;
	for (int i = 0; i < m; ++i) {
		vector<int>data;
		int tmp;
		for (int j = 0; j < n; ++j) {
			cin >> tmp;
			data.push_back(tmp);
			if (cin.get() == '\n')
				break;
		}
		input.push_back(data);
	}
	Solution sol;
				
	int res = sol.minPathSum(input);
	cout << res << endl;
	return 0;
}
