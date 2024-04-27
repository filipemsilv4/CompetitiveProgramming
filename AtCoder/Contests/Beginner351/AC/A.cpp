#include <iostream>

using namespace std;

#define lli long long int

int main(){
    int a = 0;

    for(int i = 1, tmp; i <= 9; i++){
        cin >> tmp;
        a+=tmp;
    }

    int b = 0;
    for (int i = 1, tmp; i <= 8; i++){
        cin >> tmp;
        b+=tmp;
    }

    int ans = 0;

    if (b <= a){
        ans = a - b + 1;
    }

    cout << ans << endl;
}
