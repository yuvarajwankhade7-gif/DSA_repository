// Assignment 10: Create a hash table and handle collisions using linear probing

#include <iostream>
using namespace std;

int main()
{
    int a[10];

    for(int i = 0; i < 10; i++)
    {
        a[i] = -1;
    }

    int flag = 0;
    int n;

start:
    cout << "\nEnter 1 to insert element and 0 to stop inserting" << endl;
    cin >> n;

    while(n)
    {
        if(flag == 10)
        {
            cout << "Overloading";
            cout << "\nResultant hash table is:" << endl;

            for(int i = 0; i < 10; i++)
            {
                cout << "\t" << a[i] << endl;
            }

            return 0;
        }

        int k;
        cout << "\nEnter Element => ";
        cin >> k;

        int temp = k % 10;

middle:
        if(a[temp] == -1)
        {
            a[temp] = k;
            flag++;
            goto start;
        }
        else
        {
            while(a[temp] != -1 && flag != 10)
            {
                if(temp == 9)
                {
                    temp = 0;
                }
                else
                {
                    temp++;
                }

                goto middle;
            }
        }
    }

    cout << "\nResultant hash table is:" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << "\t" << i << ".  " << a[i] << endl;
    }

    return 0;
}
