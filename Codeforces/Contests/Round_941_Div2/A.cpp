#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    //cout << "----> ";

    vector<int> cards(105);

    for (int i = 0, tmp; i < n; i++) {
      cin >> tmp;
      cards[tmp]++;
    }

    sort(cards.rbegin(), cards.rend());

    //cout << "card[0]:" << cards[0] << endl;

    if (cards[0] >= k) {
      cout << k - 1 << endl;
    } else {
        cout << n << endl;
    }
  }
}
