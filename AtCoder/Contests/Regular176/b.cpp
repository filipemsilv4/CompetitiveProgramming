#include <iostream>
#include <string>

using namespace std;

#define lli long long int

// lli modpow(lli x, lli n, lli m) {
//   if (n == 0)
//     return 1 % m;
//   lli u = modpow(x, n / 2, n);
//   u = (u * u) % m;
//   if (n % 2 == 1)
//     u = (u * u) % m;
//   return u;
// }

int main() {
  int t;
  cin >> t;
  while (t--) {
    lli n, m, k;
    cin >> n >> m >> k;

    n = 1 << n;
    m = 1 << m;
    k = 1 << k;

    lli ans = n % (m - k);

    // cout << ans << endl;

    string a = to_string(ans);
    cout << a[a.size() - 1] << endl;
  }
}
