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
		TEST_METHOD(nofileTest) {
			algorithm test;
			try {
				test.input("something.txt");
			}
			catch (runtime_error x) {
				Assert::AreEqual(x.what(), "File was not found");
			}
		}

		TEST_METHOD(inputTest)
		{

			algorithm test;
			try{
				test.input("C:\\Users\\Ирина Анатольевна\\source\\repos\\ASD.coursework\\ASD.coursework\\wronginput.txt");
			}

			catch (invalid_argument x)			{
				Assert::AreEqual("Graph should start with S and ended with T", x.what());
			}
		}
	};
}
