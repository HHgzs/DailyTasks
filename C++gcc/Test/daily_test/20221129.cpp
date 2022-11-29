#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, num;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        s.insert(num);
    }
    for (auto& it : s)
        cout << it << " ";
}







#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n,q,key,t,x;
    cin >> n>>q;
    vector<stack<int>> v;
    v.resize(n);
    for(int i = 0 ; i < q; i++)
    {
        cin >> key >> t;
        switch(key)
        {
            case 0:
            cin >> x;
            v[t].push(x);
            break;

            case 1:
            cout << v[t].top() << endl;
            break;

            case 2:
            v[t].pop();
            break;
        }

    }
}






#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
    int n, q, key, t, x, t1;
    cin >> n >> q;
    vector<list<int>> v;
    v.resize(n);
    for (int i = 0; i < q; i++)
    {
        cin >> key >> t;
        switch (key)
        {
        case 0:
            cin >> x;
            v[t].push_back(x);
            break;

        case 1:
            for (auto it : v[t])
                cout << it << " ";
            cout << endl;
            break;

        case 2:
        cin >> t1;
            v[t1].merge(v[t]);
            break;
        }
    }
}