#include <iostream>
#include <vector>

#define lli long long int

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<lli> a;

  lli tmp;
  cin >> tmp;
  a.push_back(tmp);

  for (int i = 1; i < n; i++) {
    cin >> tmp;

    if (a.back() == tmp) {
      a.pop_back();
      a.push_back(tmp + 1);

      while (a.size() >= 2 && a[a.size() - 1] == a[a.size() - 2]) {
        tmp = a[a.size() - 1] + 1;
        a.pop_back();
        a.pop_back();
        a.push_back(tmp);
      }
    } else {
      a.push_back(tmp);
    }
  }

  cout << a.size() << endl;
}
