#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool sort_pair(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first > b.first;
}

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> v(13); // times_appeared, value
  vector<int> ans;

  int value;
  for (int i = 0; i < N; i++) {
    cin >> value;
    v[value] = {v[value].first + 1, value};
  }

  sort(v.begin(), v.end(), sort_pair);

  cout << v[0].second;
  for (int i = 1; i <= N; i++) {
    if (v[i].first != v[i - 1].first)
      break;

    cout << " " << v[i].second;
  }

  cout << endl;

  return 0;
}
