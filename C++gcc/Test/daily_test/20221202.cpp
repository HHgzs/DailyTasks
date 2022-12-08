
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

// #include <iostream>
// #include <string>
// #include <stack>
// #include <iomanip>
// using namespace std;
// const int add = 0, substract = 1, multiply = 2, divide = 3;
// int main()
// {
//     stack<double> S;
//     string str = "3 + 4";
//     int judge = add;
//     while (getline(cin, str) && str != "0")
//     {
//         double temp = 0, result = 0;
//         for (int i = 0; i < size(str); i++)
//         {
//             if (str[i] >= '0' && str[i] <= '9') // 该位上是个数字,则对该位的下一位进行讨论
//             {
//                 temp += (double)str[i] - 48;
//                 if (str[i + 1] >= '0' && str[i] <= '9') // 下一位仍然是数字
//                 {
//                     temp *= 10;
//                     continue;
//                 }
//                 if (str[i + 1] == ' ') // 下一位是一个空格，则根据运算符把temp分情况存入stack中
//                 {
//                     if (judge == add)
//                         S.push(temp);
//                     if (judge == substract)
//                         S.push(-temp);
//                     if (judge == multiply)
//                     {
//                         double temp1 = S.top();
//                         S.pop();
//                         S.push((str[i] - 48) * temp1);
//                     }
//                     if (judge == divide)
//                     {
//                         double temp1 = S.top();
//                         S.pop();
//                         S.push(temp1 / (double)(str[i] - 48));
//                     }
//                     temp = 0;
//                     continue;
//                 }
//                 if (str[i + 1] == '\0') // i已到达最后一位
//                     S.push(temp);
//                 break;
//             }
//             if (str[i] == ' ')
//                 continue; // 空格直接跳到下一次循环
//             if (str[i] == '+')
//             {
//                 judge = add;
//                 continue;
//             }
//             if (str[i] == '-')
//             {
//                 judge = substract;
//                 continue;
//             }
//             if (str[i] == '*')
//             {
//                 judge = multiply;
//                 continue;
//             }
//             if (str[i] == '/')
//             {
//                 judge = divide;
//                 continue;
//             }
//         }
//         for (int i = 0; i < S.size(); i++)
//         {
//             result += S.top();
//             S.pop();
//         }
//         cout.precision(2);
//         cout.setf(ios::fixed);
//         cout << result << endl;
//     }
// }