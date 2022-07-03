#include "pch.h"
#include "CppUnitTest.h" 
 
#include "../../lib/pm.tools/pm.tools.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pm::unitTest
{
	TEST_CLASS(pmUnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			bool text = true;
			char password[8] = { 'S', 't', 'e', 'f', '@', '1', '2', '3' };
			bool result = pm::tools::checkPasswordForSpecialCharacters(password, 8);
			Assert::AreEqual(text, result);
		}

		TEST_METHOD(TestMethod2)
		{
			bool text = true;
			std::string password = "Stefan@123";
			bool result = pm::tools::checkPassword(password);
			Assert::AreEqual(text, result);
		}

		TEST_METHOD(TestMethod3)
		{
			bool text = true;
			std::string username = "user1";
			bool result = pm::tools::checkStringForSpecialCharacters(username);
			Assert::AreEqual(text, result);
		}
	};
}
