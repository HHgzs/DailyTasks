#include <bits/stdc++.h>
using namespace std;
class MyInteger
{
private:
    vector<char> number;
    bool negtive;
    static void simple_calc(vector<char> &number1, const vector<char> &number2, bool plus);
    static void add_at(vector<char> &num, int i, unsigned char x);
    static bool greater(const vector<char> &number1, const vector<char> &number2);

public:
    MyInteger()
    {
    }

    MyInteger(int num)
    {
    }

    MyInteger(string num)
    {
    }

    ~MyInteger()
    {
    }

    MyInteger &operator=(const MyInteger &number2)
    {
        number = number2.number;
        return *this;
    }

    int digit_at(size_t index) const
    {
        if (index >= number.size())
            throw "Out of range";

        return number[index];
    }

    void add_at(vector<char> &number, int index, unsigned char x)
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

    void simple_calc(vector<char> &num1, const vector<char> &num2)
    {
        int size1 = num1.size();
        int size2 = num2.size();

        for (int i = 0; i < size2; i++)
        {
            add_at(num1, i, num2[i]);
        }
        return;
    }

    void getnum()
    {
        int size = number.size();
        for(int i = 0; i < size; i++)
        {
            cout << number[i];
        }
    }

    MyInteger operator+(const MyInteger &number2)
    {
        MyInteger number1 = (*this);
        simple_calc(number1.number, number2.number);
        return number1;
    }

    MyInteger operator-(const MyInteger &b)
    {
    }

    MyInteger operator*(const MyInteger &b)
    {
    }

    MyInteger operator*(const MyInteger &number2)
    {
        MyInteger number1 = (*this);
        MyInteger ans = 0;
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
};
