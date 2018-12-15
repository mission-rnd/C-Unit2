/*
 
 Note:
 *****important******
 DO NOT modify anything in this file.
 
 Implement the function stubs in E03_Types.cpp to make
 all the test cases in this file to pass.
 */

#include "stdafx.h"

#include "../src/E03_Types.cpp"
#include "TestHelperMethods.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
    [TestClass]
    public ref class E03_TypesSpec
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

		int compare(struct base256Number* num1, struct base256Number* num2){
			if ((num1 == NULL) && (num2 == NULL))	return 1;
			else if ((num1 == NULL) || (num2 == NULL))	return 0;
			if (num1->numberOfDigits != num2->numberOfDigits)	return 0;
			for (int i = 0; i < num1->numberOfDigits; i++){
				if (num1->digits[i] != num2->digits[i])	return 0;
			}
			return 1;
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_00(){
			struct base256Number* actualOutput = addInBase256(NULL, NULL);
			struct base256Number* expectedOutput = NULL;
			Assert::AreEqual(1, compare(actualOutput, expectedOutput), L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_01(){
			unsigned int numberOfDigits1 = 1;
			UInt8 digits1[] = { 0 };
			struct base256Number pNumber1 = { numberOfDigits1, digits1 };
			struct base256Number* actualOutput = addInBase256(&pNumber1, NULL);
			struct base256Number expectedOutput = pNumber1;
			Assert::AreEqual(1, compare(actualOutput, &expectedOutput), L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_02(){
			unsigned int numberOfDigits1 = 1;
			UInt8 digits1[] = { 0 };
			struct base256Number pNumber1 = { numberOfDigits1, digits1 };
			struct base256Number* actualOutput = addInBase256(NULL, &pNumber1);
			struct base256Number expectedOutput = pNumber1;
			Assert::AreEqual(1, compare(actualOutput, &expectedOutput), L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_03(){
			unsigned int numberOfDigits1 = 1;
			UInt8 digits1[] = { 0 };
			unsigned int numberOfDigits2 = 1;
			UInt8 digits2[] = { 0 };
			unsigned int numberOfDigitsSum = 1;
			UInt8 digitsSum[] = { 0 };
			struct base256Number pNumber1 = { numberOfDigits1, digits1 };
			struct base256Number pNumber2 = { numberOfDigits2, digits2 };
			struct base256Number* actualOutput = addInBase256(&pNumber1, &pNumber2);
			struct base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
			Assert::AreEqual(1, compare(actualOutput, &expectedOutput), L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_04(){
			unsigned int numberOfDigits1 = 2;
			UInt8 digits1[] = { 0, 12 };
			unsigned int numberOfDigits2 = 2;
			UInt8 digits2[] = { 0, 25 };
			unsigned int numberOfDigitsSum = 2;
			UInt8 digitsSum[] = { 0, 37 };
			struct base256Number pNumber1 = { numberOfDigits1, digits1 };
			struct base256Number pNumber2 = { numberOfDigits2, digits2 };
			struct base256Number* actualOutput = addInBase256(&pNumber1, &pNumber2);
			struct base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
			Assert::AreEqual(1, compare(actualOutput, &expectedOutput), L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_05(){
			unsigned int numberOfDigits1 = 3;
			UInt8 digits1[] = { 0, 12, 45};
			unsigned int numberOfDigits2 = 2;
			UInt8 digits2[] = { 0, 25 };
			unsigned int numberOfDigitsSum = 3;
			UInt8 digitsSum[] = { 0, 37, 45 };
			struct base256Number pNumber1 = { numberOfDigits1, digits1 };
			struct base256Number pNumber2 = { numberOfDigits2, digits2 };
			struct base256Number* actualOutput = addInBase256(&pNumber1, &pNumber2);
			struct base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
			Assert::AreEqual(1, compare(actualOutput, &expectedOutput), L"TestSumOfNodesSmall() failed", 1, 2);
		}

    };
}

