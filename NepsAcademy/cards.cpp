//AC
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    int ans = A;
    
    if (A == B){
        ans = C;
    } else if (A == C){
        ans = B;
    }
    
    cout << ans << endl;
    
}