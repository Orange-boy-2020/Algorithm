#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string>combinations;
		if (digits.empty())
			return combinations;
		unordered_map<char, string>phone{
			{'2',"abc"},
			{'3',"def"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"}
		};

		string combination;

		backTrack(combinations, phone, combination, digits, 0);

		return combinations;
	}

	void backTrack(vector<string>& combinations, const unordered_map<char, string>& phone, string& combination, string& digits, int index) {
		if (index == digits.size()) {
			combinations.push_back(combination);
			return;
		}
		char digit = digits[index];
		const string& letters = phone.at(digit);
		for (const auto& letter : letters) {
			combination.push_back(letter);
			backTrack(combinations, phone, combination, digits, index + 1);
			combination.pop_back();
		}
	}
	
};

int main() {
	
	string dights;
	getline(cin, dights);

	Solution sol;
	vector<string> res = sol.letterCombinations(dights);

	for (auto r : res) {
		cout << r << endl;
	}

	system("pause");
	return 0;
}