#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, f, k;
    cin >> n >> f >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];

    int fav = a[f - 1];
    sort(a.rbegin(), a.rend());

    int first = -1;
    int last = -1;
    for (int i = 0; i < n; i++){
        if (a[i] == fav){
            last = i;
            if (first == -1){
                first = i;
            }
        }
    }

    k--;

    if (k >= last){
        cout << "YES" << endl;
        continue;
    }

    if (k < first){
        cout << "NO" << endl;
        continue;
    }

    cout << "MAYBE" << endl;
  }
}
