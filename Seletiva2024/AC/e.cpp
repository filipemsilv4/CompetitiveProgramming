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
    int t;
    cin >> t;

    vector<int> v(t + 1);
    for (int i = 1; i <= t; i++) cin >> v[i];

    int ans = 0;
    int curr = 0;
    for (int i = 1; i <= t; i++){
        if (v[i] >= v[i-1]){
            curr++;
            if (curr > ans){
                ans = curr;
            }
        } else {
            curr = 1;
        }
    }
    cout << ans << endl;
}
