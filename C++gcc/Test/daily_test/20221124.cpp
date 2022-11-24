// #include <iostream>
// #include <deque>
// using namespace std;
// int main()
// {
//     deque<long long> deq;
//     int n, key;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> key;
//         switch (key)
//         {
//         case 0:
//             int d, x;
//             cin >> d >> x;
//             if (d == 0)
//                 deq.push_front(x);
//             else if (d == 1)
//                 deq.push_back(x);
//             break;

//         case 1:
//             int p;
//             cin >> p;
//             cout << deq.at(p) << endl;
//             break;

//         case 2:
//             int e;
//             cin >> e;
//             if (e == 0)
//                 deq.pop_front();
//             else if (e == 1)
//                 deq.pop_back();
//             break;
//         }
//     }
// }

// #include <iostream>
// #include <set>
// #include <vector>
// using namespace std;

// int main()
// {
//     string name;
//     int n, id1, id2, num;
//     vector<set<int>> vec;
//     vec.resize(3);
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> name;
//         if (name == "new")
//         {
//             cin >> id1;
//         }
//         else if (name == "add")
//         {
//             cin >> id1 >> num;
//             vec[id1].insert(num);
//         }
//         else if (name == "merge")
//         {
//             cin >> id1 >> id2;
//             vec[id1].insert(vec[id2].begin(), vec[id2].end());
//             vec[id2].clear();
//         }
//         else if (name == "unique")
//         {
//             cin >> id1;
//         }
//         else if (name == "out")
//         {
//             cin >> id1;
//             set<int>::iterator it;
//             for (it = vec[id1].begin(); it != vec[id1].end(); it++)
//             {
//                 cout << *it << ' ';
//             }
//             cout << endl;
//         }
//     }
// }

#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

int main()
{
    string name;
    int n, id1, id2, num;
    vector<list<int>> vec;
    vec.resize(3);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        if (name == "new")
            cin >> id1;
        else if (name == "add")
        {
            cin >> id1 >> num;
            vec[id1].push_back(num);
        }
        else if (name == "merge")
        {
            cin >> id1 >> id2;
            vec[id1].merge(vec[id2]);
        }
        else if (name == "unique")
        {
            cin >> id1;
            set<int> s;
            list<int>::iterator it1;
            set<int>::iterator it2;
            for (it1 = vec[id1].begin(); it1 != vec[id1].end(); it1++)
                s.insert(*it1);
            vec[id1].clear();
            for (it2 = s.begin(); it2 != s.end(); it2++)
                vec[id1].push_back(*it2);
        }
        else if (name == "out")
        {
            cin >> id1;
            list<int>::iterator it3;
            vec[id1].sort();
            for (it3 = vec[id1].begin(); it3 != vec[id1].end(); it3++)
                cout << *it3 << ' ';
            cout << endl;
        }
    }
}