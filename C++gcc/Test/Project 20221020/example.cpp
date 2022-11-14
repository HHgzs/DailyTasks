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
//构造函数
Date::Date(int year, int month, int day)
{
	if (year >= 0 && month > 0 && month < 13 && day>0 && day < GetMonthDay(year, month))
	{
		_year=year;
		_month=month;
		_day=day;
	}
	else
		std::cout << "数据错误" << std::endl;
	
}
//拷贝构造
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

}
//赋值重载
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
//日期+=天数
Date& Date::operator+=(int day)
{
	_day = _day + day;
	while(_day > GetMonthDay(_year, _month))
	{
		_day=_day-GetMonthDay(_year,_month);
		_month ++;
		if(_month==13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

//日期+天数
Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day;

	return ret;

}

//日期-=天数
Date& Date::operator-=(int day)
{
	_day = _day - day;
	while (_day < 0)
	{
		_month--;
		_day = _day + GetMonthDay(_year, _month);
		if (_month == 0)
		{
			_month = 13;
			_year--;
		}
	}
	return *this;

}

//日期-天数
Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;

}
//前置++
Date& Date::operator++()
{
	(*this) += 1;
	return *this;
}
//后置++
Date Date::operator++(int)
{
	Date ret(*this);
	(*this) += 1;
	return ret;
}
//前置--
Date& Date::operator--()
{
	(*this) -= 1;
	return *this;
}
//后置++
Date Date::operator--(int)
{
	Date ret(*this);
	(*this) -= 1;
	return ret;
}

//==重载和!=重载
bool Date::operator==(const Date& d)
{
	return _year == d._year 
		   && _month == d._month 
		   && _day == d._day;

}
bool Date::operator!=(const Date& d)
{
	return !((*this) == d);

}
//>重载
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;	
	}
	if (_year == d._year)
	{
		if (_month > d._month)
			return true;
		if (_month == d._month)
		{
			if (_day > d._day)
				return true;
			else
				return false;
		}
	}
	return false;

}

//<重载 
bool Date::operator<(const Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	if (_year == d._year)
	{
		if (_month < d._month)
			return true;
		if (_month == d._month)
		{
			if (_day < d._day)
				return true;
			else
				return false;
		}
	}
	return false;
}
//>=重载 就是<重载取反
bool Date::operator>=(const Date& d)
{
	return !((*this) < d);
}
//<=等于重载 就是>重载取反
bool Date::operator<=(const Date& d)
{
	return !((*this) > d);
}

int Date::operator-(const Date& d)
{
	Date max = *this, min = d;
	int flag = 1;//如果*this大，两者之差为正数
	if (*this<d)
	{
		max = d;
		min = *this;
		flag = -1;//如果d大，两者之差为负数
	}
	int n = 0;
	while (min != max)
	{
		min++;
		n++;
	}
	return n*flag;



}
