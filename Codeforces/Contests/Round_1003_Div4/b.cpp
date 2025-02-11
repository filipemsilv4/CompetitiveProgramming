/*
g++ -std=c++17 -o bin/out b.cpp && ./bin/out
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

int main(){
    lli t;
    cin >> t;
    while (t--){
        string s; cin >> s;

        int ans = s.size();
        for (int i = s.size() - 2; i >= 0; i--){
            if (s[i] == s[i+1]){
                ans = s.size() - (i + 1);
                break;
            }
        }

        cout << ans << endl;
    }
}
