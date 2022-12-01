// #include <iostream>
// #include <queue>
// #include <stack>
// using namespace std;

// int main()
// {
//     int m, n, num;
//     string key;
//     cin >> m;
//     while (m--)
//     {
//         cin >> n;
//         queue<int> q;
//         stack<int> s;
//         while (n--)
//         {
//             cin >> key;
//             if (key == "push")
//             {
//                 cin >> num;
//                 q.push(num);
//                 s.push(num);
//             }
//             else if (key == "pop")
//             {
//                 if (q.empty())
//                     cout << "error" << endl;
//                 else
//                     q.pop();
//                 if (s.empty())
//                     cout << "error" << endl;
//                 else
//                     s.pop();
//             }
//         }

//         int size = q.size();
//         for (int i = 0; i < size; i++)
//         {
//             cout << q.front() << " ";
//             q.push(q.front());
//             q.pop();
//         }
//         cout << endl;

//         size = s.size();
//         stack<int> s2;
//         for (int i = 0; i < size; i++)
//         {
//             s2.push(s.top());
//             s.pop();
//         }
//         for (int i = 0; i < size; i++)
//         {
//             cout << s2.top() << " ";
//             s2.pop();
//         }
//         cout << endl;
//     }
// }

// #include <iostream>
// #include <stdio.h>
// using namespace std;
// int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// int main()
// {
//     int a, b, c, n;
//     cin >> n;
//     while (n--)
//     {
//         scanf("%d/%d/%d", &a, &b, &c);
//         if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
//             month[2] = 29;
//         else
//             month[2] = 28;
//         int sum = 0;
//         for (int i = 1; i < b; i++)
//             sum += month[i];
//         sum += c;
//         cout << sum << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// bool is_triangle(int a, int b, int c)
// {
//     if ((a + b) > c)
//         return 1;
//     else
//         return 0;
// }

// int main()
// {
//     int n, a, sum;
//     vector<int> v;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a;
//         v.push_back(a);
//     }
//     sort(v.begin(), v.end());
//     for (int i = 0; i < n - 2; i++)
//     {
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                 if ((v[i] + v[j]) > v[k])
//                     sum++;
//             }
//         }
//     }
//     cout << sum;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int a[1010];
// int main()
// {
//     ios::sync_with_stdio(false);
//     int n, tmp, tip = 0;
//     cin >> n;
//     while (n--)
//     {
//         cin >> tmp;
//         if (tmp)
//             a[++tip] = tmp;
//     }
//     long long sum = 0;
//     for (int i = 1; i <= tip - 2; i++)
//         for (int j = i + 1; j <= tip - 1; j++)
//             for (int k = j + 1; k <= tip; k++)
//                 if ((a[i] + a[j] > a[k]) && (a[j] + a[k] > a[i]) && (a[i] + a[k] > a[j]))
//                     sum++;
//     cout << sum;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// void merge_array(int array[], int first, int mid, int last, int temp[]) //归并排序中的归并，即将一个数组排好序的两部分合并到一起
// {
//     int i = first, j = mid + 1, k = 0;
//     while (i <= mid && j <= last)
//     {
//         if (array[i] <= array[j])
//         {
//             temp[k++] = array[i++];
//         }
//         else
//         {
//             temp[k++] = array[j++];
//         }
//     }
//     while (i <= mid)
//     {
//         temp[k++] = array[i++];
//     }
//     while (j <= last)
//     {
//         temp[k++] = array[j++];
//     }
//     for (int i = 0; i < k; i++)
//         array[first + i] = temp[i];
// }

// void merge_sort(int data[], int first, int last, int temp[]) //归并排序，对数组元素进行排序
// {
//     if (first < last)
//     {
//         int mid = (first + last) / 2;
//         merge_sort(data, first, mid, temp);
//         merge_sort(data, mid + 1, last, temp);
//         merge_array(data, first, mid, last, temp);
//     }
// }

// int main()
// {
//     int n, count = 0;
//     cin >> n;
//     if (n < 3)
//         return 0;
//     int a[n], temp[n];
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     merge_sort(a, 0, n - 1, temp);
//     for (int i = 0; i < n - 2; i++)
//     {
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                 if (a[i] > 0 && a[i] + a[j] > a[k])
//                 {
//                     count++;
//                 }
//                 else
//                     break;
//             }
//         }
//     }
//     cout << count << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
// #include <string>
// using namespace std;

