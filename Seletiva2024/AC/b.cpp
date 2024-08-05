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
    vector<int> GOOD = {1, 256, 65536, 16777216};
    vector<int> vals(4);
    vector<int> BAD = {16777216, 65536, 256, 1};
    string s; cin >> s;
    unsigned int num; cin >> num;

    unsigned int ans = 0;
    if (s == "GOOD"){
        for (int i = 3; i >= 0; i--){
            if (num < GOOD[i]) continue;
            vals[i] = num / GOOD[i];
            num -= GOOD[i] * vals[i];
        }

        for (int i = 3; i >= 0; i--){
            ans += (BAD[i] * vals[i]);
        }
    }
    else {
        for (int i = 0; i < 4; i++){
            if (num < BAD[i]) continue;
            vals[i] = num / BAD[i];
            num -= BAD[i] * vals[i];
        }

        for (int i = 0; i < 4; i++){
            ans += (GOOD[i] * vals[i]);
        }
    }

    // cout << "vals: ";
    // for (auto i : vals) cout << i << " ";
    // cout << endl;

    cout << ans << endl;
}
