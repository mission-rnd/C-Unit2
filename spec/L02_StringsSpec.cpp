/*
 
 Note:
 You read the code in L02_Strings.cpp file and understand the behaviour.
 And replace the blanks with correct expected output in this file.
 
 */

#include "stdafx.h"

#include "../src/L02_Strings.cpp"
#include "TestHelperMethods.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class L02_StringsSpec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};
        
        // test methods
		[TestMethod, Timeout(3000)]
		void TestnumberOfFormatSpecifiers(){
			char *str;
			int res;

			str = "%d %d";
			res = numberOfFormatSpecifiers(str);
			Assert::AreEqual(___, res, L"numberOfFormatSpecifiers() failed", 1, 2);

			str = "testing";
			res = numberOfFormatSpecifiers(str);
			Assert::AreEqual(___, res, L"numberOfFormatSpecifiers() failed", 1, 2);

			str = "testing%d";
			res = numberOfFormatSpecifiers(str);
			Assert::AreEqual(___, res, L"numberOfFormatSpecifiers() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TeststringLength(){
			char *str;
			int res;

			str = "this is a string";
			res = stringLength(str);
			Assert::AreEqual(___, res, L"stringLength() failed", 1, 2);

			str = "string     ";
			res = stringLength(str);
			Assert::AreEqual(___, res, L"stringLength() failed", 1, 2);

			str = " hai    ";
			res = stringLength(str);
			Assert::AreEqual(___, res, L"stringLength() failed", 1, 2);

			char s[10] = { 'a', 'b', 'b', '\0', 'd', 'e', 'f', 'g', 'h' };
			res = stringLength(s);
			Assert::AreEqual(___, res, L"stringLength() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TeststringMystery(){
			char *str;

			str = "hello";
			stringMystery(str);
			Assert::AreEqual(true, areEqualStrings(____, str), L"stringMystery() failed", 1, 2);

			str = "thisisamediumstring";
			stringMystery(str);
			Assert::AreEqual(true, areEqualStrings(____, str), L"stringMystery() failed", 1, 2);

			str = "loremipsumloremipsumloremipsumloremipsumlorem";
			stringMystery(str);
			Assert::AreEqual(true, areEqualStrings(____, str), L"stringMystery() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TeststringMysteryAdd(){
			char *str;

			str = "thisisaverygoodstring";
			stringMysteryAdd(str);
			Assert::AreEqual(true, areEqualStrings(____, str), L"stringMysteryAdd() failed", 1, 2);

			str = "loremipsumloremipsum";
			stringMysteryAdd(str);
			Assert::AreEqual(true, areEqualStrings(____, str), L"stringMysteryAdd() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TeststringMysteryCreate(){
			char *str;

			str = stringMysteryCreate(2);
			Assert::AreEqual(true, areEqualStrings(____, str), L"stringMysteryCreate() failed", 1, 2);

			str = stringMysteryCreate(9);
			Assert::AreEqual(true, areEqualStrings(____, str), L"stringMysteryCreate() failed", 1, 2);

			str = stringMysteryCreate(14);
			Assert::AreEqual(true, areEqualStrings(____, str), L"stringMysteryCreate() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestnumberCharMystery(){
			char *str;

			str = "1002034";
			numberCharMystery(str);
			Assert::AreEqual(true, areEqualStrings(____, str), L"numberCharMystery() failed", 1, 2);

			str = "9023";
			numberCharMystery(str);
			Assert::AreEqual(true, areEqualStrings(____, str), L"numberCharMystery() failed", 1, 2);

			str = "346";
			numberCharMystery(str);
			Assert::AreEqual(true, areEqualStrings(____, str), L"numberCharMystery() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestabcMystery(){
			char *str;

			str = "gre32344fr";
			abcMystery(str);
			Assert::AreEqual(true, areEqualStrings(____, str), L"abcMystery() failed", 1, 2);

			str = "1234";
			abcMystery(str);
			Assert::AreEqual(true, areEqualStrings(____, str), L"abcMystery() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestconcatMystery(){
			char *a,*b,*c;

			a = "abc";
			b = "def";
			c = concatMystery(a, b);
			Assert::AreEqual(true, areEqualStrings(____, c), L"abcMystery() failed", 1, 2);

			a = "string";
			b = "here";
			c = concatMystery(a, b);
			Assert::AreEqual(true, areEqualStrings(____, c), L"abcMystery() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddMystery(){
			CustomString *one = (CustomString *)malloc(sizeof(CustomString));
			CustomString *two = (CustomString *)malloc(sizeof(CustomString));
			CustomString *res;
			one->str = (char *)malloc(100);
			two->str = (char *)malloc(100);

			strcopy(one->str, "hello");
			strcopy(two->str, "hai");
			one->length = 5;
			two->length = 3;
			res = addMystery(one, two);
			Assert::AreEqual(___, res->length, L"addMystery() failed length incorrect", 1, 2);
			Assert::AreEqual(true, areEqualStrings(____, res->str), L"addMystery() failed", 1, 2);

			strcopy(one->str, "goodstring");
			strcopy(two->str, "badstring");
			one->length = 10;
			two->length = 9;
			res = addMystery(one, two);
			Assert::AreEqual(___, res->length, L"addMystery() failed length incorrect", 1, 2);
			Assert::AreEqual(true, areEqualStrings(____, res->str), L"addMystery() failed", 1, 2);
			
			strcopy(one->str, "ipsum");
			strcopy(two->str, "lorem");
			one->length = 5;
			two->length = 5;
			res = addMystery(one, two);
			Assert::AreEqual(___, res->length, L"addMystery() failed length incorrect", 1, 2);
			Assert::AreEqual(true, areEqualStrings(____, res->str), L"addMystery() failed", 1, 2);
		}
	};
}
