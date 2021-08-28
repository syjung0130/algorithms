#include <iostream>
#include <vector>

using namespace std;

namespace recursive {
int binary_search(vector<int> &v, int start, int end, int target) {
    if (start > end) return 0;

    int mid = (start+end)/2;
    
    if (target < v[mid]) {
        return binary_search(v, start, mid-1, target);
    }
    else if (target > v[mid]) {
        return binary_search(v, mid+1, end, target);
    }
    else if (target == v[mid]) {
        cout << "found : " << "[" << mid << "] " << v[mid] << endl;
        return mid;
    }
}
};

namespace iterative {
int binary_search(vector<int> &v, int target) {
    int mid = 0;
    int start = 0, end = v.size()-1;

    while (start <= end) {
        mid = (start+end)/2;

        if (target < v[mid]) {
            end = mid-1;
        }
        else if (target > v[mid]) {
            start = mid+1;
        }
        else {//if (target == v[mid]) {
            return mid;
        }
    }

    return 0;
}
};

int main () 
{
    vector<int> v = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    int target = 7;
    int target_idx = recursive::binary_search(v, 0, v.size()-1, target);
    cout << "===== recursive binary search =====" << endl;
    cout << " target idx: " << target_idx << endl;
    if (target_idx == 0) {
        cout << "target is not in array" << endl;
    }

    target = 9;
    target_idx = iterative::binary_search(v, target);
    cout << "===== iterative binary search =====" << endl;
    cout << " target idx: " << target_idx << endl;

    return 0;
}