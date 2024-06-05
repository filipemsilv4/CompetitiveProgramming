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
    while (t--){
        lli n;
        cin >> n;

        int i = 1, j = n;

        while (i < j){
            cout << i << " " << j << " ";
            i++;
            j--;
        }
        if (n % 2 == 1) cout << i;

        cout << endl;
    }
}
