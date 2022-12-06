#include <iostream>
#include <string>

using namespace std;
const int day_tab[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                            {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
const string month_name[13] = {" ", "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
const string day_name[13] = {"th", "st", "nd", "rd"};

int leap(int y)
{
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

int month_to_day(int leap, int month, int day)
{
    for (int i = month - 2; i >= 0; i--)
        day += day_tab[leap][i];
    return day;
}

int year_to_day(int year)
{
    return 365 + leap(year);
}

void times(int data)
{
    if (data <= 9)
        cout << 0;
}

int main()
{
    int n;
    long long year0, month0, day0, hour0, minute0, second0;
    long long year_new, month_new, day_new, hour_new, minute_new, second_new;
    long long second1, second_add, day_add;

    cin >> n;
    while (n--)
    {
        cin >> year0 >> month0 >> day0 >> hour0 >> minute0 >> second0 >> second1;
        day_add = second1 / 86400;
        long long second_add = hour0 * 3600 + minute0 * 60 + second0 + second1 % 86400;
        if (second_add >= 86400)
        {
            day_add += second_add / 86400;
            second_add %= 86400;
        }
        hour_new = second_add / 3600;
        second_add %= 3600;
        minute_new = second_add / 60;
        second_add %= 60;
        second_new = second_add;
        day_add += month_to_day(leap(year0), month0, day0);
        long long y = year0;
        while (day_add > year_to_day(y))
        {
            day_add -= year_to_day(y);
            y++;
        }
        while (day_add <= 0)
        {
            y--;
            day_add += year_to_day(y);
        }
        long long m = 1;
        long long d1;
        while ((d1 = day_add - day_tab[leap(y)][m - 1]) > 0)
        {
            day_add = d1;
            m++;
        }
        year_new = y;
        month_new = m;
        day_new = day_add;

        cout << month_name[month_new] << " " << day_new;
        if (day_new % 10 > 0 && day_new % 10 <= 3 && day_new / 10 != 1)
            cout << day_name[day_new % 10] << " ";
        else
            cout << day_name[0] << " ";

        times(hour_new);
        cout << hour_new << ":";
        times(minute_new);
        cout << minute_new << ":";
        times(second_new);
        cout << second_new << " " << year_new << endl;
    }
}