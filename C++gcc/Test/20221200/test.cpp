#include <bits/stdc++.h>
using namespace std;

// string getDescription()
// {
//     int minutes = 100;
//     string str("You're riding for ");
//     str.append(to_string(minutes));
//     str.append(" minute(s)");
//     return str;
// }
// int main()
// {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

//     // map<int, int> m;
//     // m.insert(pair<int,int>(0, 123));
//     // m.insert(pair<int,int>(1, 234));
//     // m.insert(pair<int,int>(2, 345));
//     // map<int, int>::iterator it;
//     // it = m.find(2);
//     // cout << it->second;
//     vector<vector<bool>> c_exist;
//     c_exist.resize(6);
//     for (int i = 0; i <= 5; i++)
//         c_exist[i].resize(6);
//     for (int i = 0; i < 6; i++)
//         for (int j = 0; j < 6; j++)
//             cout << c_exist[i][j];
// }

// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <stack>
// #include <map>
// using namespace std;

// stack<int> Num;
// stack<char> Ope;
// map<char, int> operat;

// float calculate(float a, float b, char c)
// {
//     if (c == '+')
//     {
//         return a + b;
//     }
//     if (c == '-')
//     {
//         return a - b;
//     }
//     if (c == '*')
//     {
//         return a * b;
//     }
//     if (c == '/')
//     {
//         return a / b;
//     }
//     else
//         return 0;
// }

// int main()
// {
//     operat.insert(make_pair('+', 1));
//     operat.insert(make_pair('-', 1));
//     operat.insert(make_pair('*', 2));
//     operat.insert(make_pair('/', 2)); // 分配优先级

//     // char input[200];
//     string input;
//     while (cin >> input)
//     {
//         float temp;
//         for (int i = 0; i < input.size(); i++)
//         {
//             while ((input[i] >= '0' && input[i] <= '9') && i < input.size())
//             {
//                 if (i == 0)
//                 {
//                     temp = input[i] - '0';
//                 }
//                 else
//                 {
//                     temp = temp * 10 + input[i] - '0';
//                 }
//                 i++;
//             }

//             if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
//             {
//                 if (Ope.empty())
//                 {
//                     Ope.push(input[i]);
//                 }
//                 else if (operat[Ope.top()] <= operat[input[i]])
//                 {
//                     Ope.push(input[i]);
//                 }
//                 else
//                 {
//                     float a, b;
//                     while (operat[Ope.top()] > operat[input[i]])
//                     {
//                         b = Num.top();
//                         Num.pop();
//                         a = Num.top();
//                         Num.pop();
//                         Num.push(calculate(a, b, input[i]));
//                         Ope.pop();
//                     }
//                     Ope.push(input[i]);
//                 }
//             }
//         }
//         while (!Ope.empty() && Num.size() > 1)
//         {
//             float a, b;
//             b = Num.top();
//             Num.pop();
//             a = Num.top();
//             Num.pop();
//             Num.push(calculate(a, b, Ope.top()));
//             Ope.pop();
//         }
//         cout << fixed << setprecision(2) << Num.top() << endl;
//     }
//     return 0;
// }