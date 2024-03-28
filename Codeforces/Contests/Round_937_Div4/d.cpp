#include <iostream>
#include <ostream>
#include <string>

using namespace std;

bool is_dec_bin(int n) {
  string s = to_string(n);

  for (const auto &c : s) {
    if (c != '0' && c != '1') {
      return false;
    }
  }

  return true;
}

int main() {
  int t;
  cin >> t;

  int n;
  for (int i = 0; i < t; i++) {
    cin >> n;
    int n_tmp = n;
    bool flag = false;

    if (is_dec_bin(n_tmp)) {
      cout << "YES" << endl;
      continue;
    }

    while (n_tmp % 11 == 0) {
      n_tmp = n_tmp / 11;
      if (is_dec_bin(n_tmp)) {
        cout << "YES" << endl;
        flag = true;
        break;
      }
    }

    if (flag)
      continue;

    if (is_dec_bin(n_tmp)) {
      cout << "YES" << endl;
      continue;
    }

    cout << "NO" << endl;
  }
}
