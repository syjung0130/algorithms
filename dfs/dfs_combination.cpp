#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> results;

void dfs(vector<int>& elem, int start, int n, int k) {
    if (k == 0) {
        results.push_back(elem);
        return;
    }
    for (int i = start; i < n + 1; i++) {
        elem.push_back(i);
        dfs(elem, i + 1, n, k - 1);
        elem.pop_back();
    }
}

void combi(int n, int k) {
    vector<int> elem;

    dfs(elem, 1, n, k);
}

void dfs_list(vector<int> &elem, vector<int> nums, int start, int k) {
    if (k == 0) {
        results.push_back(elem);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        elem.push_back(nums[i]);
        dfs_list(elem, nums, i + 1, k - 1);
        elem.pop_back();
    }
}

void combi_list(vector<int> nums, int k) {
    vector<int> elem;

    dfs_list(elem, nums, 0, k);
}

int main() {
	cout << "main()" << endl;
    cout << "results: " << endl;

    //combi(3, 2);
    vector<int> nums = {1, 2, 3, 4, 5};
    combi_list(nums, 3);

    for (auto v : results) {
        cout << "{ ";
        for (auto d : v) {
            cout << d << ", ";
        }
        cout << "}, " << endl;
    }
	return 0;
}

#if 0
def combination(n: int, k : int) :
    results = []
    def dfs(elements, start: int, k : int) :
    if k == 0 :
        results.append(elements[:])
        return
        # 자신 이전의 모든 값을 고정하여 재귀 호출
    for i in range(start, n + 1) :
        elements.append(i)
        dfs(elements, i + 1, k - 1)
        elements.pop()

    dfs([], 1, k)
    return results
#endif

#if 0
def combination_list(nums:list, k : int) :
    results = []
    print("combination_list()")

    def dfs(elements, start:int, k : int) :
    if k == 0 :
        results.append(elements[:])
        return
    # elif k < 0:
    #     return
    for i in range(start, len(nums)) :
        elements.append(nums[i])
        dfs(elements, i + 1, k - 1)
        elements.pop()

    dfs([], 0, k)
    return results
#endif

//#include <vector>
//#include <iostream>
//        using namespace std;
//bool check(int n) {
//    for (int i = 2; i < n / 2; i++)
//        if (n % i == 0)
//            return false;
//    return true;
//}
//int solution(vector<int> nums) {
//    int answer = 0;
//    int N = nums.size();
//    for (int i = 0; i < N; i++)
//        for (int j = i + 1; j < N; j++)
//            for (int k = j + 1; k < N; k++) {
//                if (check(nums[i] + nums[j] + nums[k]))
//                    answer++;
//            }
//    return answer;
//}
