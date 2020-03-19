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

	// ��̬��ʽ������
	// ֱ�ӷ��ظ�ʽ�����String����
	// Ϊ�˷��㣬����һ�������
	static String Format(_In_z_ _Printf_format_string_ PCXSTR pszFormat, ...);

	// ��Unicode������
	String(const wchar_t *pszSrc);
	// ��Ansi������
	String(const char *pszSrc);
	// ��Ansi������
	String(const unsigned char *pszSrc);

	// ��Unicode��ֵ
	//String & operator=(const wchar_t *pszSrc);
	// ��Ansi��ֵ
	String & operator=(const char *pszSrc);
	// ��Ansi��ֵ
	String & operator=(const unsigned char *pszSrc);

	// �ָ��ַ���
	// �Ƿ��Ƴ��յ��ַ���
	std::vector<String> Split(wchar_t separator, bool bRemoveEmptyEntries = false);
	std::vector<String> Split(const String & separator, bool bRemoveEmptyEntries = false);

	//***********�ַ����������******************
	bool Contains(const String & strValue);
	bool BeginsWith(const String & strValue);
	bool EndsWith(const String & strValue);

	int GetHashCode();


	// ʹ��C++ ���ز�����������
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
	// ���Դ�Сд
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