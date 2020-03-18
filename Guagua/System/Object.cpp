//#include "stdafx.h"
#include "Object.h"
namespace Guagua {
	namespace System {

		Object::Object()
		{
		}


		Object::~Object()
		{
		}

		bool Object::Equals(Object *obj)
		{
			return this == obj;
		}

		bool Object::Equals(Object *objA, Object *objB) {
			return objA == objB;
		}

		bool Object::ReferenceEquals(Object *objA, Object *objB) {
			return Equals(objA, objB);
		}

		// this hash function is from Reason Framework
#define Get16Bits(d) (*((const unsigned short *) (d)))

		unsigned int Hash(const char * data, int length)
		{
			unsigned int hash = length, tmp;
			int rem;

			if (length <= 0 || data == 0) return 0;

			rem = length & 3;
			length >>= 2;

			for (; length > 0; length--) {
				hash += Get16Bits(data);
				tmp = (Get16Bits(data + 2) << 11) ^ hash;
				hash = (hash << 16) ^ tmp;
				data += 2 * sizeof(unsigned short);
				hash += hash >> 11;
			}

			switch (rem) {
			case 3: hash += Get16Bits(data);
				hash ^= hash << 16;
				hash ^= data[sizeof(unsigned short)] << 18;
				hash += hash >> 11;
				break;
			case 2: hash += Get16Bits(data);
				hash ^= hash << 11;
				hash += hash >> 17;
				break;
			case 1: hash += *data;
				hash ^= hash << 10;
				hash += hash >> 1;
			}

			hash ^= hash << 3;
			hash += hash >> 5;
			hash ^= hash << 4;
			hash += hash >> 17;
			hash ^= hash << 25;
			hash += hash >> 6;

			return hash;
		}

		int Object::GetHashCode() {
			return Hash((char*)this, sizeof(*this));
		}

		String Object::ToString() {
			String strObject;
			strObject.Format(L"Object %08x", this);
			return strObject;
		}
	}
}