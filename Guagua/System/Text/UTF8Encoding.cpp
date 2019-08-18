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

		}
	}
}