#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

int main()
{
    set<int> s;
    set<int> s2;
    s.insert(1);
    s.insert(2);
    s.insert(5);
    s.insert(3);
    s.insert(7);
    s.insert(5);
    s.insert(6);
    s2.insert(1);
    s2.insert(2);
    s2.insert(5);

    for (auto m : s)
    {
        cout << m << " ";
    }
    cout << endl;

    set<int>::iterator ptr = s.find(3);
    cout << *ptr << endl;
    ;

    s.erase(ptr);

    s.swap(s2);
    for (auto m : s)
    {
        cout << m << " ";
    }
    cout << endl;
    for (auto m : s2)
    {
        cout << m << " ";
    }
    cout << endl;

    s2.clear();

    set<int>::iterator p2 = s.begin();
    while (p2 != s.end())
    {
        cout << *p2 << " ";
        p2++;
    }
    cout << endl;

    vector<int> v(5, 1);
    for (auto num : v)
    {
        cout << num << " ";
    }
    cout << endl;

    map<string, int> m1;

    typedef map<int, string> M2;
    M2 m2;

    m1.insert(pair<string, int>("year", 2022));
    m1.insert(map<string, int>::value_type("month", 11));
    m1["day"] = 18;

    m2[1] = "first";
    m2[3] = "third";
    m2[2] = "second";

    map<string, int>::iterator it;
    it = m1.find("year");
    cout << it->first << " " << it->second << endl;

    map<string, int> m3;
    m3["Alice"] = 86;
    m3["Bob"] = 78;
    m3["Zip"] = 92;
    m3["Stdevn"] = 88;
    vector<pair<string, int>> vec(m3.begin(), m3.end());
    sort(vec.begin(), vec.end(), cmp);


}
