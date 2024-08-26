#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main() {
  string s;
  ulli k;

  cin >> s >> k;

  vector<vector<char> > vec(k);

  for (ulli i = 0; i < s.size(); i++){
      vec[i % k].push_back(s[i]);
  }

  for (auto &v : vec){
      sort(v.begin(), v.end());
  }

  ulli elem = 0;
  for (ulli i = 0; ; i++){
      if (i == k){
        i %= k;
        elem++;
        i--;
        continue;
      }
      // cout << " | len: " << elem << "| i: " << i << endl;
      if (elem >= vec[i].size()) break;
      cout << vec[i][elem];
  }

  cout << endl;
}
