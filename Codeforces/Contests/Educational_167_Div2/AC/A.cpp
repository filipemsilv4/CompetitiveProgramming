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
    int n, x, y;
    cin >> n;

    while (n--){
        cin >> x >> y;
        int moves = abs(x);
        y -= (moves - 1);

        if (y < (moves * -1)){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }
}
