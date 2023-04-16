#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		int n = s.size();
		int m = p.size();
		s.insert(s.begin(), ' ');
		p.insert(p.begin(), ' ');

		vector<vector<bool>>f(n + 1, vector<bool>(m + 1, false));
		f[0][0] = true;
		for (int i = 0; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (p[j] == '*') {
					f[i][j] = f[i][j - 1] || (i - 1 >= 0 && f[i - 1][j]);
				}
				else {
					f[i][j] = (i - 1 >= 0) && f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '?');
				}
			}
		}
		return f[n][m];
	}
};
int main() {
	string s, p;
	getline(cin, s);
	getline(cin, p);
	Solution sol;
	bool res = sol.isMatch(s, p);
	cout << res << endl;

	system("pause");
	return 0;
}

