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

int priority(char ope_)
{
    if (ope_ == '+' || ope_ == '-')
        return 1;
    else if (ope_ == '*' || ope_ == '/')
        return 2;
    else
        return 0;
}

void calculate(stack<char> &Ope, stack<int> &Num)
{
    double a, b;
    a = Num.top();
    Num.pop();
    b = Num.top();
    Num.pop();

    if (Ope.top() == '+')
        Num.push(b + a);
    else if (Ope.top() == '-')
        Num.push(b - a);
    else if (Ope.top() == '*')
        Num.push(b * a);
    else if (Ope.top() == '/')
            Num.push(b / a);
    Ope.pop();

}

bool inStack(deque<int> num, deque<char> opt)
{
    stack<char> Ope;
    char ope_;
    stack<int> Num;
    int num_;

    while (1)
    {
        num_ = num.front();
        num.pop_front();
        ope_ = opt.front();
        opt.pop_front();
        Num.push(num_);

        if (ope_ == '=')
        {
            while (!Ope.empty())
                calculate(Ope, Num);
            if (Num.top() == 24)
                return 1;
            else
                return 0;
        }
        else if (Ope.empty())
            Ope.push(ope_);
        else if (priority(Ope.top()) >= priority(ope_))
        {
            calculate(Ope, Num);
            return 0;
            Ope.push(ope_);
        }
        else
            Ope.push(ope_);
    }
}

void perm_opt(int times, char opters[], vector<deque<char>> &opt, deque<char> opt_temp)
{
    if (times)
    {
        for (int i = 0; i < 4; i++)
        {
            opt_temp.push_back(opters[i]);
            perm_opt(times - 1, opters, opt, opt_temp);
            opt_temp.pop_back();
        }
    }
    else
    {
        opt.push_back(opt_temp);
        while (!opt_temp.empty())
            opt_temp.pop_back();
        return;
    }
}

void output_nums(int end, vector<deque<int>> &num, vector<int> numbers)
{
    deque<int> num1;
    for (int i = 0; i <= end; i++)
        num1.push_back(numbers[i]);
    num.push_back(num1);
}

void perm_num(int begin, int end, vector<deque<int>> &num, vector<int> numbers)
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

void print_opt(vector<deque<char>> opt)
{
    for (int i = 0; i < opt.size(); i++)
    {
        int m2 = opt[i].size();
        for (int j = 0; j < m2; j++)
        {
            cout << opt[i].back() << " ";
            opt[i].pop_back();
        }
        cout << endl;
    }
}
void print_num(vector<deque<int>> num)
{
    for (int i = 0; i < num.size(); i++)
    {
        int m2 = num[i].size();
        for (int j = 0; j < m2; j++)
        {
            cout << num[i].back() << " ";
            num[i].pop_back();
        }
        cout << endl;
    }
}

void display_line(deque<int> num, deque<char> opt)
{
    int siz = num.size();
    string str;
    deque<char> opt2 = opt;
    deque<int> num2 = num;
    while (siz--)
    {
        str.append(to_string(num2.front()));
        num2.pop_front();
        if (siz >= 1)
        {
            str.push_back(opt2.front());
            opt2.pop_front();
        }
    }
    cout << str << endl;
    calcu::count++;
}

void display(vector<deque<int>> num, vector<deque<char>> opt)
{
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < opt.size(); j++)
        {
            opt[j].push_back('=');
            if (inStack(num[i], opt[j]))
            {
                display_line(num[i], opt[j]);
            }
        }
    }
}

int calcu::count = 0;

int main()
{
    int n;
    vector<int> numbers;
    deque<char> opt_temp;
    vector<deque<int>> num;
    vector<deque<char>> opt;

    char opters[4] = {'+', '-', '*', '/'};
    cin >> n;
    numbers.resize(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    perm_num(0, n - 1, num, numbers);
    set<deque<int>> s1(num.begin(), num.end());
    num.assign(s1.begin(), s1.end());

    perm_opt(n - 1, opters, opt, opt_temp);
    set<deque<char>> s2(opt.begin(), opt.end());
    opt.assign(s2.begin(), s2.end());

    display(num, opt);
    cout << calcu::count;
}
