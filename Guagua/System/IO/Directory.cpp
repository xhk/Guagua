#include "Directory.h"
namespace Guagua {
	namespace System {
		namespace IO {

			bool Directory::CreateDirectory(const String & strPath)
			{
				TCHAR buff[MAX_PATH] = { 0 };
				_tcscpy_s(buff, strPath.GetString());
				TCHAR* pos = _tcschr(buff, '\\');
				while (pos)
				{
					buff[pos - buff] = '\0';
					_tmkdir(buff);
					buff[pos - buff] = '\\';
					pos = _tcschr(pos + 1, '\\');
				}
				return !_tmkdir(buff);
			}

			bool Directory::Exists(const String & strPath)
			{
				return _taccess(strPath.GetString(), 0) != -1;
			}

		}
	}
}