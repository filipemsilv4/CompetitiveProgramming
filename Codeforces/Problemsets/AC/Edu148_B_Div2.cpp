/*
g++ -std=c++17 -o bin/out Edu148_B_Div2.cpp && ./bin/out
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main() {
  lli t;
  cin >> t;
  while (t--) {
    lli n_elem, k_ops;
    cin >> n_elem >> k_ops;

    vector<lli> elems(n_elem + 1);
    vector<lli> elems_prefix_sum(n_elem + 1);

    for (lli i = 1; i <= n_elem; i++)
      cin >> elems[i];

    sort(elems.begin(), elems.end());

    for (lli i = 1; i <= n_elem; i++)
        elems_prefix_sum[i] = elems_prefix_sum[i - 1] + elems[i];

    // cout << endl;
    // for (int i = 1; i < elems.size(); i++)
    //   cout << elems[i] << " ";
    // cout << "[" << elems_prefix_sum[n_elem - 1] << "]" << endl;
    // for (int i = 1; i < elems_prefix_sum.size(); i++)
    //   cout << elems_prefix_sum[i] << " ";
    // cout << "[prefix_sum]" << endl;

    lli ans = 0;

    // Brute-force prefix and suffix combinations with size k_ops
    lli pref_end_index = 1, suff_start_index = n_elem;

    for (lli pref_ops = 0; pref_ops <= k_ops; pref_ops++) {
      pref_end_index = pref_ops * 2;
      if (pref_end_index > n_elem)
        break;

      lli suff_ops = k_ops - pref_ops;

      suff_start_index = n_elem - suff_ops;
      if (suff_start_index < pref_end_index)
        break;

      lli value = elems_prefix_sum[n_elem];
      if (suff_ops != 0) {
        value = elems_prefix_sum[suff_start_index];
      }
      if (pref_ops != 0) {
        value -= elems_prefix_sum[pref_end_index];
      }

      // cout << "v:" << value << " | p:" << pref_ops << ", s:" << suff_ops << endl;
      if (value > ans) {
        ans = value;
        // cout << "val: " << value
        //      << "  | pref_end_index: " << pref_end_index
        //      << "[ps:" << elems_prefix_sum[pref_end_index] << "]"
        //      << "[v:" << elems[pref_end_index] << "]"
        //      << ", suff_start_index: " << suff_start_index
        //      << "[ps:" << elems_prefix_sum[suff_start_index] << "]"
        //      << "[v:" << elems[suff_start_index] << "]"
        //      << endl;
      }
    }

    // cout << "--->";
    cout << ans << endl;
  }
}
