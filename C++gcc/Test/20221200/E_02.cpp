#include <bits/stdc++.h>
using namespace std;
class MyInteger
{
public:
    vector<char> number;
    bool negtive;

private:
    static void simple_calc(vector<char> &, const vector<char> &, bool plus);
    static void add_at(vector<char> &number, int index, unsigned char x);
    static bool greater(const vector<char> &, const vector<char> &);

public:
    MyInteger();
    MyInteger(int);
    MyInteger(string);
    ~MyInteger();
    MyInteger &operator=(const MyInteger &);
    MyInteger &operator+=(const MyInteger &number2);
    MyInteger operator+(const MyInteger &number2);
    MyInteger operator-(const MyInteger &number2);
    MyInteger operator*(const MyInteger &number2);
    bool operator==(const MyInteger &);
    int digit_at(size_t index) const;
    friend ostream &operator<<(ostream &out, const MyInteger &num);
    const char *getnum();
};

void MyInteger::simple_calc(vector<char> &num1, const vector<char> &num2, bool plus)
{
    int size1 = num1.size();
    int size2 = num2.size();
    if (plus)
    {
        for (int i = 0; i < size2; i++)
        {
            add_at(num1, i, num2[i]);
        }
        return;
    }
    else
    {
        for (int i = 0; i < size2; i++)
        {
            num1[i] -= num2[i];
        }
        for (int i = 0; i < size1; i++)
        {
            if (num1[i] >= 0)
            {
                continue;
            }
            char temp = (9 - num1[i]) / 10;
            num1[i + 1] -= temp;
            num1[i] += temp * 10;
        }
        return;
    }
}
void MyInteger::add_at(vector<char> &number, int index, unsigned char x)
{
    if (x == 0)
    {
        return;
    }
    int size = number.size();
    if (index >= size)
    {
        number.insert(number.end(), index - size + 1, 0);
        size = index + 1;
    }
    number[index] += x;
    while (index < size && number[index] >= 10)
    {
        if (index + 1 == size)
        {
            number.emplace_back(number[index] / 10);
            size++;
        }
        else
        {
            number[index + 1] += number[index] / 10;
        }
        number[index] %= 10;
        index++;
    }
}
bool MyInteger::greater(const vector<char> &number1, const vector<char> &number2)
{
    if (number1.size() != number2.size())
    {
        return number1.size() > number2.size();
    }
    for (int i = number1.size() - 1; i >= 0; i--)
    {
        if (number1[i] != number2[i])
        {
            return number1[i] > number2[i];
        }
    }
    return false;
}

MyInteger::MyInteger()
{
    negtive = false;
    if (number.empty())
        number.emplace_back(0);
}
MyInteger::MyInteger(int num)
{
    negtive = false;
    if (num < 0)
    {
        num *= -1;
        negtive = true;
    }
    while (num)
    {
        number.emplace_back(num % 10);
        num /= 10;
    }
    while (number.back() == 0)
    {
        number.pop_back();
    }
    if (number.empty())
    {
        number.emplace_back(0);
    }
}
MyInteger::MyInteger(string str)
{
    negtive = false;
    bool cl_zero = 0;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            number.emplace_back(str[i] - '0');
        }
        else if (i == 0 && str[0] == '-')
            negtive = true;
        else
            break;
    }
    while (number.back() == 0)
    {
        number.pop_back();
    }
    if (number.empty())
    {
        number.emplace_back(0);
        negtive = false;
    }
}
MyInteger::~MyInteger() {}

int MyInteger::digit_at(size_t index) const
{
    if (index >= number.size())
        throw "Out of range";

    return number[index];
}
bool MyInteger::operator==(const MyInteger &number2)
{
    if (this->negtive != number2.negtive)
    {
        return false;
    }
    return this->number == number2.number;
}
MyInteger &MyInteger::operator=(const MyInteger &number2)
{
    number = number2.number;
    return *this;
}
MyInteger &MyInteger::operator+=(const MyInteger &number2)
{
    if (negtive != number2.negtive && MyInteger::greater(number2.number, number))
    {
        MyInteger ans = number2;
        simple_calc(ans.number, number, false);
        *this = ans;
        return *this;
    }

    simple_calc(number, number2.number, negtive == number2.negtive);
    if (number.size() == 1 && number[0] == 0)
    {
        negtive = false;
    }
    return *this;
}
MyInteger MyInteger::operator+(const MyInteger &number2)
{
    MyInteger number1 = (*this);
    number1 += number2;
    return number1;
}
MyInteger MyInteger::operator-(const MyInteger &number2)
{
    MyInteger temp = number2;
    temp.negtive = !number2.negtive;
    return operator+(temp);
}
MyInteger MyInteger::operator*(const MyInteger &number2)
{
    MyInteger number1 = (*this);
    MyInteger ans = 0;
    vector<char> zero;
    zero.push_back('0');
    if (number1.number == zero || number2.number == zero)
    {
        return ans;
    }

    ans.negtive = (number1.negtive != number2.negtive);

    for (size_t i = 0; i < number1.number.size(); i++)
    {
        for (size_t j = 0; j < number2.number.size(); j++)
        {
            MyInteger::add_at(ans.number, i + j, number1.number[i] * number2.number[j]);
        }
    }
    return ans;
}

ostream &operator<<(ostream &out, const MyInteger &num)
{
    if (num.negtive)
    {
        out << '-';
    }
    for (int i = num.number.size() - 1; i >= 0; --i)
    {
        out << (char)(num.number[i] + '0');
    }
    return out;
}

const char *MyInteger::getnum()
{
    while (number.back() == 0)
    {
        number.pop_back();
    }
    string str;
    if (negtive)
        str.push_back('-');
    int size = number.size();
    for (int i = size - 1; i >= 0; i--)
    {
        str.push_back(number[i] + '0');
    }
    const char *p_char = str.c_str();
    return p_char;
}

int main()
{
    MyInteger a, b;
    a = 123456;
    b = 654321;
    // cout << a;
    // MyInteger c(12345);
    // MyInteger d("45678");
    // MyInteger bint("01895");
    // cout << bint.getnum() << endl;
    // cout << c.getnum() << endl;
    // cout << d.getnum() << endl;

    // cout << c.getnum() << endl;
    //  c = b - a;
    //  cout << c.getnum() << endl;
    MyInteger e;
    e = a * b;
    cout << e.getnum() << endl;
}
