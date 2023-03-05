#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> results;

void dfs_combination(vector<int>& elem, vector<int>& nums, int start, int k) {
	if (k == 0) {
		results.push_back(elem);
		return;
	}
	for (int i = start; i < nums.size(); i++) {
		elem.push_back(nums[i]);
		dfs_combination(elem, nums, i + 1, k - 1);
		elem.pop_back();
	}
}

void combination(vector<int>& nums, int k) {
	vector<int> elems;
	dfs_combination(elems, nums, 0, k);
}

int main()
{
	//cout << "main(): " << endl;

	vector<int> nums = { 1, 2, 3, 4, 5 };
	combination(nums, 3);

	cout << "results: " << endl;
	cout << "{" << endl;
	for (auto v : results) {
		cout << "  {";
		for (auto d : v) {
			cout << d << ", ";
		}
		cout << "}" << endl;
	}
	cout << "}" << endl;

	return 0;
}
