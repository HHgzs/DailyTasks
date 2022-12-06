#include <bits/stdc++.h>
using namespace std;
class MyInteger
{
private:
    vector<char> number;
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

    string getnum()
    {
    }

    MyInteger operator+(const MyInteger &b)
    {
    }

    MyInteger operator-(const MyInteger &b)
    {
    }

    MyInteger operator*(const MyInteger &b)
    {
    }
};
