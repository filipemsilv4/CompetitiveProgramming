#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<bool> teeth(n, true);

  int t, ans = n;
  while (q--) {
    cin >> t;
    if (teeth[t]) {
      ans--;
      teeth[t] = false;
    } else {
      ans++;
      teeth[t] = true;
    }
  }

  cout << ans << endl;
}
