#include "stdafx.h"
#include "CppUnitTest.h"
#include "System/DateTime.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Guagua::System;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			DateTime dt1(20200322);
			DateTime dt2(20200323);

			Logger::WriteMessage("Test DateTime < ");
			Assert::AreEqual(dt1 < dt2, true);

			Logger::WriteMessage("Test DateTime <= ");
			Assert::AreEqual(dt1 <= dt2, true);
		}

		TEST_METHOD(DateTimeAddDays) 
		{
			DateTime dt1(20200322);
			dt1.AddDays(1);
			Assert::AreEqual(dt1.Date()== 20200323, true);

			dt1.AddDays(-1);
			Assert::AreEqual(dt1.Date() == 20200322, true);
		}
	};
}