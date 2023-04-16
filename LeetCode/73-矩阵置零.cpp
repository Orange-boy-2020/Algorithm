#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int Rows = matrix.size();
		int Cols = matrix[0].size();
		vector<vector<int>>memo(Rows, vector<int>(Cols, 0));
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				if (matrix[i][j] == 0 && memo[i][j] == 0) {
					for (int x = j; x < Cols; x++) {
						if (matrix[i][x] != 0) {
							matrix[i][x] = 0;
							memo[i][x] = 1;
						}
					}
					for (int x = j; x >= 0; x--) {
						if (matrix[i][x] != 0) {
							matrix[i][x] = 0;
							memo[i][x] = 1;
						}
					}
					for (int x = i; x < Rows ; x++) {
						if (matrix[x][j] != 0) {
							matrix[x][j] = 0;
							memo[x][j] = 1;
						}
						
					}
					for (int x = i; x >= 0; x--) {
						if (matrix[x][j] != 0) {
							matrix[x][j] = 0;
							memo[x][j] = 1;
						}
		
					}

				}
			}
		}
	}
};

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>>matrix;
	for (int i = 0; i < m; i++) {
		vector <int> data;
		int tmp;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			data.push_back(tmp);
			if (cin.get() == '\n')
				break;
		}
		matrix.push_back(data);
	}
	Solution sol;
	sol.setZeroes(matrix);

	for (auto i : matrix) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

