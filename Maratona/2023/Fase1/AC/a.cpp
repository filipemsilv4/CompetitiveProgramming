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
    int n, h, tmp, ans = 0;
    cin >> n >> h;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        if (h >= tmp) ans++;
    }

    cout << ans << endl;
}
