#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> ans;

  int tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    ans.push_back(tmp);
  }

  sort(ans.begin(), ans.end());

  for (const auto &i : ans) {
    cout << i << " ";
  }

  cout << endl;
}
