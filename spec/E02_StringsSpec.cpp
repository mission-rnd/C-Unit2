/*
 
 Note:
 *****important******
 DO NOT modify anything in this file.
 
 Implement the function stubs in E02_Strings.cpp to make
 all the test cases in this file to pass.
 */

#include "stdafx.h"

#include "../src/E02_Strings.cpp"
#include "TestHelperMethods.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
    [TestClass]
    public ref class E02_StringsSpec
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
        
        // test cases
		[TestMethod, Timeout(3000)]
		void TestSumOfMSDs(){
			char *a,*b;
			int res;
			a = "4556456";
			b = "534554465676";
			res = sumOfMSDs(a, b);
			Assert::AreEqual(9, res, L"sumOfMSDs() failed", 1, 2);

			a = "9";
			b = "0";
			res = sumOfMSDs(a, b);
			Assert::AreEqual(9, res, L"sumOfMSDs() failed", 1, 2);

			a = "9435326546546";
			b = "6435435435345453";
			res = sumOfMSDs(a, b);
			Assert::AreEqual(15, res, L"sumOfMSDs() failed", 1, 2);

			a = "0";
			b = "0";
			res = sumOfMSDs(a, b);
			Assert::AreEqual(0, res, L"sumOfMSDs() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void Testsum(){
			char *a, *b, *c;
			a = "0";
			b = "0";
			c = sum(a, b);
			Assert::AreEqual(true, areEqualStrings(c, "0"), L"sum(0,0)failed", 1, 2);

			a = "4534534";
			b = "0";
			c = sum(a, b);
			Assert::AreEqual(true, areEqualStrings(c, "4534534"), L"sum(4534534,0)failed", 1, 2);

			a = "9";
			b = "1";
			c = sum(a, b);
			Assert::AreEqual(true, areEqualStrings(c, "10"), L"sum(9,1)failed", 1, 2);

			a = "99";
			b = "11";
			c = sum(a, b);
			Assert::AreEqual(true, areEqualStrings(c, "110"), L"sum(99,11)failed", 1, 2);

			a = "999999999999999999999999999";
			b = "1";
			c = sum(a, b);
			Assert::AreEqual(true, areEqualStrings(c, "1000000000000000000000000000"), L"sum(999999999999999999999999999,1)failed", 1, 2);

			a = "790383079289753282034840151177";
			b = "728685578060233812895424995760";
			c = sum(a, b);
			Assert::AreEqual(true, areEqualStrings(c, "1519068657349987094930265146937"), L"sum(790383079289753282034840151177,728685578060233812895424995760)failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestreplicateNTimes(){
			char *res, *ans;
			char *s1 = "";
			res = replicateNTimes(s1, 10);
			Assert::AreEqual(true, areEqualStrings("", res), L"replicateNTimes(\"\",10) failed",1,2);

			char *s2 = "hello!@";
			res = replicateNTimes(s2, 1000);
			ans = "hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@hello!@";
			Assert::AreEqual(true, areEqualStrings(res, ans), L"replicateNTimes(hello!@,1000) failed", 1, 2);

			char *s3 = "---This is spartaaa---";
			res = replicateNTimes(s3, 300);
			ans = "---This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa------This is spartaaa---";
			Assert::AreEqual(true, areEqualStrings(res, ans), L"replicateNTimes(---This is spartaaa---,1000) failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestRepeatPositionTimes(){
			char *s,*res,*ans;
			s = "ap";
			res = repeatPositionTimes(s);
			ans = "app";
			Assert::AreEqual(true, areEqualStrings(res, ans), L"repeatPositionTimes() failed", 1, 2);

			s = "ap";
			res = repeatPositionTimes(s);
			ans = "app";
			Assert::AreEqual(true, areEqualStrings(res, ans), L"repeatPositionTimes() failed", 1, 2);

			s = "test";
			res = repeatPositionTimes(s);
			ans = "teessstttt";
			Assert::AreEqual(true, areEqualStrings(res, ans), L"repeatPositionTimes() failed", 1, 2);

			s = "this is a long string";
			res = repeatPositionTimes(s);
			ans = "thhiiissss     iiiiiisssssss        aaaaaaaaa          llllllllllloooooooooooonnnnnnnnnnnnngggggggggggggg               sssssssssssssssstttttttttttttttttrrrrrrrrrrrrrrrrrriiiiiiiiiiiiiiiiiiinnnnnnnnnnnnnnnnnnnnggggggggggggggggggggg";
			Assert::AreEqual(true, areEqualStrings(res, ans), L"repeatPositionTimes() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestscanfInt(){
			char *inp;
			int res;
			inp = "3245345";
			res = scanfInt(inp);
			Assert::AreEqual(3245345, res, L"scanfInt(3245345)failed", 1, 2);

			inp = "998988999";
			res = scanfInt(inp);
			Assert::AreEqual(998988999, res, L"scanfInt(998988999)failed", 1, 2);

			inp = "2147483647";
			res = scanfInt(inp);
			Assert::AreEqual(2147483647, res, L"scanfInt(2147483647)failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestscanfFloat(){
			char *inp;
			float res;
			inp = "10.02";
			res = scanfFloat(inp);
			Assert::AreEqual(10.02f, res, L"scanfFloat(10.02)failed", 1, 2);

			inp = "23.354532";
			res = scanfFloat(inp);
			Assert::AreEqual(23.35453f, res, L"scanfFloat(23.354532)failed", 1, 2);

			inp = "0.0001";
			res = scanfFloat(inp);
			Assert::AreEqual(0.0001f, res, L"scanfFloat(0.0001)failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestgetCommandLine(){
			char *res,*ans;
			char *inp1[]= { "file.exe", "one", "two", "three" };
			ans = "file.exe one two three";
			res = getCommandLine(4, inp1);
			Assert::AreEqual(true, areEqualStrings(ans, res), L"getCommandLine() failed", 1, 2);

			char *inp2[] = { "mrnd.exe", "hello", "there", "three", "haha", "good" };
			ans = "mrnd.exe hello there three haha good";
			res = getCommandLine(6, inp2);
			Assert::AreEqual(true, areEqualStrings(ans, res), L"getCommandLine() failed", 1, 2);

			char *inp3[] = { "this.exe", "testing", "one", "two", "three" };
			ans = "this.exe testing one two three";
			res = getCommandLine(5, inp3);
			Assert::AreEqual(true, areEqualStrings(ans, res), L"getCommandLine() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestgetExecutableName(){
			char *res;
			char *inp1[] = { "file.exe", "one", "two", "three" };
			res = getExecutableName(4, inp1);
			Assert::AreEqual(true, areEqualStrings(inp1[0], res), L"getCommandLine() failed", 1, 2);

			char *inp2[] = { "mrnd.exe", "hello", "there", "three", "haha", "good" };
			res = getExecutableName(6, inp2);
			Assert::AreEqual(true, areEqualStrings(inp2[0], res), L"getCommandLine() failed", 1, 2);

			char *inp3[] = { "this.exe", "testing", "one", "two", "three" };
			res = getExecutableName(5, inp3);
			Assert::AreEqual(true, areEqualStrings(inp3[0], res), L"getCommandLine() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestprintfInt(){
			char *res;
			res = printfInt("%2d", 3);
			Assert::AreEqual(true, areEqualStrings(" 3", res), L"printfInt() failed", 1, 2);

			res = printfInt("%05d", 50);
			Assert::AreEqual(true, areEqualStrings("00050", res), L"printfInt() failed", 1, 2);

			res = printfInt("%06d", 9);
			Assert::AreEqual(true, areEqualStrings("000009", res), L"printfInt() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestprintfFloat(){
			char *res;
			res = printfFloat("%.2f", 1.24563f);
			Assert::AreEqual(true, areEqualStrings("1.24", res), L"printfInt() failed", 1, 2);

			res = printfFloat("%.4f", 0.53520f);
			Assert::AreEqual(true, areEqualStrings("0.5352", res), L"printfInt() failed", 1, 2);

			res = printfFloat("%f", 9.1245324665545654f);
			Assert::AreEqual(true, areEqualStrings("0.124532", res), L"printfInt() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestremoveSpaces(){
			char inp1[100] = "printf (\" hello wor ld\") ;";
			removeSpaces(inp1);
			Assert::AreEqual(true, areEqualStrings(inp1, "printf(\" hello wor ld\");"), L"removeSpaces() failed", 1, 2);
			char inp2[100] = "vector[1] = tenTimes  (     vector[1]   );";
			removeSpaces(inp2);
			Assert::AreEqual(true, areEqualStrings(inp2, "vector[1] = tenTimes(vector[1]);"), L"removeSpaces() failed", 1, 2);
			char inp3[100] = "#include          <  stdio.h>";
			removeSpaces(inp3);
			Assert::AreEqual(true, areEqualStrings(inp3, "#include <stdio.h>"), L"removeSpaces() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void Teststrend(){
			char *a, *b;
			a = "loremipsumlolemipsumloremipsum";
			b = "ipsum";
			Assert::AreEqual(1, strend(a, b), L"strend() failed", 1, 2);

			a = "Von Neumann";
			b = "man";
			Assert::AreEqual(0, strend(a, b), L"strend() failed", 1, 2);

			a = "As he crossed toward the pharmacy at the corner he involuntarily turned his head because of a burst of light that had ricocheted from his temple, and saw, with that quick smile with which we greet a rainbow or a rose, a blindingly white parallelogram of sky being unloaded from the van—a dresser with mirrors across which, as across a cinema screen, passed a flawlessly clear reflection of boughs sliding and swaying not arboreally, but with a human vacillation, produced by the nature of those who were carrying this sky, these boughs, this gliding façade.";
			b = "gliding facade.";
			Assert::AreEqual(1, strend(a, b), L"strend() failed", 1, 2);

			a = "test";
			b = "testing testing";
			Assert::AreEqual(0, strend(a, b), L"strend() failed", 1, 2);
		}
    };
}
