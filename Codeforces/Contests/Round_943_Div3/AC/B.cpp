#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;

    //cout << "-----> ";
    int ans = 0;
    for (int i = 0; i < m && ans < n; i++) {
        //cout << "a[" << ans << "] == " << a[ans] << " | b[" << i << "] == " << b[i];
      if (a[ans] == b[i]) {
        ans++;
        //cout << "ans++";
      }
      //cout << endl;
    }

    cout << ans << endl;
  }
}
