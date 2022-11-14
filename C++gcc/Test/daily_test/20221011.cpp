
#include <iostream>
using namespace std;
void search(string c_string, char key)
{
    bool yes_or_no = 0;
    for (int i = 0; i < c_string.length(); i++)
    {
        if (c_string[i] == key)
            yes_or_no = 1;
    }

    if (yes_or_no == 1)
        cout << "Yes";
    else
        cout << "No";
}

int main()
{
    string word;
    char key;
    cin >> word >> key;
    search(word, key);
}

#include <iostream>
using namespace std;
void find_and_change(char get_in)
{
    if (get_in < 'E')
        get_in = 'W' + get_in - 'A';
    else
        get_in -= 4;
    cout << get_in;
}
int main()
{
    string words;
    cin >> words;
    for (int i = 0; i < words.length(); i++)
    {
        find_and_change(words[i]);
    }
}




#include <iostream>
using namespace std;
int main()
{
    int A[10000];
    int n;
    int *p = A;
    cin >> n;
    for (int i = 0; i < (n * n * 2); i++)
    {
        cin >> *(p + i);
        if (i >= (n * n))
            *(p - n * n + i) += *(p + i);
    }
    for (int i = 0; i < n * n; i++)
    {
        cout << *(p + i) << " ";
        if ((i + 1) % n == 0)
            cout << endl;
    }
}




#include <iostream>
using namespace std;
int main()
{
    int A[10000];
    int n;
    cin >> n;
    for (int i = 0; i < (n * n * 2); i++)
    {
        cin >> A[i];
        if (i >= (n * n))
            A[i - n * n] += A[i];
    }
    for (int i = 0; i < n * n; i++)
    {
        cout << A[i] << " ";
        if ((i + 1) % n == 0)
            cout << endl;
    }
}