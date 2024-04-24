#include <iostream>

using namespace std;

bool is_prime(int n) {
  for (int d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      return false;
    }
  }

  return n >= 2;
}

int main() {
  int n;
  cin >> n;

  while (n != 0) {
    if (is_prime(n)) {
      cout << "no" << endl;
    } else {
      cout << "yes" << endl;
    }

    cin >> n;
  }
}