// bool compares(vector<int> a, vector<int> b)
// {
//     if (a[4] != b[4])
//         return a[4] > b[4];
//     else
//     {
//         if (a[1] != b[1])
//             return a[1] > b[1];
//         else
//         {
//             if (a[2] != b[2])
//                 return a[2] > b[2];
//             else
//                 return a[3] > b[3];
//         }
//     }
// }

// int main()
// {
//     int n, a, b, c, d;
//     string s1, s2;
//     cin >> n;
//     vector<vector<int>> v1;
//     vector<vector<string>> v2;
//     v1.resize(n);
//     v2.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> s1 >> s2 >> a >> b >> c;
//         v2[i].push_back(s1);
//         v2[i].push_back(s2);
//         v1[i].push_back(i);
//         v1[i].push_back(a);
//         v1[i].push_back(b);
//         v1[i].push_back(c);
//         v1[i].push_back(v1[i][1] + v1[i][2] + v1[i][3]);
//     }
//     sort(v1.begin(), v1.end(), compares);
//     for (int i = 0; i < 5; i++)
//     {
//         cout << v2[v1[i][0]][0] << " " << v2[v1[i][0]][1] << " " << v1[i][4] << endl;
//     }
// }

// #include <iostream>
// #include <cmath>
// using namespace std;

// bool is_prime(int i)
// {
//     for (int j = 2; j <= static_cast<int>(sqrt(i)); j++)
//     {
//         if (i % j == 0)
//             return 0;
//     }
//     return 1;
// }
// int main()
// {
//     long long N, sum = 2, sum2 = 0;
//     int n18 = 0, n0 = 1;
//     cin >> N;
//     for (int i = 3; i <= N; i += 2)
//     {
//         if (is_prime(i))
//             sum += i;
//     if (sum >= 1000000000000000000)
//     {
//         sum -= 1000000000000000000;
//         n18++;
//     }
// }
// sum2 = sum;
// while (sum)
// {
//     n0++;
//     sum /= 10;
// }

// if (n18)
// {
//     for (int i = 0; i < (18 - n0); i++)
//         cout << 0;
// }
//     cout << sum;
// }

// #include <iostream>
// #include <cmath>
// #include <vector>
// using namespace std;

// bool is_prime(int i,vector<int>& v)
// {
//     for (int j = 0; j<v.size(); j++)
//     {
//         if (i % v[j] == 0)
//             return 0;
//     }
//     v.push_back(i);
//     return 1;
// }

// int main()
// {
//     unsigned long long N, sum = 2;
//     int n18 = 0, n0 = 1;
//     cin >> N;
//     vector<int> v(1,2);

//     for (int i = 3; i <= N; i += 2)
//     {
//         if (is_prime(i,v))
//             sum += i;
//     }
//     cout << sum;
// }

// #include <iostream>
// #include <cmath>
// #include <iostream>
// using namespace std;
// bool is_prime(int n) // bool函数，只会返回真(true)[不等于0]或者假(false)[等于0]
// {
//     if (n == 2 || n == 3)         //先判断小于5的素数
//         return true;              //返回真
//     if (n % 6 != 5 && n % 6 != 1) //去掉不在6周围的情况
//         return false;
//     int cmb = (int)sqrt(n); //强制转换成int型，返回值问题详细可见我的另外一篇博客
//     for (int i = 5; i <= cmb; i += 6)
//     {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false; //返回假
//     }
//     return true; //去掉所有不满足的情况，就是满足的情况
// }
// int main()
// {
//     int N;
//     unsigned long long sum = 0;
//     cin >> N;

//     for (int n = 7; n <= N; n++)
//     {
//         if (is_prime(n))
//             sum += n;
//     }
//     cout << sum;
// }

// #include <vector>
// #include <cmath>
// #include <iostream>
// using namespace std;
// bool is_prime(int n)
// {
//     if (n == 2 || n == 3)
//         return true;
//     if (n % 6 != 5 && n % 6 != 1)
//         return false;
//     int sqrt_num = (int)sqrt(n);
//     for (int i = 5; i <= sqrt_num; i += 6)
//     {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;
// }
// int main()
// {
//     int N;
//     vector<int> v(1, 2);
//     unsigned long long sum = 0;
//     cin >> N;

