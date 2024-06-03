#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n); // og array
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    map<int, int> diff; // value, diff occurencies
    vector<int> b(n);   // found array
    map<int, int> b_map;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (b[i] != a[i]) {
        diff[b[i]]++;
      }
      b_map[b[i]]++;
    }

    int m; // num of operations
    cin >> m;

    vector<int> d(m);
    for (int i = 0; i < m; i++) {
      cin >> d[i];
      // check if key is present (if theres divergence with this key)
      if (diff.find(d[i]) != diff.end()){
          diff[d[i]]--;
          if (diff[d[i]] <= 0){
              diff.erase(d[i]);
          }
      }
    }

    // cout << "---------------------> ";
    if (diff.size() > 0 || b_map.find(d[m-1]) == b_map.end()){
        cout << "NO" << endl;
        continue;
    }

    cout << "YES" << endl;
  }
}
