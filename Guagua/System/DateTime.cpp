#include "DateTime.h"
#include <atltime.h>
namespace Guagua {
	namespace System {



		DateTime::DateTime()
		{
		}


		DateTime::~DateTime()
		{
		}

		DateTime::DateTime(unsigned int nDate, unsigned int nTime)
		{
			m_nDate = nDate;
			m_nTime = nTime;
		}

		DateTime::DateTime(unsigned int nYear, unsigned int nMonth, unsigned int nDay,
			unsigned int nHour, unsigned int nMinute, unsigned int nSecond, unsigned int nMillSecond)
		{
			m_nDate = nYear * 10000 + nMonth * 100 + nDay;
			m_nTime = (nHour * 10000 + nMinute * 100 + nSecond) * 1000 + nMillSecond;
		}

		unsigned int DateTime::Year()
		{
			return m_nDate % 10000;
		}

		unsigned int DateTime::Month()
		{
			return m_nDate / 100 % 100;
		}

		unsigned int DateTime::Day() {
			return m_nDate % 100;
		}

		unsigned int DateTime::Hour() {
			return m_nTime / 1000 % 10000;
		}
		unsigned int DateTime::Minute()
		{
			return m_nTime / 1000 / 100 % 100;
		}
		unsigned int DateTime::Second() {
			return m_nTime / 1000 % 100;
		}
		unsigned int DateTime::MillSecond()
		{
			return m_nTime % 1000;
		}

		String DateTime::ToString()
		{
			return String::Format(L"%04/d%02d/%02d %02d:%02d:%02d", Year(), Month(), Day(), Hour(), Minute(), Second());
		}

		String DateTime::ToString(const String & strFormat)
		{
			String strTime = strFormat;

			// year
			strTime.Replace(L"YYYY", String::Format(L"%04d", Year()));
			strTime.Replace(L"YY", String::Format(L"%02d", Year()));

			// Month
			strTime.Replace(L"MM", String::Format(L"%02d", Month()));
			strTime.Replace(L"DD", String::Format(L"%02d", Day()));
			strTime.Replace(L"HH", String::Format(L"%02d", Hour()));
			strTime.Replace(L"hh", String::Format(L"%02d", Hour() % 12));
			strTime.Replace(L"mm", String::Format(L"%02d", Minute()));
			strTime.Replace(L"ss", String::Format(L"%02d", Second()));
			strTime.Replace(L"ms", String::Format(L"%02d", MillSecond()));


			return strTime;
		}

		void DateTime::AddDays(int nDays)
		{
			if (nDays == 0) {
				return;
			}

			CTime t(Year(), Month(), Day());
			if (nDays > 0) {
				CTimeSpan ts(nDays, 0, 0, 0);
				t += ts;
			}
			else {
				CTimeSpan ts(-nDays, 0, 0, 0);
				t -= ts;
			}

			m_nDate = t.GetYear() * 10000 + t.GetMonth() * 100 + t.GetDay();
		}
	}
}