#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//4
//2
//3 4
//6 5 7
//4 1 8 3
class Solution {
public:
	int minimumTotal(vector<vector<int> >& triangle) {
		if (triangle.size() == 0 || triangle[0].size() == 0)
			return 0;
		int Rows = triangle.size();
		vector<vector<int> >dp(Rows,vector<int>(Rows));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < Rows; i++) {
			dp[i][0] = dp[i - 1][0] + triangle[i][0];
			dp[i][triangle[i].size() - 1] = triangle[i][triangle[i].size() - 1] + dp[i-1][triangle[i-1].size()-1];
		}
		
		for (int i = 1; i < Rows; i++) {
			for (int j = 1; j < triangle[i].size()-1; j++) {
				dp[i][j] = min(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
			}
		}
		return *min_element(dp[Rows - 1].begin(), dp[Rows - 1].end());
	}
};

int main(int argc, char* argv[]) {
	int N;
	cin >> N;
	vector<vector<int> >triangle;
	while (N--) {
		int tmp;
		vector<int>data;
		while (cin >> tmp) {
			data.push_back(tmp);
			if (cin.get() == '\n')
				break;
		}
		triangle.push_back(data);
	}
	Solution sol;
	int res = sol.minimumTotal(triangle);
	cout << res << endl;

	/*for (auto i : triangle) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}*/
	return 0;
}

