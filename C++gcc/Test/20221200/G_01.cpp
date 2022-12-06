#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

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

void output_opt(int end, char opters[], int &times, stack<double> num, stack<char> opt, vector<int> opt_select)
{
    if (times--)
    {
        for (int i = 0; i < 4; i++)
        {
            opt.push(opters[i]);
            output_opt(end, opters, times, num, opt, opt_select);
        }
    }
    else
    {
        if (calculate(num, opt))
        {
            string str;
            for (int j = 0; j <= end; j++)
            {
                str.append(to_string(num.top()));
                num.pop();
                if (!opt.empty())
                {
                    str.push_back(opt.top());
                    opt.pop();
                }
                reverse(str.begin(), str.end());
                cout << str << endl;
            }
        }
    }
}

void output_nums(int end, char opters[], vector<int> numbers)
{
    stack<double> num;
    stack<char> opt;
    vector<int> opt_select;
    int times = end;
    while (!num.empty())
        num.pop();
    for (int i = 0; i <= end; i++)
    {
        num.push(numbers[numbers[i]]);
    }
    output_opt(end, opters, times, num, opt, opt_select);
}

void permutate(int begin, int end, char opters[], vector<int> numbers)
{
    if (begin == end)
    {
        output_nums(end, opters, numbers);
        return;
    }
    for (int i = begin; i <= end; i++)
    {
        swap(numbers[begin], numbers[i]);
        permutate(begin + 1, end, opters, numbers);
        swap(numbers[begin], numbers[i]);
    }
}

int main()
{
    int n;
    vector<int> numbers;
    stack<double> num;
    stack<char> opt;
    char opters[4] = {'+', '-', '*', '/'};
    cin >> n;
    numbers.resize(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    permutate(0, n - 1, opters, numbers);
}
