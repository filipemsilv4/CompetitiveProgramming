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
    string s;
    cin >> s;

    char prev = '0';
    lli ans = 0, curr = 0;
    for (int i = 0; i < s.size(); i++){
        s[i] == prev ? ++curr : curr = 1;
        if (curr > ans) ans = curr;
        prev = s[i];
    }

    cout << ans << endl;
}
