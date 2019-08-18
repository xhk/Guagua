#pragma once
#include "Encoding.h"

namespace System {
	namespace Text {

		class ASCIIEncoding :
			public Encoding
		{
		public:
			ASCIIEncoding();
			~ASCIIEncoding();

			static ASCIIEncoding & Default() {
				static ASCIIEncoding ec;
				return ec;
			}

			std::vector<char> GetBytes(String str);

		};

	}
}
