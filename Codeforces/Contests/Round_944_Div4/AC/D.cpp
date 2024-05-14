#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    // cout << "---> ";

    char last_digit = s[0];
    int blocks = 1;
    bool zero_one = false;

    for (int i = 1; i < s.length(); i++) {
      if (last_digit == '0' && s[i] == '1')
        zero_one = true;

      if (s[i] != last_digit)
        blocks++;

      last_digit = s[i];
    }

    if (zero_one)
      blocks--;

    cout << blocks << endl;
  }
}
