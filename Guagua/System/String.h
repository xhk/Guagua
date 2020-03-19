#pragma once
#include <atlstr.h>
#include <vector>



namespace Guagua{
namespace System{
class String : public CStringW
{
public:
	String();
	~String();

	// 静态格式化函数
	// 直接返回格式化后的String对象
	// 为了方便，牺牲一点点性能
	static String Format(_In_z_ _Printf_format_string_ PCXSTR pszFormat, ...);

	// 从Unicode串构造
	String(const wchar_t *pszSrc);
	// 从Ansi串构造
	String(const char *pszSrc);
	// 从Ansi串构造
	String(const unsigned char *pszSrc);

	// 从Unicode赋值
	//String & operator=(const wchar_t *pszSrc);
	// 从Ansi赋值
	String & operator=(const char *pszSrc);
	// 从Ansi赋值
	String & operator=(const unsigned char *pszSrc);

	// 分割字符串
	// 是否移除空的字符串
	std::vector<String> Split(wchar_t separator, bool bRemoveEmptyEntries = false);
	std::vector<String> Split(const String & separator, bool bRemoveEmptyEntries = false);

	//***********字符串查找相关******************
	bool Contains(const String & strValue);
	bool BeginsWith(const String & strValue);
	bool EndsWith(const String & strValue);

	int GetHashCode();


	// 使用C++ 重载操作符的优势
	String & operator<<(const wchar_t *pszWide);
	String & operator<<(const char *pszAnsi);
	String & operator<<(const unsigned char *pszAscii);
	String & operator<<(wchar_t c);
	String & operator<<(char c);
	String & operator<<(unsigned char c);
	String & operator<<(short num);
	String & operator<<(int num);
	String & operator<<(unsigned int num);
	String & operator<<(__int64 num);
	String & operator<<(unsigned __int64 num);
	String & operator<<(float num);
	String & operator<<(double num);

	struct Hash
	{
		public:
			size_t operator()(const String &s) const
			{
				return std::hash<std::wstring>()(s.GetString());
			}
	};

	//
	// 忽略大小写
	struct IgnoreCaseHash
	{
	public:
		size_t operator()(const String &s) const
		{
			CString t = s;
			t.MakeUpper();
			return std::hash<std::wstring>()(t.GetString());
		}
	};


};

}
}