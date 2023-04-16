#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		vector<int>dp(n + 1);
		dp[0] = 0;
		dp[1] = nums[0];
		for (int i = 2; i <= n; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		}
		return dp[n];
	}
};


int main() {
	vector<int>nums;
	int tmp;
	while (cin >> tmp) {
		nums.push_back(tmp);
		if (cin.get() == '\n')
			break;
	}
	Solution sol;
	int res = sol.rob(nums);
	cout << res << endl;
	return 0;
}
