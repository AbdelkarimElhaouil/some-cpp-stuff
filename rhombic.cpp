
void print_rhombic(int n)
{
    for (int i = 1; i < n; i+=2)
    {
        for (int j = n; j > i; j-=2)
        {
            cout << " ";
        }
        for (int k = 0; k < i; k++)
        {
            cout << "*";
        }
        cout <<"\n";
    }
     for (int i = 1; i <= n; i+=2)
     {
        for (int j = 1; j < i; j+=2)
        {
            cout << " ";
        }
        for (int k = n; k >= i; k--)
        {
            cout << "*";
        }
        cout <<"\n";
    }
}