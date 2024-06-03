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
  lli n;
  cin >> n;
  vector<lli> xyz(3);

  for (lli i = 0; i < n; i++) {
    for (lli j = 0, tmp; j < xyz.size(); j++) {
      cin >> tmp;
      xyz[j] += tmp;
    }
  }

  if (xyz[0] == 0 && xyz[1] == 0 && xyz[2] == 0) {
    cout << "YES" << endl;
    return 0;
  }

  cout << "NO" << endl;
}
