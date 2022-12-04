#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string str0;
        cin >> str0;

        int len = str0.length();
        int num = 0;
        map<string, int> mp;

        string str = str0;
        str.append(str0);

        for (int i = 0; i < len; i++)
        {
            for (int j = 1; j <= len; j++)
            {
                string str2 = str.substr(i, j);
                if (mp[str2] == 0)
                {
                    num++;
                    mp[str2]++;
                }
            }
        }
        cout << num << endl;
    }
}