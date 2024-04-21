#include <iostream>

using namespace std;

#define lli long long int

int main() {
  int t;
  cin >> t;

  while (t--) {
    lli a, b, c;
    cin >> a >> b >> c;

    // No such tree exists
    if (a == -1) {
      cout << "-1" << endl;
      continue;
    }

    int height = 0;
    int current_level_leafs = 1;
    int next_level_leafs = 0;
  }
}
