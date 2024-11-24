#include <iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

int max(int a, int b, int c){return max(max(a, b), c);}
int max(int a, int b, int c, int d){return max(max(a, b, c), d);}
int max(int a, int b, int c, int d, int e){return max(max(a, b, c, d), e);}
int max(int a, int b, int c, int d, int e, int f){return max(max(a, b, c, d, e), f);}

string reverse_s(const string &str)
{
    string s = str;
    int c = str.size();
    for(int i = 0; i < c/2; ++i)
    {
        char temp = s[i];
        s[i] = s[c - 1 - i];
        s[c - 1 - i] = temp;
    }
    return s;
}

int c = 0;
int menu()
{
   int n;
   while(true)
   {
        cout << "Enter your operation number:\n";
        cout << "-1 for division\n";
        cout << "-2 for multiplication\n";
        cout << "-3 for substraction\n";
        cout << "-4 for addition\n";
        cout << "-5 for exit\n";
        cin >> n;
        if( n > 5)
            cout << "Invalide number, Please try again\n";
        else break;
   }
   return n;
}
void div(const double &a, const double &b){
    if(b == 0) cout << "Math error, can't divide by zero.\n";
    else
        {
            cout << a << " / " << b << " = " << a / b;
            c++;
        }
    }
void add(const double &a, const double &b) {
    cout << a << " + " << b << " = " << a + b;
    c++;
    }
void mul(const double &a, const double &b)
    {
        cout << a << " * " << b << " = " << a * b;
        c++;
    }
void sub(const double &a, const double &b)
    {
        cout << a << " - " << b << " = " << a - b;
        c++;
    }
void operation(double &a, double &b)
{
    while(true)
    {
        int choice = menu();
        if(choice == 5)
        {
            cout << "The number of operation you done is: " << c << endl;
            break;
        }
        cout << "Please Enter two numbers: ";
        cin >> a >> b;
        if(choice == 1) div(a, b);
        else if(choice == 2) mul(a, b);
        else if(choice == 3) sub(a, b);
        else add(a, b);
        cout << endl;
    }
}



