/*
g++ -std=c++17 -o bin/out 367_B_Div2.cpp && ./bin/out
*/

//https://codeforces.com/problemset/problem/706/B

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main(){
    // The first line of the input contains a single integer n (1 ≤ n ≤ 100 000) — the number of shops in the city that sell Vasiliy's favourite drink.
    int n; cin >> n;

    // The second line contains n integers xi (1 ≤ xi ≤ 100 000) — prices of the bottles of the drink in the i-th shop.
    vector<int> x(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    // The third line contains a single integer q (1 ≤ q ≤ 100 000) — the number of days Vasiliy plans to buy the drink.
    int q; cin >> q;

    // Then follow q lines each containing one integer mi (1 ≤ mi ≤ 109) — the number of coins Vasiliy can spent on the i-th day.
    for (int i = 0, m; i < q; i++){
        cin >> m;
        auto ub = upper_bound(x.begin(), x.end(), m);
        
        // cout << "-----> ";
        cout << ub - x.begin() << endl;
    }
}
