

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

class BigInt
{
public:
    BigInt(long long num = 0);
    explicit BigInt(string str);
    virtual ~BigInt();

    int digit_at(size_t index) const;

    BigInt &operator=(const BigInt &number2);
    BigInt &operator+=(const BigInt &number2);
    BigInt &operator*=(const BigInt &number2);
    BigInt &operator-=(const BigInt &number2);
    BigInt &operator/=(const BigInt &number2);
    BigInt &operator%=(const BigInt &number2);
    BigInt &operator++();
    BigInt &operator--();
    BigInt operator++(int);
    BigInt operator--(int);

    friend bool operator==(const BigInt &number1, const BigInt &number2);
    friend bool operator!=(const BigInt &number1, const BigInt &number2);
    friend bool operator<(const BigInt &number1, const BigInt &number2);
    friend bool operator>(const BigInt &number1, const BigInt &number2);
    friend bool operator<=(const BigInt &number1, const BigInt &number2);
    friend bool operator>=(const BigInt &number1, const BigInt &number2);

    friend BigInt operator+(const BigInt &number1, const BigInt &number2);
    friend BigInt operator*(const BigInt &number1, const BigInt &number2);
    friend BigInt operator-(const BigInt &number1, const BigInt &number2);
    friend BigInt operator/(const BigInt &number1, const BigInt &number2);
    friend BigInt operator%(const BigInt &number1, const BigInt &number2);
    friend ostream &operator<<(ostream &output, const BigInt &num);
    friend istream &operator>>(istream &intput, BigInt &num);

private:
    vector<char> number;
    bool negtive;
    static void simple_calc(vector<char> &number1, const vector<char> &number2, bool plus);
    static void add_at(vector<char> &num, int i, unsigned char x);
    static bool greater(const vector<char> &number1, const vector<char> &number2);
};

BigInt::BigInt(long long num)
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
    if (number.empty())
    {
        number.emplace_back(0);
    }
}

BigInt::BigInt(string str)
{
    negtive = false;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            number.emplace_back(str[i] - '0');
        }
        else if (i == 0 && str[0] == '-')
        {
            negtive = true;
        }
        else
        {
            break;
        }
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
BigInt::~BigInt() {}

int BigInt::digit_at(size_t index) const
{
    if (index >= number.size())
    {
        throw "Out of range";
    }
    return number[index];
}
void BigInt::add_at(vector<char> &number, int index, unsigned char x)
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

BigInt &BigInt::operator=(const BigInt &number2)
{
    number = number2.number;
    negtive = number2.negtive;
    return *this;
}
BigInt &BigInt::operator+=(const BigInt &number2)
{
    if (negtive != number2.negtive && BigInt::greater(number2.number, number))
    {
        BigInt ans = number2;
        BigInt::simple_calc(ans.number, number, false);
        *this = ans;
        return *this;
    }
    BigInt::simple_calc(number, number2.number, negtive == number2.negtive);
    if (number.size() == 1 && number[0] == 0)
    {
        negtive = false;
    }
    return *this;
}
BigInt &BigInt::operator*=(const BigInt &number2)
{
    *this = (*this) * number2;
    return *this;
}
BigInt &BigInt::operator-=(const BigInt &number2)
{
    *this = (*this) - number2;
    return *this;
}
BigInt &BigInt::operator/=(const BigInt &number2)
{
    *this = (*this) / number2;
    return *this;
}
BigInt &BigInt::operator%=(const BigInt &number2)
{
    if (number2 == 0)
    {
        throw "Divide by zero";
    }
    if (BigInt::greater(number2.number, number))
    {
        return *this;
    }
    int index = number.size() - number2.number.size();
    while (index >= 0)
    {
        vector<char> temp(index, 0);
        temp.insert(temp.end(), number2.number.begin(), number2.number.end());
        while (!BigInt::greater(temp, number))
        {
            BigInt::simple_calc(number, temp, false);
        }
        index--;
    }
    if (number.size() == 1 && number[0] == 0)
    {
        negtive = false;
    }
    return *this;
}

BigInt &BigInt::operator++()
{
    (*this) += 1;
    return *this;
}
BigInt &BigInt::operator--()
{
    (*this) -= 1;
    return *this;
}
BigInt BigInt::operator++(int)
{
    BigInt temp = (*this);
    (*this) += 1;
    return temp;
}
BigInt BigInt::operator--(int)
{
    BigInt temp = (*this);
    (*this) -= 1;
    return temp;
}

