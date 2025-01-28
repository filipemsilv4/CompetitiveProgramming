/*
g++ -std=c++17 -o bin/out A-Binary-Search.cpp && ./bin/out
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
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);

    for (int i = 0; i < n; i++){ cin >> vec[i]; }

    for (int i = 0, q; i < k; i++){
        cin >> q;
        auto lb = lower_bound(vec.begin(), vec.end(), q);
        if (lb != vec.end() && *lb == q){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}
