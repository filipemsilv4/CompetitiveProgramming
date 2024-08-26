/*
g++ -std=c++17 -o bin/out Permutations.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main(){
    lli t; cin >> t;

    if (t == 2 || t == 3){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    if (t == 4){
        cout << "2 4 1 3" << endl;
        return 0;
    }

    vector<lli> ans(t);

    lli val = 1;
    for (lli i = 0; i < t; i+=2) ans[i] = val++;
    for (lli i = 1; i < t; i+=2) ans[i] = val++;
    for (lli i = 0; i < t; i++) cout << ans[i] << " ";

    cout << endl;
}
