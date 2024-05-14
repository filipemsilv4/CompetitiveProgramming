#include <iostream>
#include <vector>

using namespace std;

#define lli long long int

int main() {
  int t;
  cin >> t;

  while (t--) {
    lli a, b, c;
    cin >> a >> b >> c;

    if (c != (a + 1)) {
      cout << -1 << endl;
      continue;
    }

    int height = 0;
    int slots_in_this_height = 1;
    int slots_in_next_height = 0;

    while (a > 0 && slots_in_this_height > 0){
        a--;
        slots_in_next_height += 2;
        slots_in_this_height -= 1;

        if (slots_in_this_height == 0){
            slots_in_this_height = slots_in_next_height;
            slots_in_next_height = 0;
            height++;
        }
    }
    while (b > 0 && slots_in_this_height > 0){
        b--;
        slots_in_next_height += 1;
        slots_in_this_height -= 1;

        if (slots_in_this_height == 0){
            slots_in_this_height = slots_in_next_height;
            slots_in_next_height = 0;
            height++;
        }
    }
    if (c > slots_in_this_height){
        height++;
    }

    //cout << "---> ";
    cout << height << endl;

  }
}
