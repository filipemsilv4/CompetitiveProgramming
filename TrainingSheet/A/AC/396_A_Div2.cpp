#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    int ans = -1;

    if (a != b){
        ans = max(a.size(), b.size());
    }

    cout << ans << endl;

}
