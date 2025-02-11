/*
g++ -std=c++17 -o bin/out B-Ropes.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <math.h>
#include <iomanip>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"
#define bi 1000000000

using namespace std;

vector<int> rope;
int n, k;

bool good(double x){
    lli pieces = 0;

    for (int i = 0; i < rope.size(); i++){
        pieces += floor(rope[i] / x);
    }

    return pieces >= k;
}

// There are n ropes, you need to cut k pieces of the same length from them. Find the maximum length of pieces you can get.
int main(){
    cin >> n >> k;

    rope.resize(n);
    for (int i = 0; i < n; i++){ 
        cin >> rope[i];
    }

    double l = 0, r = 1e9;
    for (int i = 0; i < 150; i++){
        double mid = (l + r) / (double)2;

        if (good(mid)){
            l = mid;
            continue;
        }

        r = mid;
    }
    
    cout << setprecision(20) << l << "\n";
}
