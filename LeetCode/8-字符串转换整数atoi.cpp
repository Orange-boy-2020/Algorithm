#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int myAtoi(string s) {
		int res = 0, sign = 1, i = 0, n = s.length();
		while (s[i++] == ' ');
		i--;
		if (i < n && (s[i] == '+' || s[i] == '-')) {
			sign = s[i] == '-' ? -1 : 1;
			i++;
		}
		for (; i < n; ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				if (res > INT_MAX / 10 || res == INT_MAX / 10 && (s[i] - '0' > 7)) {
					return (sign + 1) ? INT_MAX : INT_MIN;
				}
				res = res * 10 + (s[i] - '0');
			}
			else {
				break;
			}
		}
		return res * sign;
	}
};
int main() {
	string s;
	getline(cin, s);
	Solution sol;
	int res = sol.myAtoi(s);

	cout << res << endl;
	
	system("pause");
	return 0;
}

