#include <iostream>

using namespace std;

#define lli long long int

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int num = 0;
    for (const auto &c : s){
        if (c == 'U') num++;
    }

    if (num % 2 != 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

  }
}
