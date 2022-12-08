
//calculator

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    char ch;
    string line;

    while (getline(cin, line), line != "0")
    {
        double temp_num = 0, sum = 0, temp1, temp2;
        stack<double> num;
        stack<char> opt;

        for (int il = 0; il < line.length(); il++)
        {
            ch = line[il];
            if (ch == 43 || ch == 45 || ch == 42 || ch == 47)
            {
                opt.push(ch);
            }
            else if (ch < 58 && ch > 47)
            {
                temp_num = temp_num * 10 + static_cast<double>(ch - 48);
            }
            else
            {
                if (temp_num != 0)
                    num.push(temp_num);
                temp_num = 0;
            }
            if (temp_num != 0 && il == line.length() - 1)
                num.push(temp_num);
        }

        while (!opt.empty())
        {
            if (opt.top() == '/')
            {
                temp1 = num.top();
                num.pop();
                temp2 = num.top() / temp1;
                num.pop();
                num.push(temp2);
            }
            else if (opt.top() == '*')
            {
                temp1 = num.top();
                num.pop();
                temp2 = num.top() * temp1;
                num.pop();
                num.push(temp2);
            }
            else if (opt.top() == '+')
            {
                sum += num.top();
                num.pop();
            }
            else if (opt.top() == '-')
            {
                sum -= num.top();
                num.pop();
            }

            if (opt.size() == 1)
            {
                sum += num.top();
                num.pop();
            }
            opt.pop();
        }

        cout << fixed << setprecision(2) << sum << endl;
    }
}
