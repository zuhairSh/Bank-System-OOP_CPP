#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdio>
#include "clsString.h"

using namespace std;

class clsDate
{

private:
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string sDate)
	{
		vector<string> vDate = clsString::Split(sDate, "/");

		if (vDate.size() != 3)
			throw invalid_argument("Invalid Date Format");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DateOrderInYear, short Year)
	{
		clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
		_Day = Date1.GetDay();
		_Month = Date1.GetMonth();
		_Year = Date1.GetYear();
	}

	void SetDay(short Day) { _Day = Day; }
	short GetDay() { return _Day; }

	void SetMonth(short Month) { _Month = Month; }
	short GetMonth() { return _Month; }

	void SetYear(short Year) { _Year = Year; }
	short GetYear() { return _Year; }

	void Print()
	{
		cout << DateToString() << endl;
	}

	static bool isLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return isLeapYear(Year) ? 366 : 365;
	}

	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
			return 0;

		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date.GetDay()) + "/" +
			   to_string(Date.GetMonth()) + "/" +
			   to_string(Date.GetYear());
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static clsDate AddOneDay(clsDate Date)
	{
		if (Date.GetDay() == NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear()))
		{
			Date.SetDay(1);

			if (Date.GetMonth() == 12)
			{
				Date.SetMonth(1);
				Date.SetYear(Date.GetYear() + 1);
			}
			else
			{
				Date.SetMonth(Date.GetMonth() + 1);
			}
		}
		else
		{
			Date.SetDay(Date.GetDay() + 1);
		}

		return Date;
	}

	void AddOneDay()
	{
		*this = AddOneDay(*this);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.GetYear() < Date2.GetYear()) ||
			(Date1.GetYear() == Date2.GetYear() && Date1.GetMonth() < Date2.GetMonth()) ||
			(Date1.GetYear() == Date2.GetYear() && Date1.GetMonth() == Date2.GetMonth() && Date1.GetDay() < Date2.GetDay());
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2)
	{
		int Days = 0;

		if (!IsDate1BeforeDate2(Date1, Date2))
			swap(Date1, Date2);

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Date1 = AddOneDay(Date1);
			Days++;
		}

		return Days;
	}

	int NumberOfSecondsInAYear()
	{
		return NumberOfDaysInAYear(_Year) * 24 * 60 * 60;
	}

	void IncreaseDateByXYears(short Years)
	{
		_Year += Years;
	}

	clsDate IncreaseDateByXYears(short Years, clsDate& Date)
	{
		Date.SetYear(Date.GetYear() + Years);
		return Date;
	}

	clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		Date.SetYear(Date.GetYear() + 1000);
		return Date;
	}

	clsDate IncreaseDateByOneMillennium()
	{
		return IncreaseDateByOneMillennium(*this);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp;
		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;
		Date.SetYear(Year);
		Date.SetMonth(1);

		short RemainingDays = DateOrderInYear;

		while (true)
		{
			short MonthDays = NumberOfDaysInAMonth(Date.GetMonth(), Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.SetMonth(Date.GetMonth() + 1);
			}
			else
			{
				Date.SetDay(RemainingDays);
				break;
			}
		}

		return Date;
	}

	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year,Hour,Minute,Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}

};