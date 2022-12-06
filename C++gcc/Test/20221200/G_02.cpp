#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

class calcu
{
public:
    static int count;
};

bool calculate(stack<double> num, stack<char> opt)
{
    double temp_num = 0, sum = 0, temp1, temp2;

    while (!opt.empty())
    {
        if (opt.top() == '/')
        {
            temp1 = num.top();
            num.pop();
            temp2 = num.top() / temp1;
            if (temp2 - (int)temp2 != 0)
                return 0;
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

    if (sum == 24)
        return 1;
    else
        return 0;
}

void perm_opt(int times, char opters[], vector<stack<char>> &opt, stack<char> opt_temp)
{
    if (times)
    {
        for (int i = 0; i < 4; i++)
        {
            opt_temp.push(opters[i]);
            perm_opt(times - 1, opters, opt, opt_temp);
            opt_temp.pop();
        }
    }
    else
    {
        opt.push_back(opt_temp);
        while (!opt_temp.empty())
            opt_temp.pop();
        return;
    }
}

void output_nums(int end, vector<stack<double>> &num, vector<int> numbers)
{
    stack<double> num1;
    for (int i = 0; i <= end; i++)
        num1.push(numbers[i]);
    num.push_back(num1);
}

void perm_num(int begin, int end, vector<stack<double>> &num, vector<int> numbers)
{
    if (begin == end)
    {
        output_nums(end, num, numbers);
        return;
    }
    for (int i = begin; i <= end; i++)
    {
        swap(numbers[begin], numbers[i]);
        perm_num(begin + 1, end, num, numbers);
        swap(numbers[begin], numbers[i]);
    }
}

void print_opt(vector<stack<char>> opt)
{
    for (int i = 0; i < opt.size(); i++)
    {
        int m2 = opt[i].size();
        for (int j = 0; j < m2; j++)
        {
            cout << opt[i].top() << " ";
            opt[i].pop();
        }
        cout << endl;
    }
}
void print_num(vector<stack<double>> num)
{
    for (int i = 0; i < num.size(); i++)
    {
        int m2 = num[i].size();
        for (int j = 0; j < m2; j++)
        {
            cout << num[i].top() << " ";
            num[i].pop();
        }
        cout << endl;
    }
}

void display_line(stack<double> num, stack<char> opt)
{
    int siz = num.size();
    string str;
    stack<char> opt2;
    stack<double> num2;
    while (!opt.empty())
    {
        opt2.push(opt.top());
        opt.pop();
    }
    while (!num.empty())
    {
        num2.push(num.top());
        num.pop();
    }
    while (siz--)
    {
        str.append(to_string(static_cast<int>(num2.top())));
        num2.pop();
        if (!opt2.empty())
        {
            str.push_back(opt2.top());
            opt2.pop();
        }
    }
    cout << str << endl;
    calcu::count++;
}

void display(vector<stack<double>> num, vector<stack<char>> opt)
{
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < opt.size(); j++)
        {
            if (calculate(num[i], opt[j]))
                display_line(num[i], opt[j]);
        }
    }
}

int calcu::count = 0;

int main()
{
    int n;
    vector<int> numbers;
    stack<char> opt_temp;
    vector<stack<double>> num;
    vector<stack<char>> opt;

    char opters[4] = {'+', '-', '*', '/'};
    cin >> n;
    numbers.resize(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    perm_num(0, n - 1, num, numbers);
    set<stack<double>> s1(num.begin(), num.end());
    num.assign(s1.begin(), s1.end());

    perm_opt(n - 1, opters, opt, opt_temp);
    set<stack<char>> s2(opt.begin(), opt.end());
    opt.assign(s2.begin(), s2.end());

    display(num, opt);
    cout << calcu::count;
}
