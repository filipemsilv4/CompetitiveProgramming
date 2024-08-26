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
    lli d, c, r;
    cin >> d >> c >> r;

    vector<lli> c_activs;

    for (int i = 0, tmp; i < c; i++){
        cin >> tmp;
        c_activs.push_back(tmp);
    }

    for (int i = 0, tmp; i < r; i++){
        cin >> tmp;
        d += tmp;
    }

    lli ans = r;
    for (auto const &i : c_activs){
        if (i > d) break;
        ans++;
        d -= i;
    }

    // cout << "---> ";
    cout << ans << endl;
}
