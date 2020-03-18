#include "Encoding.h"
namespace Guagua {
	namespace System {
		namespace Text {
			class UTF8Encoding :public Encoding {
			public:
				UTF8Encoding();
				~UTF8Encoding();

				Encoding & Default();

				std::vector<char> GetBytes(String str);
			};
		}
	}
}