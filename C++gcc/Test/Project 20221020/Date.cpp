#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	int month_days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = month_days[month];
	if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))//是闰年
	{
		days = 29;
	}
	return days;
}
