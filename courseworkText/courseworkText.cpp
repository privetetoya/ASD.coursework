#include "pch.h"
#include "CppUnitTest.h"
#include "../ASD.coursework/EdmondsKarp.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace courseworkText
{
	TEST_CLASS(courseworkTest)
	{
	public:
		
		TEST_METHOD(maxflowTest)
		{
			algorithm test;
			test.input("C:\\Users\\Ирина Анатольевна\\source\\repos\\ASD.coursework\\ASD.coursework\\input.txt");
			int expected = 5;
			int inreal = test.maxflow();
			Assert::AreEqual(expected, inreal);
		}
	};
}
