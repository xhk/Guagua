#pragma once
#include <string>
#include <unordered_map>
#include <System/String.h>

namespace Guagua { namespace Utils{

class Config
{
public:
	Config(const TCHAR *szIniFile=NULL);
	~Config();

	static Config & Inst(){ static Config inst; return inst;}

	System::String Get(System::String section, System::String key, System::String defval);
	int Get(System::String section, System::String key, int defval);

	void Set(const wchar_t *section, const wchar_t *key, const wchar_t *val);
	void Set(System::String section, System::String key, System::String val);
	void Set(System::String section, System::String key, int val);

private:
	std::unordered_map<
		System::String, 
		std::unordered_map<System::String, System::String, System::String::Hash>, 
		System::String::Hash
	> m_items;
	System::String m_file;
};

}
}

