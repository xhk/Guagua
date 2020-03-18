#pragma once
#include <System/String.h>

namespace Guagua {
	namespace System {
		namespace IO {


class Directory
{
public:
	static bool CreateDirectory(const String & strPath);
	static bool Exists(const String & strPath);

};

		}
	}
}