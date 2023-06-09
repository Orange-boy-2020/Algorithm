#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Soluton {
public:
	const int dx[4] = { 1,-1,0,0 };
	const int dy[4] = { 0,0,1, - 1 };

	void solve(vector<vector<char>>& board) {
		if (board.size() <= 2 || board[0].size() <= 2)
			return;
		int n = board.size();
		int m = board[0].size();
		queue<pair<int, int>> que;
		for (int i = 0; i < n; i++) {
			if (board[i][0] == 'O') {
				que.emplace(i, 0);
				board[i][0] = 'A';
			}
			if (board[i][m - 1] == 'O') {
                que.emplace(i, m - 1);
                board[i][m - 1] = 'A';
            }
		}
		for (int i = 1; i < m - 1; i++) {
			if (board[0][i] == 'O') {
				que.emplace(0, i);
				board[0][i] = 'A';
			}
			if (board[n - 1][i] == 'O') {
				que.emplace(n - 1, i);
				board[n - 1][i] = 'A';
			}
		}
		while (!que.empty()) {
			int x = que.front().first, y = que.front().second;
			que.pop();
			for (int i = 0; i < 4; i++) {
				int mx = x + dx[i], my = y + dy[i];
				if (mx < 0 || my < 0 || mx >= n || my >= m || board[mx][my] != 'O') {
					continue;
				}
				que.emplace(mx, my);
				board[mx][my] = 'A';
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'A') {
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
	}
};
int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<char>> board;
	for (int i = 0; i < m; i++) {
		vector<char>data;
		char tmp;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			data.push_back(tmp);
			if (cin.get() == '\n')
				break;
		}
		board.push_back(data);
	}
	Soluton sol;
	sol.solve(board);

	for (auto i : board) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}

