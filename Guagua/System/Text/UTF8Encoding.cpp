#include "UTF8Encoding.h"


namespace System {
	namespace Text {
		UTF8Encoding::UTF8Encoding() {

		}

		UTF8Encoding::~UTF8Encoding() {

		}

		Encoding & UTF8Encoding::Default()
		{
			static UTF8Encoding ec;
			return ec;
		}

		std::vector<char> UTF8Encoding::GetBytes(String str)
		{
			int utf8size = ::WideCharToMultiByte(CP_UTF8, 0, str.GetString(), -1, NULL, 0, NULL, NULL);
			if (utf8size == ERROR_NO_UNICODE_TRANSLATION || utf8size==0)
			{
				return std::vector<char>();
			}


			std::vector<char> resultstring(utf8size);

			int convresult = ::WideCharToMultiByte(CP_UTF8, 0, str.GetString(), -1, &resultstring[0], utf8size, NULL, NULL);
			return resultstring;
		}
	}
}