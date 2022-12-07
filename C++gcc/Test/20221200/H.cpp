#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    vector<char> number;
    for (int i = 0; i < 5; i++)
        number.push_back(i);
    int size = number.size();
    for (int i = size - 1; i >= 0; i--)
    {
        str.push_back(number[i] + '0');
    }
    const char *p_char = str.c_str();
    cout << p_char;
}

// #include <bits/stdc++.h>
// using namespace std;
// const char *getnum()
// {
//     string str;
//     vector<char> number;
//     for (int i = 0; i < 5; i++)
//         number.push_back(i);

//     int size = number.size();
//     for (int i = size - 1; i <= 0; i--)
//         str.push_back(number[i] + '0');
//     const char *p_char = str.c_str();
//     return p_char;
// }
// int main()
// {
//     const char* p = getnum();
//     cout << p;
// }