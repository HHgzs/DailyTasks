#include <bits/stdc++.h>
using namespace std;

int priority(char ope_)
{
    if (ope_ == '+' || ope_ == '-')
        return 1;
    else if (ope_ == '*' || ope_ == '/')
        return 2;
    else
        return 0;
}

int calculate(deque<int> Num, deque<char> Opt)
{
    int a, b;
    while (!Opt.empty())
    {
        a = Num.front();
        Num.pop_front();
        b = Num.front();
        Num.pop_front();

        if (Opt.front() == '+')
            Num.push_front(a + b);
        else if (Opt.front() == '-')
            Num.push_front(a - b);
        else if (Opt.front() == '*')
            Num.push_front(b * a);
        else if (Opt.front() == '/')
            Num.push_front(a / b);
        Opt.pop_front();
    }
    return Num.front();
}

int calcu_base(deque<int> Num, deque<char> Opt)
{
    deque<char> opt_p;
    deque<char> opt_x;
    char opt_;
    deque<int> num_p;
    deque<int> num_x;
    int num_;
    int sum = 0;
    int times = Num.size();
    while (times--)
    {
        num_ = Num.front();
        Num.push_back(num_);
        Num.pop_front();
        opt_ = Opt.front();
        Opt.push_back(opt_);
        Opt.pop_front();

        if (priority(opt_) == 1)
        {
            if (times != Num.size())
            {
                if (priority(Num.back()) == 1)
                {
                    num_p.push_back(num_);
                    opt_p.push_back(opt_);
                }
                else
                {
                    num_x.push_back(num_);
                    num_p.push_back(calculate(num_x, opt_x));
                    opt_p.push_back(opt_);
                    num_x.clear();
                    opt_x.clear();
                }
            }
            else
            {
                num_p.push_back(num_);
                opt_p.push_back(opt_);
            }
        }
        else if (priority(opt_) == 2)
        {
            num_x.push_back(num_);
            opt_x.push_back(opt_);
        }
        else
        {
            if (priority(Num.back()) == 1)
            {
                num_p.push_back(num_);
            }
            else
            {
                num_x.push_back(num_);
                num_p.push_back(calculate(num_x, opt_x));
                num_x.clear();
                opt_x.clear();
            }
        }
    }
    return calculate(num_p, opt_p);
}

int main()
{
    deque<int> num;
    deque<char> opt;
    num.push_back(1);
    num.push_back(3);
    num.push_back(4);
    num.push_back(3);
    num.push_back(1);
    opt.push_back('+');
    opt.push_back('/');
    opt.push_back('*');
    opt.push_back('-');
    opt.push_back('=');
    cout << calcu_base(num, opt);
}