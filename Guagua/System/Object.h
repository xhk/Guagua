#pragma once
#include "String.h"

namespace System {


class Object
{
public:
	Object();
	~Object();

	
public:
	// Returns a String which represents the object instance.  The default
	// for an object is to return the fully qualified name of the class.
	virtual String ToString();

	// Returns a boolean indicating if the passed in object obj is 
	// Equal to this.  Equality is defined as object equality for reference
	// types and bitwise equality for value types using a loader trick to
	// replace Equals with EqualsValue for value types).
	virtual bool Equals(Object *obj);

	static bool Equals(Object *objA, Object *objB);

	static bool ReferenceEquals(Object *objA, Object *objB);

	virtual int GetHashCode();

};
}
