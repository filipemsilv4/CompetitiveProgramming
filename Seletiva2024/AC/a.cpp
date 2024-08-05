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
    int n;
    cin >> n;
    lli conv = n + 2;
    while (n--){
        string name;
        cin >> name;
        if (name.length() > 4){
            if (name[name.length() - 4] == '+'){
                conv++;
            }
        }
    }
    if (conv == 13) conv++;
    cout << conv * 100 << endl;
}
