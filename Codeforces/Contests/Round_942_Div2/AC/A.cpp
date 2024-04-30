#include <deque>
#include <iostream>

using namespace std;

#define lli long long int

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n; // num of problems
    cin >> n;

    deque<lli> a;
    deque<lli> b;

    // read A
    for (int i = 0, tmp; i < n; i++) {
      cin >> tmp;
      a.push_back(tmp);
    }

    // read B
    for (int i = 0, tmp; i < n; i++) {
      cin >> tmp;
      b.push_back(tmp);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        a.pop_back();
        a.push_front(b[0]);
        ans++;
        i--;
      }
    }

    cout << ans << endl;
  }
}
