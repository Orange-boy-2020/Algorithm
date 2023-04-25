#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	void backTrack(vector<string>& res, string& current, int open, int close, int n) {
		if (current.size() == n * 2) {
			res.push_back(current);
			return;
		}
		if (open < n) {
			current.push_back('(');
			backTrack(res, current, open+1, close, n);
			current.pop_back();
		}
		if (close < open) {
			current.push_back(')');
			backTrack(res, current, open, close+1, n);
			current.pop_back();
		}

	}
	vector<string> generateParenthesis(int n) {
		vector<string>res;
		string current;
		backTrack(res, current, 0, 0, n);
		return res;
	}
};

int main(){
	int n;
	cin >> n;
	Solution sol;
	auto res = sol.generateParenthesis(n);
	for (auto i : res) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}