//     for (int n = 2; n <= N; n++)
//     {
//         if (is_prime(n))
//         {
//             sum += n;
//             v.push_back(n);
//         }
//     }
//     cout << sum;
// }

// #include <iostream>
// #include <cmath>
// #include <vector>
// using namespace std;

// bool is_prime(int i, vector<int> &v)
// {
//     int sqrts = (int)sqrt(i);
//     for (int j = 0; j < v.size() && v[j] <= sqrts; j++)
//         if (i % v[j] == 0)
//             return 0;
//     v.push_back(i);
//     return 1;
// }

// int main()
// {
//     unsigned long long N, sum = 2;
//     int n18 = 0, n0 = 1;
//     cin >> N;
//     vector<int> v(1, 2);

//     for (int i = 3; i <= N; i += 2)
//     {
//         if (is_prime(i, v))
//             sum += i;
//     }
//     cout << sum;
// }

// #include <iostream>
// #include <string>
// #include <stack>
// using namespace std;

// void calculator(string str)
// {
//     string::iterator it = str.begin(); //迭代器
//     stack<char> s1;                    // s1是用来存放运算符的栈
//     stack<int> s2;                     // s3是用来存放数字的栈
//     while (it != str.end())
//     {
//         //运算符优先级：) > *、/、% > +、- > ( 且 ( 特例，直接入栈
//         if (*it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == '%' || *it == '(')
//         {
//             //当遇到栈顶为 *、/、% 读取的字符为 +、- 时，即读取的运算符优先级低于符号栈顶元素优先级
//             //或
//             //当遇到栈顶为 *、/、% 读取的字符为*、/、%时，即读取的运算符优先级等于符号栈顶元素优先级时
//             if (!s1.empty() && (s1.top() == '*' || s1.top() == '/' || s1.top() == '%') && *it != '(')
//             { //注意这里要加上栈判空，否则会导致开始的时候出错
//                 int num2 = s2.top();
//                 s2.pop();
//                 int num1 = s2.top();
//                 s2.pop();
//                 if (s1.top() == '*')
//                 {
//                     s2.push(num1 * num2);
//                 }
//                 else if (s1.top() == '/')
//                 {
//                     s2.push(num1 / num2);
//                 }
//                 else
//                 {
//                     s2.push(num1 % num2);
//                 }
//                 s1.pop();
//                 s1.push(*it);
//             }
//             //当遇到栈顶为 +、- 读取的字符为 +、- 时，即读取的运算符优先级等于符号栈顶元素优先级
//             else if (!s1.empty() && (s1.top() == '+' || s1.top() == '-') && (*it == '+' || *it == '-'))
//             { //注意这里要在前面加栈的判空，否则会导致开始的时候出错
//                 int num2 = s2.top();
//                 s2.pop();
//                 int num1 = s2.top();
//                 s2.pop();
//                 if (s1.top() == '+')
//                 {
//                     s2.push(num1 + num2);
//                 }
//                 else
//                 {
//                     s2.push(num1 - num2);
//                 }
//                 s1.pop();
//                 s1.push(*it);
//             }
//             //当遇到栈顶为 +、- 读取的字符为 *、/、% 时，即读取的运算符优先级高于符号栈顶元素优先级
//             //或
//             //当遇到栈顶为 ( 读取的字符为 +、-、 *、/、% 时，即读取的运算符优先级高于符号栈顶元素优先级
//             //或
//             //读取的字符为 ( 时
//             else
//             {
//                 s1.push(*it);
//             }
//         }
//         else if (*it == ')')
//         { //匹配到右括号
//             while (s1.top() != '(')
//             {
//                 int num2 = s2.top();
//                 s2.pop();
//                 int num1 = s2.top();
//                 s2.pop();
//                 if (s1.top() == '+')
//                 {
//                     s2.push(num1 + num2);
//                 }
//                 else if (s1.top() == '-')
//                 {
//                     s2.push(num1 - num2);
//                 }
//                 else if (s1.top() == '*')
//                 {
//                     s2.push(num1 * num2);
//                 }
//                 else if (s1.top() == '/')
//                 {
//                     s2.push(num1 / num2);
//                 }
//                 else
//                 {
//                     s2.push(num1 % num2);
//                 }
//                 s1.pop();
//             }
//             s1.pop();
//         }
//         else
//         {                              //匹配到数字
//             s2.push((int)(*it - '0')); //转换为整型
//         }
//         it++;
//     }

