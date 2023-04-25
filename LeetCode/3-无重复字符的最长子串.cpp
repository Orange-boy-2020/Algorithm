#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() <= 1)
			return s.size();
		int length = s.size();
		int left = 0, right = 0;
		int res = 0;

		map<char, int>count;
		for (; right < length; right++) {
			count[s[right]]++;
			while (count[s[right]] >= 2) {
				count[s[left++]]--;
			}
			res = max(res, right - left + 1);
		}

		return res;
	}
};

int main() {
	string s;
	getline(cin, s);
	Solution sol;
	int res = sol.lengthOfLongestSubstring(s);
	cout << res << endl;

	system("pause");
	return 0;
}