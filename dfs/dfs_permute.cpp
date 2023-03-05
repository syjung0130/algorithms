#include <iostream>
#include <vector>


using namespace std;

vector<vector<int>> results;

void dfs_permute(vector<int> prev_elem, vector<int> elements, int n, int k) {
	if (elements.size() == n - k) {
		results.push_back(prev_elem);
		for (auto d : prev_elem)
			cout << d << ", ";
		cout << endl;
		return;
	}

	for (auto it = elements.begin(); it != elements.end(); it++) {
		vector<int> next_elem(elements);

		next_elem.erase(next_elem.begin() + std::distance(elements.begin(), it));
		prev_elem.push_back(*it);
		dfs_permute(prev_elem, next_elem, n, k);
		prev_elem.pop_back();
	}
}

void permute(vector<int> nums, int k) {
	vector<int> prev_elem;
	dfs_permute(prev_elem, nums, nums.size(), k);
}

int main()
{

	//cout << "main(): " << endl;
	vector<int> v1 = { 1, 2, 3 };
	permute(v1, 2);

	return 0;
}
