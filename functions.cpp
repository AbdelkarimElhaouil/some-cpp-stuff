#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

void set_array(int arr[],int len = 5, int m = 2)
{
    for(int i = 0; i < len; i++)
    {
        if(i == 0) arr[i] = 1;
        else
            arr[i] = m * arr[i-1];
    }

}

string reverse_str(const string &str)
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

bool is_prime(int n)
{
    int c = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(n % i == 0) c++;
    }
    return c == 2;
}

int nth_prime(int n)
{
    int p, i = 1;
    while(n)
    {
        if(is_prime(i)) p = i, n--;
        ++i;
    }
    return p;
}

bool start_with(string inp, string pat, int pos)
{
    int p = pat.size();
    if(pos == 0 || pos - 1>= inp.size()) return false;
    pos--;
    for(int j = 0; j < p; ++j)
    {
        if(inp[pos + j] == inp.size()) break;
        if(inp[pos + j] != pat[j]) return false;
    }
    return true;
}

string replace_str(string inp, string pat, string to)
{
    int ins = inp.size(), pas = pat.size();
    string str;
    for(int i = 0; i < ins; ++i)
    {
        if(start_with(inp, pat, i+1))
        {
            for(int j = 0; j < to.size(); ++j)
            {
                str.push_back(to[j]);
            }
            i += pas - 1;
        }
        else str.push_back(inp[i]);
    }
    return str;
}

