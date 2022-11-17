#include <iostream>

class Date
{
public:
    int GetMonthDay(int year, int month);
    Date(int year = 2000, int month = 1, int day = 1);
    Date(const Date &d);
    ~Date();
    Date &operator+=(int day);
    Date operator+(int day);
    Date &operator-=(int day);
    Date operator-(int day);
    Date &operator++();
    Date operator++(int);
    Date &operator--();
    Date operator--(int);
    bool operator==(const Date &d);
    bool operator!=(const Date &d);
    bool operator>(const Date &d);
    bool operator<=(const Date &d);
    bool operator>=(const Date &d);
    inline bool operator>=(const Date &d);
    bool operator<(const Date &d);
    int operator-(const Date &d);

private:
    int _year;
    int _month;
    int _day;
};