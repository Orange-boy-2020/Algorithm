#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
#if 1
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int res = 0;
		while (left < right) {
			int area = min(height[left], height[right]) * (right - left);
			res = max(res, area);
			if (height[left] <= height[right]) {
				++left;
			}
			else {
				--right;
			}
		}
		return res;
	}
#endif
};

int main() {
	vector<int>height;
	int tmp;
	while (cin >> tmp) {
		height.emplace_back(tmp);
		if (cin.get() == '\n')
			break;
	}


	Solution sol;
	int res = sol.maxArea(height);
	cout << res << endl;

	system("pause");
	return 0;
}