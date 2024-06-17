#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

bool bs(vector<lli> &paes, vector<bool> &comidos, lli d, lli days, lli n) {
  // cout << "paes: ";
  // for (auto const &n : paes)
  //   cout << n - days << " ";
  // cout << endl;
  // binary search for d-1 and d
  lli l = 0, r = n - 1;
  while (l <= r) {
    lli mid = l + (r - l) / 2;
    // printf("l:%lli, r: %lli, mid:%lli | ", l, r, mid);
    // printf("VALS: l:%lli, r: %lli, mid:%lli, d:%lli, days:%lli\n",
           // paes[l] - days, paes[r] - days, paes[mid] - days, d, days);
    if (paes[mid] - days == d) {
      if (!comidos[mid]) {
        comidos[mid] = true;
        // cout << "RETORNO 1 TRUE, COMIDO " << mid << "=" << paes[mid] - days
             // << endl;
        return true;
      } else {
        for (lli i = mid; i >= 0; i--) {
          if (paes[i] != paes[mid])
            break;
          else if (!comidos[i]) {
            comidos[i] = true;
            // cout << "RETORNO 2 TRUE\n";
            return true;
          }
        }
        for (lli i = mid; i < n; i++) {
          if (paes[i] != paes[mid])
            break;
          else if (!comidos[i]) {
            comidos[i] = true;
            // cout << "RETORNO 3 TRUE\n";
            return true;
          }
        }
        // cout << "RETORNO 4 FALSE\n";
        return false;
      }
    } else if (paes[mid] - days > d) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  // cout << "RETORNO 5 FALSE\n";
  return false;
}

int main() {
  lli n, d;
  cin >> n >> d;

  vector<lli> paes(n);
  vector<bool> comidos(n);

  for (lli i = 0; i < n; i++)
    cin >> paes[i];

  sort(paes.begin(), paes.end());

  lli days = -1;
  lli ans = 0;
  while ((paes[n - 1] - days) >= (d * -1)) {
    ++days;
    // binary search for -d and d
    if (bs(paes, comidos, d * -1, days, n)) {
      ans++;
      continue;
    }
    if (bs(paes, comidos, d, days, n)) {
      ans++;
      continue;
    }
  }

  cout << ans << endl;
}
