#include <iostream>
#include <vector>

using namespace std;

#define lli long long int

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<lli> x;

    for (int i = 0, tmp; i < n - 1; i++) {
      cin >> tmp;
      x.push_back(tmp);
    }

    vector<lli> a;
    a.push_back(1000);

    for (int i = 0; i < n - 1; i++) {
      int val = a[i] + x[i];
      a.push_back(val);
    }

    // cout << "ans: ";
    for (const auto &c : a) {
      cout << c << " ";
    }
    cout << endl;
  }
}
