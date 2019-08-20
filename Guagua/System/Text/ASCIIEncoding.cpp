#include "ASCIIEncoding.h"


namespace System {
	namespace Text {

		ASCIIEncoding::ASCIIEncoding()
		{
		}

		 
		ASCIIEncoding::~ASCIIEncoding()
		{
		}

		std::vector<char> ASCIIEncoding::GetBytes(String str)
		{
			int asciisize = ::WideCharToMultiByte(CP_OEMCP, 0, str.GetString(), -1, NULL, 0, NULL, NULL);
			if (asciisize == ERROR_NO_UNICODE_TRANSLATION)
			{
				return std::vector<char>();
			}

			if (asciisize == 0) {
				return std::vector<char>();
			}

			std::vector<char> resultstring(asciisize);
			int convresult = ::WideCharToMultiByte(CP_OEMCP, 0, str.GetString(), -1, &resultstring[0], asciisize, NULL, NULL);

			return resultstring;
		}

	}
}