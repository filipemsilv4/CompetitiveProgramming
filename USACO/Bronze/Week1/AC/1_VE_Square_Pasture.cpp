#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main(){
    vector<int> a(4);
    vector<int> b(4);
    vector<int> c(4);

    for (int i = 0; i < 4; i++)
        cin >> a[i];

    for (int i = 0; i < 4; i++)
        cin >> b[i];

    for (int i = 0; i < 2; i++)
        c[i] = min(a[i], b[i]);
    for (int i = 2; i < 4; i++)
        c[i] = max(a[i], b[i]);

    int side = max(abs(c[0] - c[2]), abs(c[1] - c[3]));

    cout << side * side << endl;
}
