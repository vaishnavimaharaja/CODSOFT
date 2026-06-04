#include<bits/stdc++.h>
using namespace std;

int main(){
    double num1, num2;  // fix: was int
    char op;

    cout << "SIMPLE CALCULATOR" << endl;

    cout << "Enter the First Number: ";
    cin >> num1;

    cout << "Enter the Second Number: ";
    cin >> num2;

    cout << "Enter The Operator (+, -, *, /): ";
    cin >> op;

    if(op == '+'){
        cout << num1 << " + " << num2 << " = " << num1+num2 << endl;
    }
    else if(op == '-'){
        cout << num1 << " - " << num2 << " = " << num1-num2 << endl;
    }
    else if(op == '*'){
        cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
    }
    else if(op == '/'){
        if(num2 == 0){
            cout << "Error! Division by zero is not allowed." << endl;
        }
        else{
            cout << num1 << " / " << num2 << " = " << num1/num2 << endl;
        }
    }
    else{
        cout << "Invalid operator! Use +, -, *, / only." << endl;
    }

    return 0;
}