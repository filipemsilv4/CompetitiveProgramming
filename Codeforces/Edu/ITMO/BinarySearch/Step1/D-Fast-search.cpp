/*
g++ -std=c++17 -o bin/out D-Fast-search.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"
#define bi 1000000000

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }

    int k;
    cin >> k;

    sort(vec.begin(), vec.end());
    // for (auto i: vec){
    //     cout << i << " ";
    // }
    // cout << endl;

    while (k--){
        int l, r;
        cin >> l >> r;

        auto lind = lower_bound(vec.begin(), vec.end(), l);
        auto rind = upper_bound(vec.begin(), vec.end(), r) - 1;

        // cout << "[" << lind - vec.begin() << ", " << rind - vec.begin() << "]    |    ans: ";

        if (lind == vec.end() || rind < lind){
            cout << 0 << endl;
            continue;
        }

        cout << rind - lind + 1 << endl;
    }
    
}
