#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<char> s)
{
    // If stack is empty then return
    if (s.empty()) 
        return;
     
 
    char x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    printStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

bool closing(char c){
    return c == '}' || c == ')' || c == ']';
}

bool sameType(char a, char b){
    if (a == '{' && b == '}') return true;
    if (a == '(' && b == ')') return true;
    if (a == '[' && b == ']') return true;
    return false;
}

bool solve(){
    stack <char> expression;

    string e; cin >> e;
    for (char c : e){
        if (!expression.empty() && closing(c)){
            if (!sameType(expression.top(), c)){
                return false;
            }
            expression.pop();
            continue;
        }
        expression.push(c);
    }

    if (!expression.empty()){
        // cout << "------------------" << endl;
        // cout << "seila, olha ai: " << endl;
        // printStack(expression);
        // cout << "------------------" << endl;
        return false;
    }

    //cout << "How did we get here?" << endl;
    return true;
}


int main(){
    int T;
    cin >> T;

    for (int i = 0; i < T; i++){
        if (solve())
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }

}