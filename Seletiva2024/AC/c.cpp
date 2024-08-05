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
    vector<lli> tem(3);
    vector<lli> precisa(3);
    for (int i = 0; i < 3; i++) cin >> tem[i];
    for (int i = 0; i < 3; i++) cin >> precisa[i];

    int diff = 0;
    int sobra = 0;

    diff = precisa[0] - tem[0];
    if (precisa[0] > tem[0]){
        tem[2] -= diff;
        tem[0] += diff;
    } else {
        sobra += abs(diff);
    }

    diff = precisa[1] - tem[1];
    if (precisa[1] > tem[1]){
        tem[2] -= diff;
        tem[1] += diff;
    } else {
        sobra += abs(diff);
    }

    // cout << "sobra: " << sobra << " | tem[2]: " << tem[2] << endl;

    if (tem[2] >= 0 && (tem[2] + sobra >= precisa[2])){
        cout << "It is a kind of magic" << endl;
        return 0;
    }
    cout << "There are no miracles in life" << endl;
}
