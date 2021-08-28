#include <iostream>
#include <vector>

using namespace std;

namespace syj {
namespace recursive {
#if 0
int fibo(int x) {
    cout << "f(" << x << ")" << endl;
    if (x == 1 || x == 2) 
        return 1;
    //중복해서 방문하게 되서 시간복잡도가 크다.
    //99이상의 숫자만 입력해도 오래걸린다.
    return fibo(x-1) + fibo(x-2);
}
#else

unsigned int fibo(unsigned int x, vector<int> &v) {
    cout << "f(" << x << ")" << endl;
    if (x == 1 || x == 2) 
        return 1;
    
    if (v[x] != 0)
        return v[x];

    v[x] = fibo(x-1, v) + fibo(x-2, v);

    return v[x];
}
#endif

};
};

int main() {
    // cout << syj::recursive::fibo(6) << endl;

    // vector<int> v(100, 0);
    vector<int> v;
    int size = 100;
    for (int i = 0; i < size; i++) {
        v.push_back(0);
    }
    cout << syj::recursive::fibo(99, v) << endl;
    return 0;
}