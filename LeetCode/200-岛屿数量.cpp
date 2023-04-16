#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	const int dx[4] = { 1,0,-1,0 };
	const int dy[4] = { 0,1,0,-1 };
	int X = 0, Y = 0;
	int numIslands(vector<vector<char>>& grid) {
		int res = 0;
		if (grid.size() == 0)
			return 0;
		Y = grid.size();
		X = grid[0].size();
		vector<vector<int>>memo(Y, vector<int>(X, 0));
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				if (grid[i][j] == '1' && memo[i][j] == 0) {
					memo[i][j] = 1;
					dfs(grid, memo, j, i);
					res++;
				}
			}
		}

		return res;
	}
	void dfs(vector<vector<char>>& grid, vector<vector<int>>&memo, int xx, int yy) {
		

		for (int i = 0; i < 4; i++) {
			int x = xx + dx[i];
			int y = yy + dy[i];
			if (x >= 0 && x < X && y >= 0 && y < Y && grid[y][x] == '1' && memo[y][x] == 0) {
				memo[y][x] = 1;
				dfs(grid, memo, x, y);
			}
		}
		return;
	}
};
int main() {
	vector<vector<char>>grid;
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		vector<char>data;
		char tmp;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			data.push_back(tmp);
			if (cin.get() == '\n')
				break;
		}
		grid.push_back(data);
	}

	Solution sol;
	int res = sol.numIslands(grid);
	cout << res << endl;

	system("pause");
	return 0;
}

