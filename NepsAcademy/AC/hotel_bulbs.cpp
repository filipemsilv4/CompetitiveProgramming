//AC
#include <iostream>

using namespace std;

int main(){
    bool ia, ib, fa, fb;
    cin >> ia >> ib >> fa >> fb;

    if (ia == fa && ib == fb) { cout << 0 << endl; }
    else if (ia == !fa && ib == !fb) { cout << 1 << endl; }
    else if (ia == !fa && ib == fb) { cout << 1 << endl; }
    else cout << 2 << endl;
}