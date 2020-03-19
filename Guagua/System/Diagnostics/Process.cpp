#include "Process.h"

namespace Guagua {
	namespace System {
		namespace Diagnostics {


			Guagua::System::String Process::GetCurrentModuleDirectory()
			{
				TCHAR szModuleFile[MAX_PATH] = { 0 };
				GetModuleFileName(NULL, szModuleFile, MAX_PATH);
				*_tcsrchr(szModuleFile, '\\') = 0;
				return szModuleFile;
			}

			Guagua::System::String Process::GetCurrentModuleFileName()
			{
				TCHAR szModuleFile[MAX_PATH] = { 0 };
				GetModuleFileName(NULL, szModuleFile, MAX_PATH);
				return szModuleFile;
			}

		}
	}
}