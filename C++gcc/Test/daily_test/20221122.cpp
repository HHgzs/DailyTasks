#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, a, x;
    cin >> n;
    vector<long long> v;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a != 2)
            cin >> x;
        switch (a)
        {
        case 0:
            v.push_back(x);
            break;
        case 1:
            cout << v[x] << endl;
            break;
        case 2:
            v.pop_back();
            break;
        }
    }
}





#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int nv, nt, a, t;
    cin >> nv>> nt;
    long long x;
    vector<vector<long long>> vec;
    vec.resize(nv);
    for (int i = 0; i < nt; i++)
    {
        cin >> a >> t;
        switch (a)
        {
        case 0:
            cin >> x;
            vec[t].push_back(x);
            break;
        case 1:
            for (int j = 0; j < vec[t].size(); j++)
                cout << vec[t][j] << " ";
                cout << endl;
            break;
        case 2:
            vec[t].clear();
            break;
        }
    }
}
