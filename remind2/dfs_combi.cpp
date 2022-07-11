#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> results;

void dfs_list(vector<int> &elem, vector<int> &nums, int start, int k) {
	if (k == 0) {
		results.push_back(elem);
		return;
	}
	for (int i = start; i < nums.size(); i++) {
		elem.push_back(nums[i]);
		dfs_list(elem, nums, i+1, k-1);
		elem.pop_back();
	}
}

void combi_list(vector<int> &nums, int k) {
	vector<int> elem;

	dfs_list(elem, nums, 0, k);
}

int main()
{
	cout << "main(): " << endl;
	cout << "results: " << endl;

	vector<int> nums = {1, 2, 3, 4, 5};
	combi_list(nums, 3);

	for (auto v: results) {
		cout << "{";
		for (auto d: v) {
			cout << d << ", ";
		}
		cout << "}," << endl;
	}

	return 0;
}
