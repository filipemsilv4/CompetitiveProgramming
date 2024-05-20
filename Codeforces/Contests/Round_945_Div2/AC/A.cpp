#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define lli long long int

int main() {
  int t;
  cin >> t;
  while (t--) {
    priority_queue<int> pq;

    vector<int> three;

    for (int i = 0, tmp; i < 3; i++) {
      cin >> tmp;
      pq.push(tmp);
      three.push_back(tmp);
    }

    int ans = 0;

    while (pq.top() != 0) {
      int top = pq.top();
      pq.pop();

      int top2 = pq.top();
      pq.pop();
      if (top2 == 0) {
        if (top % 2 != 0) {
          ans = -1;
        }
        break;
      }
      top--;
      top2--;
      pq.push(top);
      pq.push(top2);

      ans++;
    }

    cout << ans << endl;
  }
}
