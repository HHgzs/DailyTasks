#include <bits/stdc++.h>
using namespace std;

string getDescription()
{
    int minutes = 100;
    string str("You're riding for ");
    str.append(to_string(minutes));
    str.append(" minute(s)");
    return str;
}
int main()
{
    // map<int, int> m;
    // m.insert(pair<int,int>(0, 123));
    // m.insert(pair<int,int>(1, 234));
    // m.insert(pair<int,int>(2, 345));
    // map<int, int>::iterator it;
    // it = m.find(2);
    // cout << it->second;
    vector<vector<bool>> c_exist;
    c_exist.resize(6);
    for (int i = 0; i <= 5; i++)
        c_exist[i].resize(6);
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            cout << c_exist[i][j];
}