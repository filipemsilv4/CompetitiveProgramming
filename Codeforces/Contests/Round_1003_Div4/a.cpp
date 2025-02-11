/*
g++ -std=c++17 -o bin/out a.cpp && ./bin/out
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
        string w; cin >> w;
        
        // cout << "----> ";
        for (int i = 0; i < w.size() - 2; i++){
            cout << w[i];
        }

        cout << "i" << "\n";
    }
}
