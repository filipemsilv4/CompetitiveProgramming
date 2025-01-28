/*
g++ -std=c++17 -o bin/out Pinely3_B_Div1-2.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"
#define bi 1000000000

using namespace std;

int main(){
    lli t;
    cin >> t;
    while (t--){
        lli n;
        cin >> n;

        vector<lli> a(n);

        bool even = false;
        bool odd = false;
        for (lli i = 0, tmp; i < n; i++){
            cin >> tmp;
            a[i] = tmp;

            if (tmp & 1ll){
                odd = true;
                continue;
            }

            even = true;
        }

        if (even && odd){
            cout << 2 << endl;
            continue;
        }


        // find a power of 2 that works
        for (lli ans = 2; ans < 1ll<<60; ans = ans<<1){
            set<lli> s;
            // check the entire array
            for (lli index_in_a = 0; index_in_a < n; index_in_a++){
                lli modded = a[index_in_a] % ans;
                s.insert(modded);

                if (s.size() > 2){
                    index_in_a = n;
                    continue;
                }
            }

            if (s.size() == 2){
                cout << ans << endl;
                break;
            }
        }

    }
}
