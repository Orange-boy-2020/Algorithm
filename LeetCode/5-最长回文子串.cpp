#include <iostream>
#include <string>
#include <vector>
using namespace std;

// dp[i][j]表示 下标i 到 j的子串 是否为 回文串
// 子串长度为1时，必然是，则dp[i][i] = true 边界条件
// 子串长度为2时，当s[i]=s[j]时 dp[i][j] = true 边界条件
// 子串长度大于2时，dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
// 使用一个值记录长度 ，一个值记录起始位置
// substr() 用法：
// 假设：string s = "0123456789";
// string sub1 = s.substr(5);  只有一个数字5表示从下标为5开始一直到结尾：sub1 = "56789"
// string sub2 = s.substr(5, 3);  从下标为5开始截取长度为3位：sub2 = "567"
class Solutinon {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)
			return s;
		int n = s.size();

		int maxLen = 1;
		int begin = 0;
		vector<vector<int>>dp(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			dp[i][i] = true;
		}
		for (int L = 2; L <= n; ++L) {
			for (int i = 0; i < n; ++i) {
				int j = L + i - 1;
				if (j >= n) {
					break;
				}
				if (s[i] != s[j]) {
					dp[i][j] = false;
				}
				else {
					if (j - i < 3) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				}
				if (dp[i][j] && j - i + 1 > maxLen) {
					maxLen = j - i + 1;
					begin = i;
				}
			}
		}
		return s.substr(begin, maxLen);
	}
};
int main() {
	string s;
	getline(cin, s);
	Solutinon sol;
	auto res = sol.longestPalindrome(s);
	cout << res << endl;
	return 0;
}