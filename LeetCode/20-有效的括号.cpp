#include <iostream>
#include <string>
#include <stack>
using namespace std;
// "([)]"
// "()[]{}"
class Solution {
public:
	bool isValid(string s) {
		if (s.size() % 2 != 0)
			return false;
		stack<char>st;
		for (auto i : s) {
			if (i == '(')
				st.push(')');
			else if (i == '{')
				st.push('}');
			else if (i == '[')
				st.push(']');
			else if (st.empty() || st.top() != i)
				return false;
			else
				st.pop();
		}
		return st.empty();
	}
};

int main() {
	string s;
	getline(cin, s);
	Solution sol;
	auto res = sol.isValid(s);
	cout << res << endl;

	system("pause");
	return 0;
}