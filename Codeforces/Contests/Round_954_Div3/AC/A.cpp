#include <algorithm>
#include <climits>
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
    while (t--){
        vector<int> x(3);
        cin >> x[0] >> x[1] >> x[2];

        lli min = INT_MAX;
        for (int i = 1; i <= 10; i++){
            lli val = abs(x[0] - i) + abs(x[1] - i) + abs(x[2] - i);
            if (val < min) min = val;
        }

        cout << min << endl;
    }
}
