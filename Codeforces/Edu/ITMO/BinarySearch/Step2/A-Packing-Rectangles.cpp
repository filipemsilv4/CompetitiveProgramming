/*
g++ -std=c++17 -o bin/out A-Packing-Rectangles.cpp && ./bin/out
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

lli w, h, n;

bool good(lli x){
    return ((x / h) * (x / w)) >= n;
}

int main(){
    cin >> w >> h >> n;

    lli l = -1;
    lli r = 1;

    while (!good(r)) r = r << 1;

    while (l < r - 1){
        lli mid = (l + r) / 2;
        // cout << l << " " << mid << " " << r << "\n";
        if (good(mid)){
            r = mid;
            continue;
        }
        l = mid;
    }

    cout << r << "\n";
}