bool operator==(const BigInt &number1, const BigInt &number2)
{
    if (number1.negtive != number2.negtive)
    {
        return false;
    }
    return number1.number == number2.number;
}
bool operator!=(const BigInt &number1, const BigInt &number2)
{
    return !(number1 == number2);
}
bool operator<(const BigInt &number1, const BigInt &number2)
{
    return number2 > number1;
}
bool operator>(const BigInt &number1, const BigInt &number2)
{
    if (number1.negtive == false)
    {
        if (number2.negtive == true)
        {
            return true;
        }
        else
        {
            return BigInt::greater(number1.number, number2.number); //全为正数
        }
    }
    else
    {
        if (number2.negtive == false)
        {
            return false;
        }
        else
        {
            return BigInt::greater(number2.number, number1.number); //全为负数
        }
    }
}
bool operator<=(const BigInt &number1, const BigInt &number2)
{
    return !(number1 > number2);
}
bool operator>=(const BigInt &number1, const BigInt &number2)
{
    return !(number1 < number2);
}

BigInt operator+(const BigInt &number1, const BigInt &number2)
{
    BigInt ans = number1;
    ans += number2;
    return ans;
}
BigInt operator*(const BigInt &number1, const BigInt &number2)
{
    BigInt ans = 0;
    if (number1 == 0 || number2 == 0)
    {
        return ans;
    }
    ans.negtive = (number1.negtive != number2.negtive); //同号得正，异号得负
    for (size_t i = 0; i < number1.number.size(); i++)
    {
        for (size_t j = 0; j < number2.number.size(); j++)
        {
            BigInt::add_at(ans.number, i + j,
                           number1.number[i] * number2.number[j]);
        }
    }
    return ans;
}

BigInt operator-(const BigInt &number1, const BigInt &number2)
{
    BigInt temp = number2;
    temp.negtive = !number2.negtive; // temp 是number2的相反数
    return operator+(number1, temp); // n1 - n2 = n1 + (-1 * n2)
}
BigInt operator/(const BigInt &number1, const BigInt &number2)
{
    BigInt ans = 0;
    if (number2 == 0)
    {
        throw "Divide by zero";
    }
    if (BigInt::greater(number2.number, number1.number))
    {
        return ans;
    }
    ans.negtive = (number1.negtive != number2.negtive);
    vector<char> left = number1.number;
    int index = left.size() - number2.number.size();
    while (index >= 0)
    {
        vector<char> temp(index, 0);
        temp.insert(temp.end(), number2.number.begin(), number2.number.end());
        while (!BigInt::greater(temp, left))
        {
            BigInt::simple_calc(left, temp, false);
            BigInt::add_at(ans.number, index, 1);
        }
        index--;
    }
    return ans;
}
BigInt operator%(const BigInt &number1, const BigInt &number2)
{
    BigInt ans = number1;
    ans %= number2;
    return ans;
}
istream &operator>>(istream &in, BigInt &num)
{
    string str;
    in >> str;
    num = BigInt(str);
    return in;
}
ostream &operator<<(ostream &out, const BigInt &num)
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

void BigInt::simple_calc(vector<char> &num1, const vector<char> &num2,
                         bool plus)
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
        while (size1 > 1 && num1.back() == 0)
        {
            num1.pop_back();
            size1--;
        }
        return;
    }
}

bool BigInt::greater(const vector<char> &number1, const vector<char> &number2)
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

int main()
{
    BigInt num1, num2;
    while (1)
    {
        cout << "please enter two long number:" << endl;
        cin >> num1 >> num2;
        cout << "num1 = " << num1 << endl;
        cout << "num2 = " << num2 << endl;

        if (num1 == num2)
        {
            cout << "num1 == num2" << endl;
        }
        else if (num1 < num2)
        {
            cout << "num1 < num2" << endl;
        }
        else
        {
            cout << "num1 > num2" << endl;
        }
        cout << "num1 + num2 = " << num1 + num2 << endl;
        cout << "num1 - num2 = " << num1 - num2 << endl;
        cout << "num1 * num2 = " << num1 * num2 << endl;
        cout << "num1 / num2 = " << num1 / num2 << endl;
        cout << "num1 % \\num2 = " << num1 % num2 << endl;
    }

    return 0;
}
