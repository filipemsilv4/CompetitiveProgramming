/*
g++ -std=c++17 -o bin/out C-Very-Easy-Task.cpp && ./bin/out
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

int n, x, y;

bool good(int t){
    if (t < min(x, y)) return false;
    t -= min(x, y);
    return (1 + floor(t / x) + floor(t / y)) >= n;
}

int main(){
    cin >> n >> x >> y;

    int l = 0, r = 1;
    while (!good(r)){ l = r; r = r << 1; }

    while (l < r - 1){
        lli mid = (l + r) / 2;
        if (good(mid)){
            r = mid;
            continue;
        }
        l = mid;
    }

    cout << r << "\n";
}
