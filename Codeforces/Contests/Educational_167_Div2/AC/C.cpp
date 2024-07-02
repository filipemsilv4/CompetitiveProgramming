#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0, tmp; i < n; i++)
      cin >> b[i];

    lli plus = 0;
    lli minus = 0;
    lli suma = 0;
    lli sumb = 0;
    for (int i = 0; i < n; i++) {
      // they're different
      if (a[i] > b[i]) {
        suma += a[i];
        continue;
      } else if (b[i] > a[i]) {
        sumb += b[i];
        continue;
      }

      // they're equal
      if (a[i] == 0)
        continue;
      else if (a[i] == 1)
        plus++;
      else if (a[i] == -1)
        minus++;
    }

    while (plus) {
      suma < sumb ? ++suma : ++sumb;
      --plus;
    }
    while (minus) {
      suma > sumb ? --suma : --sumb;
      --minus;
    }

    // cout << "----> ";
    cout << min(suma, sumb) << endl;
  }
}
