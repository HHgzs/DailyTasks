//#include<bits/stdc++.h>
//using namespace std;

#include<iostream>
using namespace std;
int main()
{
    bool isCovered[99];
    int number1;
    for (int i = 0; i < 99; i++)
    isCovered[i] = false;
    cin >> number1;
    while (number1 != 0)
    {
        isCovered[number1 -1] = true;
        cin >> number1;
    }
    bool all_covered = true;
    for (int i = 0; i < 99; i++)
        if (!isCovered[i])
        {
            all_covered = false;
            break;
        }
        if (all_covered)
        cout << "Cover all"<< endl;
        else 
        cout << "Not cover all"<< endl;

        system("pause");
        return 0;
}




void print_array(int list[], int array_size);
int main()
{
    int number[5] = {1,2,3,4,5};
    print_array(number, 5);
    getchar();
    return 0;
}
void print_array(int list[], int array_size)
{
    for(int i = 0; i < array_size; i++)
    {
        cout << list[i] << " ";
    }
}


