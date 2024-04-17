#include <iostream>

using namespace std;

int count(int n, string s) {
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      ans++;
    }
  }

  return ans;
}

int main() {
  int t;
  cin >> t;

  int n;
  string s;
  for (int i = 0; i < t; i++) {
    cin >> n >> s;
    cout << count(n, s) << endl;
  }
}
