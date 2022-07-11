#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> results;
int n = 0;

void dfs_permute(vector<int> prev_elem, vector<int> elements, int k) {
	if (elements.size() == n-k) {
		results.push_back(prev_elem);
		for (auto d : prev_elem)
			cout << d << ", ";
		cout << endl;
		return;
	}

	cout << __LINE__ << endl;
	for (auto it = elements.begin(); it != elements.end(); it++) {
		vector<int> next_elem(elements);
		int idx = std::distance(elements.begin(), it);
		vector<int>::iterator offset = next_elem.begin();
		std::advance(offset, idx);
		next_elem.erase(offset);

		prev_elem.push_back(*it);
		dfs_permute(next_elem, elements, k);
		prev_elem.pop_back();
	}
}

void permute(vector<int> nums, int k) {
	vector<int> prev_elem;
	n = nums.size();
	dfs_permute(prev_elem, nums, k);
}

int main()
{
	cout << "main(): " << endl;

	vector<int> v1 = {1, 2, 3};
	permute(v1, 2);

	cout << endl;
	for (auto v : results) {
		for (auto d : v) {
			cout << d << ", ";
		}
		cout << endl;
	}

	return 0;
}
