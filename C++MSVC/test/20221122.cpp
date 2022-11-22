#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, a, x;
    cin >> n;
    vector<int> v(1,1);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a >> x;
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