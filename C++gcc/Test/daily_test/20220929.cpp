
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string number;
    string text = "0";
    bool key = 1;
    int total;
    char num;
    while (key)
    {
        total = 0;
        cin >> number;
        if (number == text)
        {
            key = 0;
            break;
        }
        for (int i = 0; i < number.length(); i++)
        {

            num = number[i];
            total += (int)num - 48;
        }
        cout << total << endl;
    }
    getchar();
    return 0;
}




#include <iostream>
using namespace std;
int main()
{
    int box[26];
    for (int i = 0; i < 26; i++)
        box[i] = 0;
    bool aa = 1;
    while (aa)
    {
        string word;
        cin >> word;
        string key = ".";
        int a = 0;
        for (int i = 0; i < word.length(); i++)
        {
            a = (int)(char)word[i];
            if (a == 46)
            {
                aa = 0;
                break;
            }
            else if (a < 91)
                box[a - 65] += 1;
            else
                box[a - 97] += 1;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        cout << (char)(i + 97) << " : " << box[i] << endl;
    }
    getchar();
    getchar();
    return 0;
}





#include <iostream>
using namespace std;
int main()
{
    string whole, keys;
    cin >> whole >> keys;
    int length_whole = whole.length();
    int length_keys = keys.length();
    int a = 0;
    int b = 0;
    int m;
    bool key = 1;
    bool out = 0;

    while (key)
    {
        if (b >= length_keys - 1)
        {
            key = 0;
            break;
        }
        if (whole[a] == keys[b] && b <= (length_keys - 1) )
        {
            if (b = 0)
                m = a;
            if (b = (length_keys - 1))
                out = 1;
            if (a < (length_whole - 1))
            {
                a++;
                b++;
            }
            else
            {
                a = 0;
                b++;
            }
           // cout << "Y " << a << " " << b << endl;
        }
        else if (whole[a] != keys[b])
        {
            if (a <= length_whole - 1)
            {
                a = m + 1;
                m++;
                b = 0;
                cout << "N " << a << " " << b << endl;
            }
            else
            {
                key = 0;
                break;
            }
        }
    }
    if (b = length_keys - 1 && out)
        cout << "Yes";
    else
        cout << "No";

    getchar();
    getchar();
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a>> b;
    a.append(a);
    a.append(a);
    if (a.find(b) != string::npos)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}