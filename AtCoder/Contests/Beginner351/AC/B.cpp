#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define lli long long int

int main() {
  int n;
  cin >> n;
  vector<lli> xa(n);
  vector<lli> ya(n);
  vector<lli> xb(n);
  vector<lli> yb(n);

  // Read A
  for (int i = 0; i < n; i++) {
    lli sum = 0;

    string s;
    cin >> s;

    for (int j = 0, tmp; j < n; j++) {
      ya[j] += (int)s[j];
      sum += (int)s[j];
    }
    xa[i] = sum;
  }

  // Read B
  for (int i = 0; i < n; i++) {
    lli sum = 0;

    string s;
    cin >> s;

    for (int j = 0, tmp; j < n; j++) {
      yb[j] += (int)s[j];
      sum += (int)s[j];
    }
    xb[i] = sum;
  }

  // Print X
  for (int i = 0; i < n; i++) {
    if (xa[i] != xb[i]) {
      cout << i + 1 << " ";
      break;
    }
  }

  // Print Y
  for (int i = 0; i < n; i++) {
    if (ya[i] != yb[i]) {
      cout << i + 1 << endl;
      break;
    }
  }
}
