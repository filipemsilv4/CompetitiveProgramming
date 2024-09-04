/*
g++ -std=c++17 -o bin/out Edu168_C_Div2.cpp && ./bin/out
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main() {
  lli t;
  cin >> t;
  while (t--) {
    lli n;
    string s;
    cin >> n >> s;

    stack<pair<lli, char> > q; // pos, char

    lli ans = 0;
    lli balance = 0;
    for (lli i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        balance++;
      else if (s[i] == ')')
        balance--;
      else {
        if (balance == 0) {
          s[i] = '(';
          balance++;
        } else {
          s[i] = ')';
          balance--;
        }
      }

      if (s[i] == ')'){
          // cout << "ans(" << ans << ")+=" << i << "-" << q.top().first << endl;
          ans += (i - q.top().first);
          q.pop();
      } else {
          q.push({i, s[i]});
      }
    }

    // cout << s << " | " ;
    cout << ans << endl;
  }
}
