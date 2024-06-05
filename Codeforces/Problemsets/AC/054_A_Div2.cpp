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
    string goal = "hello";
    string s; cin >> s;

    int ptr = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (ptr == goal.length()){
            cout << "YES" << endl;
            return 0;
        }
        if (s[i] == goal[ptr]){
            ptr++;
        }
    }

    cout << "NO" << endl;
}
