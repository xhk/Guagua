#include "Encoding.h"
#include "ASCIIEncoding.h"
namespace Guagua {
	namespace System {
		namespace Text {


			Encoding::Encoding()
				:Encoding(0)
			{
			}

			Encoding::Encoding(int codePage)
				: _codePage(codePage)
			{

			}

			Encoding::~Encoding()
			{
			}


			Encoding & Encoding::ASCII()
			{
				return ASCIIEncoding::Default();
			}
		}
	}
}