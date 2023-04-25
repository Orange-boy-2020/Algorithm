#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	
	bool isMatch(string s, string p) {
		int n = s.size();
		int m = p.size();
		s.insert(s.begin(), ' ');
		p.insert(p.begin(), ' ');
	
		vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
		f[0][0] = true;

		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				// 如果下一个字符是 '*'，则代表当前字符不能被单独使用，跳过
				if (j + 1 <= m && p[j + 1] == '*')
					continue;
				if (i - 1 >= 0 && p[j] != '*') {
					// 对应了 p[j] 为普通字符和 '.' 的两种情况
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
				}
				else if (p[j] == '*') {
					// 对应了 p[j] 为 '*' 的情况
					f[i][j] = (j - 2 >= 0 && f[i][j - 2]) || (i - 1 >= 0 && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
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
	return 0;
}