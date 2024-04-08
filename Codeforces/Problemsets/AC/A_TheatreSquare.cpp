// https://codeforces.com/problemset/problem/1/A

#include <iostream>

using namespace std;

int main() {
  unsigned long long n, m, a;
  cin >> n >> m >> a;

  if (n % a != 0) {
    n += a;
    n -= n % a;
  }
  if (m % a != 0) {
    m += a;
    m -= m % a;
  }

  cout << (n / a) * (m / a) << endl;
}