//     //还差一步
//     int num2 = s2.top();
//     s2.pop();
//     int num1 = s2.top();
//     s2.pop();
//     if (s1.top() == '+')
//     {
//         s2.push(num1 + num2);
//     }
//     else if (s1.top() == '-')
//     {
//         s2.push(num1 - num2);
//     }
//     else if (s1.top() == '*')
//     {
//         s2.push(num1 * num2);
//     }
//     else if (s1.top() == '/')
//     {
//         s2.push(num1 / num2);
//     }
//     else
//     {
//         s2.push(num1 % num2);
//     }
//     cout << s2.top() << endl;
// }

// int main()
// {

//     string str = "(5+1)%(4/(3-2+1/2)+2)+1";
//     cout << (5 + 1) % (4 / (3 - 2 + 1 / 2) + 2) + 1 << endl;
//     calculator(str);

//     return 0;
// }

// #include <iostream>
// #include <iomanip>
// #include <vector>
// #include <string>
// #include <stack>
// using namespace std;

// int main()
// {
//     char ch;
//     string line;

//     while (getline(cin, line), line != "0")
//     {
//         double temp_num = 0, sum = 0, temp1, temp2;
//         stack<double> num;
//         stack<char> opt;

//         for (int il = 0; il < line.length(); il++)
//         {
//             ch = line[il];
//             if (ch == 43 || ch == 45 || ch == 42 || ch == 47)
//             {
//                 opt.push(ch);
//             }
//             else if (ch < 58 && ch > 47)
//             {
//                 temp_num = temp_num * 10 + static_cast<double>(ch - 48);
//             }
//             else
//             {
//                 if (temp_num != 0)
//                     num.push(temp_num);
//                 temp_num = 0;
//             }
//             if (temp_num != 0 && il == line.length() - 1)
//                 num.push(temp_num);
//         }

//         while (!opt.empty())
//         {
//             if (opt.top() == '/')
//             {
//                 temp1 = num.top();
//                 num.pop();
//                 temp2 = num.top() / temp1;
//                 num.pop();
//                 num.push(temp2);
//             }
//             else if (opt.top() == '*')
//             {

//                 temp1 = num.top();
//                 num.pop();
//                 temp2 = num.top() * temp1;
//                 num.pop();
//                 num.push(temp2);
//             }
//             else if (opt.top() == '+')
//             {
//                 sum += num.top();
//                 num.pop();
//             }
//             else if (opt.top() == '-')
//             {

//                 sum -= num.top();
//                 num.pop();
//             }

//             if (opt.size() == 1)
//             {

//                 sum += num.top();
//                 num.pop();
//             }
//             opt.pop();
//         }

//         cout << fixed << setprecision(2) << sum << endl;
//     }
// }

#include <iostream>
#include <vector>
using namespace std;

bool boom_next_next(int n, vector<int> v)
{
    for (int i2 = 1; i2 <= n; i2++)
    {
        if(v[i2]>=3)
        {
            if()
        }


    }
    for (int i3 = 1; i3 <= n - 2; i3++)
    {
        while (v[i3] > 0 && v[i3 + 1] > 0 && v[i3 + 2] > 0)
        {
            v[i3]--;
            v[i3 + 1]--;
            v[i3 + 2]--;
        }
    }
    int sum = 0;
    for (int i4 = 1; i4 <= n; i4++)
    {
        sum += v[i4];
    }
    if (sum == 0)
        return 1;
    else
        return 0;
}

bool boom_next(int add, int n, vector<int> v)
{
    if (v[add] >= 2)
        v[add] -= 2;
    else
        return 0;
    boom_next_next(n, v);
}

bool boom(int add, int n, vector<int> v)
{
    v[add]++;
    for (int i2 = 1; i2 <= n; i2++)
    {
        if (boom_next(i2, n, v))
            return 1;
    }
    return 0;
}

int main()
{
    int n, m, num;
    bool key = 0;
    cin >> n >> m;
    vector<int> v;
    v.resize(n + 1);
    for (int i = 0; i < 3 * m + 1; i++)
    {
        cin >> num;
        v[num]++;
    }
    for (int in = 1; in <= n; in++)
    {
        if (boom(in, n, v))
        {
            key = 1;
            cout << in << " ";
        }
    }
    if (!key)
        cout << "NO";
}