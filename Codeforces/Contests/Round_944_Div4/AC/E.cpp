#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define lli long long int

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(k + 1); // distancia
    vector<int> b(k + 1); // tempo

    for (int i = 1; i <= k; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
      cin >> b[i];
    }

    for (int i = 0; i < q; i++) {
      lli querie;
      cin >> querie;

      int uaq_index = 0, r = k;
      while (r - uaq_index > 1) {
        lli mid = (r + uaq_index) / 2;

        if (a[mid] > querie) {
          r = mid;
        } else {
          uaq_index = mid;
        }
      }

      lli ans = (querie - a[uaq_index]) * (b[uaq_index + 1] - b[uaq_index]) /
                (a[uaq_index + 1] - a[uaq_index]);

      ans += b[uaq_index];

      cout << ans << " ";
    }
    cout << endl;
  }
}
