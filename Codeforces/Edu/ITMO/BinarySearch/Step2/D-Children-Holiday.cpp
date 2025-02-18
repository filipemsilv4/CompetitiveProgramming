/*
g++ -std=c++17 -o bin/out D-Children-Holiday.cpp && ./bin/out
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

// t - time to inflate a baloon
// z - how many ballons can inflate before getting tired
// y - rest time
vector<pair<pair<lli,lli>, lli > > a; // t, z,  y
vector<lli> ans2; // the number of balloons inflated by each of the invited assistants
lli m, n; // balloons, assistants

bool good(lli clock){
    lli total_ans = 0;
    lli i;
    for (i = 0; i < n; i++){
        lli clk = clock;
        lli local_ans = 0;
        
        lli t = a[i].first.first;
        lli z = a[i].first.second;
        lli y = a[i].second;
        
        lli tam_seg = t * z + y;
        local_ans += (clk / tam_seg) * z;
        
        lli tam_picotado = clk % tam_seg;
        if (tam_picotado >= t * z) local_ans += z;
        else local_ans += tam_picotado / t;

        if (total_ans + local_ans >= m){
            ans2[i] = m - total_ans;
            total_ans += ans2[i];
            break;
        }
        
        total_ans += local_ans;
        ans2[i] = local_ans;

        // cout << "[clock=" << clock << " | i:" << i << " | local_ans:" << local_ans << " | total_ans:" << total_ans << "]\n";
    }
    for (i = i + 1; i < n; i++){ ans2[i] = 0; }

    return total_ans >= m;
}

int main(){
    cin >> m >> n;
    a.resize(n);
    ans2.resize(n, 0);

    for (lli i = 0; i < n; i++){
        cin >> a[i].first.first >> a[i].first.second >> a[i].second; // t, z, y
    }

    if (m == 0){
        cout << "0" << "\n";
        for (lli i = 0; i < n; i++) cout << "0" << " ";
        cout << "\n";
        return 0;
    }

    lli l = 0, r = 1;

    while (!good(r)) { l = r; r = r << 1; }

    while (l < r - 1){
        lli mid = (l + r) / 2;

        if (good(mid)){
            r = mid;
            continue;
        }

        l = mid;
    }

    good(r); // good() always overrides ans2, so we need to call it again

    cout << r << "\n";
    for (int i = 0, acc = 0; i < n; i++){
        cout << ans2[i] << " ";
    }
    cout << "\n";

}
