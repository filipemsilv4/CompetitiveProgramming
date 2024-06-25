#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        pair<lli, lli> t1;
        pair<lli, lli> t2;
        cin >> t1.first >> t2.first;
        cin >> t1.second >> t2.second;

        // if both t1 between t2: NO
        if (t2.first < t1.first && t2.second > t1.second){
            cout << "NO" << endl;
            continue;
        }

        if (t1.first < t2.first && t1.second > t2.second){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }
}
