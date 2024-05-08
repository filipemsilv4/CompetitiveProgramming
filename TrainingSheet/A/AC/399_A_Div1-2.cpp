#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

#define lli long long int

int main(){
    lli n; cin >> n;

    if (n < 3){
        cout << 0 << endl;
        return 0;
    }

    vector<lli> s;

    for (lli i = 0, tmp; i < n; i++){
        cin >> tmp;
        s.push_back(tmp);
    }

    sort(s.begin(), s.end());

    lli min = s[0];
    lli max = s[n-1];
    lli ans = 0;

    for (lli i = 1; i < n; i++){
        if (s[i] != s[0] && s[i] != s[n-1]){
            ans++;
        }
    }

    cout << ans << endl;
}
