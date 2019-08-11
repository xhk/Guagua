#include "../stdafx.h"
#include "String.h"
#include <string>

namespace System {
	String::String() {}

	String::~String() {

	}

	String String::Format(_In_z_ _Printf_format_string_ PCXSTR pszFormat, ...)
	{
		String str;
		va_list argList;
		va_start(argList, pszFormat);
		str.FormatV(pszFormat, argList);
		va_end(argList);

		return str;
	}

	String::String(const wchar_t *pszWide)
		: CStringW(pszWide)
	{

	}


	String::String(const char *pszAscii)
	{
		int widesize = MultiByteToWideChar(CP_ACP, 0, pszAscii, -1, NULL, 0);
		int convresult = MultiByteToWideChar(CP_ACP, 0, pszAscii, -1, GetBuffer(widesize), widesize);
		ReleaseBuffer();
	}



	String::String(const unsigned char *pszAscii)
	{
		int widesize = MultiByteToWideChar(CP_ACP, 0, (char *)pszAscii, -1, NULL, 0);
		int convresult = MultiByteToWideChar(CP_ACP, 0, (char *)pszAscii, -1, GetBuffer(widesize), widesize);
		ReleaseBuffer();
	}

	String & String::operator=(const char *pszAscii)
	{
		int widesize = MultiByteToWideChar(CP_ACP, 0, pszAscii, -1, NULL, 0);
		int convresult = MultiByteToWideChar(CP_ACP, 0, pszAscii, -1, GetBuffer(widesize), widesize);
		ReleaseBuffer();
		return *this;
	}

	String & String::operator=(const unsigned char *pszAscii)
	{
		int widesize = MultiByteToWideChar(CP_ACP, 0, (char *)pszAscii, -1, NULL, 0);
		int convresult = MultiByteToWideChar(CP_ACP, 0, (char *)pszAscii, -1, GetBuffer(widesize), widesize);
		ReleaseBuffer();
		return *this;
	}

	String & String::operator<<(const wchar_t *pszWide) {
		this->Append(pszWide);
		return (*this);
	}
	String & String::operator<<(const char *pszAscii) {
		int widesize = MultiByteToWideChar(CP_ACP, 0, (char *)pszAscii, -1, NULL, 0);
		wchar_t *pNew = new wchar_t[widesize];
		int convresult = MultiByteToWideChar(CP_ACP, 0, (char *)pszAscii, -1, pNew, widesize);
		this->Append(pNew);
		delete pNew;
		return (*this);
	}
	String & String::operator<<(const unsigned char *pszAscii) {
		int widesize = MultiByteToWideChar(CP_ACP, 0, (char *)pszAscii, -1, NULL, 0);
		wchar_t *pNew = new wchar_t[widesize];
		int convresult = MultiByteToWideChar(CP_ACP, 0, (char *)pszAscii, -1, pNew, widesize);
		this->Append(pNew);
		delete pNew;
		return (*this);
	}
	String & String::operator<<(wchar_t c) {
		AppendChar(c);
		return (*this);
	}
	String & String::operator<<(char c) {
		AppendChar(c);
		return (*this);
	}
	String & String::operator<<(unsigned char c) {
		AppendChar(c);
		return (*this);
	}
	String & String::operator<<(short num) {
		CStringW str;
		str.Format(L"%d", num);
		Append(str);
		return (*this);
	}
	String & String::operator<<(int num) {
		CStringW str;
		str.Format(L"%d", num);
		Append(str);
		return (*this);
	}
	String & String::operator<<(unsigned int num) {
		CStringW str;
		str.Format(L"%d", num);
		Append(str);
		return (*this);
	}
	String & String::operator<<(__int64 num) {
		CStringW str;
		str.Format(L"%i64", num);
		Append(str);
		return (*this);
	}
	String & String::operator<<(unsigned __int64 num) {
		CStringW str;
		str.Format(L"%i64", num);
		Append(str);
		return (*this);
	}
	String & String::operator<<(float num) {
		CStringW str;
		str.Format(L"%f", num);
		Append(str);
		return (*this);
	}
	String & String::operator<<(double num) {
		CStringW str;
		str.Format(L"%f", num);
		Append(str);
		return (*this);
	}

	std::vector<String> String::Split(wchar_t separator, bool bRemoveEmptyEntries)
	{
		String s;
		s.AppendChar(separator);
		return Split(s, bRemoveEmptyEntries);
	}

	std::vector<String> String::Split(const String & separator, bool bRemoveEmptyEntries)
	{
		std::vector<String> arr;
		unsigned int b = 0, e = 0;
		String s;
		unsigned int sep_len = separator.GetLength();
		while (-1 != (e = Find(separator, b))) {
			s = Mid(b, e - b).GetString();
			if (bRemoveEmptyEntries) {
				if (!s.IsEmpty()) {
					arr.push_back(s);
				}
			}
			else {
				arr.push_back(s);
			}

			b = e + sep_len;
		}
		s = Mid(b, GetLength() - b).GetString();
		if (bRemoveEmptyEntries) {
			if (!s.IsEmpty()) {
				arr.push_back(s);
			}
		}
		else {
			arr.push_back(s);
		}

		return arr;
	}

	bool String::Contains(const String & strValue)
	{
		return Find(strValue) >= 0;
	}

	bool String::BeginsWith(const String & strValue)
	{
		return Find(strValue) == 0;
	}

	bool String::EndsWith(const String & strValue)
	{
		auto nValueLen = strValue.GetLength();
		auto nLen = GetLength();
		if (nValueLen > nLen) {
			return false;
		}

		for (int i = 0; i < nValueLen; ++i) {
			if (strValue[nValueLen - i - 1] != GetAt(nLen - i - 1)) {
				return false;
			}
		}

		return true;
	}
}