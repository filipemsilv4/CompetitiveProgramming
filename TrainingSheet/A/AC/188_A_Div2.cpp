#include <iostream>

using namespace std;

#define lli long long int

int main() {
  lli k, n;
  cin >> k >> n;

  lli mid = (k + 1) / 2;

  if (n <= mid) {
    n = (n * 2) - 1;
  } else {
    n = (n - mid) * 2;
  }

  cout << n << endl;
}
