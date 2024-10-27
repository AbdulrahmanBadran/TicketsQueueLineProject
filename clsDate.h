#pragma once
#pragma warning (disable:4996)

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class clsDate {


	 short _day;
	 short _month;
	 short _year;
	 short _hour;
	 short _min;
	 short _sec;

public:
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		
		_year = now->tm_year + 1900;
		_month = now->tm_mon + 1;
		_day = now->tm_mday;
		_hour = now->tm_hour;
		_min = now->tm_min;
		_sec = now->tm_sec;
	}


	 string GetDateAndTime()
	{

		return to_string(_day) + '/' + to_string(_month) + '/' + to_string(_year) + '-' + to_string(_hour) + ':' + to_string(_min) + ':' + to_string(_sec);

	}


};
