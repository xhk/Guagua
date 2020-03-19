#include "stdafx.h"
#include "Config.h"
#include <sstream>
#include <System/Diagnostics/Process.h>


namespace Guagua {
	namespace Utils {
		Config::Config(const TCHAR *szIniFile)
		{
			if (szIniFile) {
				if (_tcschr(szIniFile, ':')) {
					m_file = szIniFile;
				}
				else {
					m_file = System::Diagnostics::Process::GetCurrentModuleDirectory();
					m_file << "\\" << szIniFile;
				}
			}
			else {
				wchar_t szModuleFile[MAX_PATH] = { 0 };
				GetModuleFileName(NULL, szModuleFile, MAX_PATH);
				CString file = szModuleFile;
				file.MakeLower();
				file.Replace(L".exe", L".ini");
				m_file = file.GetString();

				m_file = System::Diagnostics::Process::GetCurrentModuleFileName();
				m_file.MakeLower();
				m_file.Replace(L".exe", L".ini");
				m_file.Replace(L".dll", L".ini");
			}
		}

		Config::~Config()
		{
		}

		System::String Config::Get(System::String section, System::String key, System::String defval) {
			TCHAR szVal[1024] = { 0 };
			auto it = m_items.find(section);
			if (it != m_items.end()) {
				auto itval = it->second.find(key);
				if (itval != it->second.end()) {
					return itval->second;
				}
				else {
					GetPrivateProfileString(section.GetString(), key.GetString(), defval.GetString(), szVal, 1024, m_file.GetString());
					it->second.insert(std::make_pair(key, szVal));
				}
			}
			else {
				GetPrivateProfileString(section.GetString(), key.GetString(), defval.GetString(), szVal, 1024, m_file.GetString());
				m_items[section].insert(std::make_pair(key, szVal));
			}

			return szVal;
		}
		int Config::Get(System::String section, System::String key, int defval)
		{
			System::String ss;
			ss << defval;
			return _ttoi(Get(section, key, ss).GetString());
		}

		void Config::Set(System::String section, System::String key, System::String val)
		{
			Set(section.GetString(), key.GetString(), val.GetString());
		}

		void Config::Set(System::String section, System::String key, int val)
		{
			System::String ss;
			ss << val ;

			Set(section.GetString(), key.GetString(), ss.GetString());
		}

		void Config::Set(const wchar_t *section, const wchar_t *key, const wchar_t *val)
		{
			m_items[section][key] = val;
			WritePrivateProfileString(section, key, val, m_file.GetString());
		}

	}
}