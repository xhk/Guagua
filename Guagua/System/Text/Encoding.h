#pragma once

#include <vector>
#include <System/String.h>
namespace Guagua {
	namespace System {
		namespace Text {


			class Encoding
			{
			protected:
				Encoding();
				Encoding(int codePage);
				~Encoding();

			public:

				static std::vector<char> Convert(Encoding & srcEncoding, Encoding & dstEncoding, const std::vector<char> & bytes);

				static Encoding & ASCII();
				static Encoding & UTF8();

				virtual std::vector<char> GetBytes(String str) = 0;

			private:
				int _codePage = 0;
			};

		}
	}
}
