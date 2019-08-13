#pragma once
#include "String.h"

namespace System {


class DateTime
{
public:
	DateTime();
	DateTime(unsigned int nDate,unsigned int nTime = 0);
	DateTime(unsigned int nYear, unsigned int nMonth, unsigned int nDay,
		unsigned int nHour = 0, unsigned int nMinute = 0, unsigned int nSecond = 0, unsigned int nMillSecond = 0);
	~DateTime();

	unsigned int Year();
	unsigned int Month();
	unsigned int Day();
	unsigned int Hour();
	unsigned int Minute();
	unsigned int Second();
	unsigned int MillSecond();

	//
	// 改变日期
	void AddDays(int nDays);

	String ToString();
	/*
	 Patterns   Format      Description                           Example
     =========  ==========  ===================================== ========
        YY     "00"        Year
		YYYY   "2019"      Year
		MM       08          Month
		DD       11          Day
		HH       20          Hour(24-hour clock)
		hh       12          hour(12-hour clock)
		mm       59          minute
		SS       59          Second
		ms      999          Millsecond
	*/
	String ToString(const String & strFormat);

private:
	unsigned int m_nDate;
	unsigned int m_nTime;
};

}