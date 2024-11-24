#include<iostream>
using namespace std;

const int len = 5, max_spec = 20;

struct hospital_queue
{
    string name[len];
    int status[len], c, spec;
    hospital_queue()
    {
        c = 0;
    }
    hospital_queue(int sp)
    {
        spec = sp;
    }
    bool add_back(string n, int st)
    {
        if(c == len) return false;
        name[c] = n;
        status[c] = st;
        ++c;
        return true;
    }
    bool add_front(string n,int st)
    {
        if(c == len) return false;
        for(int i = c; i > 0; --i)
        {
            name[i] = name[i - 1];
            status[i] = status[i - 1];
        }
        name[0] = n;
        status[0] = st;
        c++;
        return true;
    }

    void remove_front()
    {
        if(c == 0) cout << "No patients at the moment.\n";
        else
        {
            string x = name[0];
            for(int i = 0; i < c - 1; ++i)
            {
                name[i] = name[i + 1];
            }
            cout << endl << x << "Please go with the doctor." << endl;
            --c;
        }
    }

    void print()
    {
        cout << "There are " << c << " in specialization " << spec << ".\n";
        for(int i = 0; i < c; ++i)
        {
            cout << name[i] << " ";
            if(status[i] == 0) cout << "regular\n";
            else cout << "urgent\n";
        }
    }

};

struct hospital_system
{
    hospital_queue q[20];

    hospital_system()
    {
        for(int i = 0; i < max_spec; ++i)
            q[i] = hospital_queue(i);
    }

    bool add_patient()
    {
        string n;
        int st, spec;
        cout << "Enter your name, specialization and status\n";
        cin >> n >> spec >> st;
        bool status;
        if(st == 0)
            status = q[spec].add_back(n, st);
        else status = q[spec].add_front(n, st);
        if(!status)
        {
            cout << "Sorry we can't add more patients.\n";
            return false;
        }
        return true;
    }
    void get_next()
    {
        int sp;
        cout << "Enter specialization\n";
        cin >> sp;
        q[sp].remove_front();
    }
    void print_patients()
    {
        for(int i = 0; i < max_spec; ++i)
        {
            if(q[i].c > 0)
                q[i].print();
        }
    }
    int menue()
    {
        int c = -1;
        while(c == -1)
        {
            cout << "\nPlease Enter your choice\n";
            cout << "1 - Add new patients.\n";
            cout << "2 - print all patients.\n";
            cout << "3 - Get next patient.\n";
            cout << "4 - Exit.\n";
            cin >> c;
            if(c > 4 && c < 1)
            {
                cout << "Invalide choice, Please try again.\n";
                c = -1;
            }
        }
        return c;
    }
    void run()
    {
        while(true)
        {
            int choice = menue();
            if(choice == 1)
                add_patient();
            else if(choice == 2)
                print_patients();
            else if(choice == 3)
                get_next();
            else
                break;
        }
    }
};

int main()
{
    hospital_system hospital;
    hospital.run();
    return 0;
}
