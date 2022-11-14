
/*
#include<bits/stdc++.h>
using namespace std;
   //include<iostream>
   //include<string>
   //include<cctype>
    int hex2Dec(const string& hex);
    int hexCharToDecimal(char ch);
    
    int main()
    {
        cout << "Enter a hex number: ";
        string hex;
        cin >> hex;
        cout << "The decimal value for hex number "<< hex << " is "<< hex2Dec(hex) << endl;
        getchar();
        getchar();
        return 0;
    }

    int hex2Dec(const string& hex)
    {
        int decimalValue = 0;
        for (unsigned i = 0; i < hex.size(); i++ )
        decimalValue = decimalValue * 16 + hexCharToDecimal(hex[i]);
    return decimalValue;
    }

    int hexCharToDecimal(char ch)
    {
        ch = toupper(ch);
        if (ch >= 'A' && ch <= 'F')
            return 10 + ch - 'A';
        else
            return ch - '0';
    }
*/




#include<iostream>
#include<iomanip>
using namespace std;
void print_month(int year , int month);
void print_month_title(int year , int month);
void print_month_name(int month);
void print_month_body(int year ,int month);
int get_start_day(int year, int month);
int get_total_number_of_days(int year ,int month);
int get_number_of_days_in_month(int year, int month);
bool is_leap_year(int year);

int main()
{
    cout << "Enter full year (e.g., 2001):";
    int year;
    cin >> year;
    cout << "Enter month in number between 1 and 12: ";
    int month;
    cin >> month;
    print_month(year, month);
    getchar();
    getchar();
    return 0;
}
void print_month(int year, int month)
{
    print_month_title(year, month);
    print_month_body(year, month);
}
void print_month_title(int year, int month)
{
    print_month_name(month);
    cout << " " << year << endl;
    cout << "-----------------------------" << endl;
    cout << " Sun Mon Yue Wed Thu Fri Sat" << endl;
}
void print_month_name(int month)
{
    switch(month)
    {
        case 1:
            cout << "January";
            break;
        case 2:
            cout << "February";
            break;
        case 3:
            cout << "March";
            break;
        case 4:
            cout << "April"; 
            break;
        case 5:
            cout << "May";
            break;
        case 6:
            cout << "June"; 
            break;
        case 7:
            cout << "July"; 
            break;
        case 8:
            cout << "August"; 
            break;
        case 9:
            cout << "September"; 
            break;
        case 10:
            cout << "October"; 
            break;
        case 11:
            cout << "November"; 
            break;
        case 12:
            cout << "December"; 
            break;
    }
}

void print_month_body(int year, int month)
{
    int start_day = get_start_day(year, month);
    int number_of_days_in_month = get_number_of_days_in_month(year, month);
    int i = 0;
    for( i = 0; i < start_day; i++)
        cout << "    ";
        for (i = 1; i <= number_of_days_in_month; i++)
        {
            cout << setw(4) <<i;
            if ((i + start_day) % 7 == 0)
                cout << endl;
        }
}

int get_start_day(int year, int month)
{
    int start_day1800 = 3;
    int total_number_of_days = get_total_number_of_days(year, month);
    return(total_number_of_days = start_day1800) % 7;
}

int get_total_number_of_days(int year, int month)
{
    int total = 0;
    for(int i = 1800; i < year; i++)
        if(is_leap_year(i))
            total = total + 366;
        else
            total = total + 365;
    for(int i = 1; i < month; i++)
        total = total +get_number_of_days_in_month(year, i);
    return total;
}

int get_number_of_days_in_month(int year, int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    if (month == 4 || month == 6 || month == 9 | month == 11)
        return 30;
    if (month == 2) return is_leap_year(year) ? 29 :28;
        return 0;
}

bool is_leap_year(int year)
{
    return year % 400 == 0 || ( year % 4 == 0 && year % 100 !=0 );
}