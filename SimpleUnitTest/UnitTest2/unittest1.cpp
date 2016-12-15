#include "stdafx.h"
#include "CppUnitTest.h"
#include "testmain.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsFalse(test1(), L"test1");
		}

	};
}