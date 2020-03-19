#pragma once
#include <System/String.h>

namespace Guagua {
	namespace System {
		namespace Diagnostics {


class Process {
public:
	static String GetCurrentModuleDirectory();
	static String GetCurrentModuleFileName();
};

		}
	}
}
