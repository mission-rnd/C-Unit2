/*
 
 Note:
 *****important******
 DO NOT modify anything in this file.
 
 Implement the function stubs in E04_Memory.cpp to make
 all the test cases in this file to pass.
 */

#include "stdafx.h"

#include "../src/E04_Memory.cpp"
#include "TestHelperMethods.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
    [TestClass]
    public ref class E04_MemorySpec
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
		void TestprimeFactorsSmall(){
			DynamicList *primes;
			primes = primeFactors(10);
			int ans1[] = { 2, 5 };
			Assert::AreEqual(2, primes->count, L"TestprimeFactorsSmall() failed", 1, 2);
			Assert::AreEqual(true, areEqualArrays(primes->list, ans1, 2), L"TestprimeFactorsSmall() failed", 1, 2);
			primes = primeFactors(75);
			int ans2[] = { 3, 5, 5 };
			Assert::AreEqual(3, primes->count, L"TestprimeFactorsSmall() failed", 1, 2);
			Assert::AreEqual(true, areEqualArrays(primes->list, ans2, 3), L"TestprimeFactorsSmall() failed", 1, 2);
			
			primes = primeFactors(96);
			int ans3[] = { 2, 2, 2, 2, 2, 3 };
			Assert::AreEqual(6, primes->count, L"TestprimeFactorsSmall() failed", 1, 2);
			Assert::AreEqual(true, areEqualArrays(primes->list, ans3, 6), L"TestprimeFactorsSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestprimeFactorsMedium(){
			DynamicList *primes;
			primes = primeFactors(19250);
			int ans1[] = { 2, 5, 5, 5, 7, 11 };
			Assert::AreEqual(6, primes->count, L"TestprimeFactorsMedium() failed", 1, 2);
			Assert::AreEqual(true, areEqualArrays(primes->list, ans1, 6), L"TestprimeFactorsMedium() failed", 1, 2);
			primes = primeFactors(31247);
			int ans2[] = { 31247 };
			Assert::AreEqual(1, primes->count, L"TestprimeFactorsMedium() failed", 1, 2);
			Assert::AreEqual(true, areEqualArrays(primes->list, ans2, 1), L"TestprimeFactorsMedium() failed", 1, 2);

			primes = primeFactors(78057);
			int ans3[] = { 3, 3, 3, 7, 7, 59 };
			Assert::AreEqual(6, primes->count, L"TestprimeFactorsMedium() failed", 1, 2);
			Assert::AreEqual(true, areEqualArrays(primes->list, ans3, 6), L"TestprimeFactorsMedium() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestprimeFactorsLarge(){
			DynamicList *primes;
			primes = primeFactors(1073741824);
			int ans1[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
			Assert::AreEqual(30, primes->count, L"TestprimeFactorsLarge() failed", 1, 2);
			Assert::AreEqual(true, areEqualArrays(primes->list, ans1, 30), L"TestprimeFactorsLarge() failed", 1, 2);
			primes = primeFactors(26165843);
			int ans2[] = { 11, 71, 33503 };
			Assert::AreEqual(3, primes->count, L"TestprimeFactorsLarge() failed", 1, 2);
			Assert::AreEqual(true, areEqualArrays(primes->list, ans2, 3), L"TestprimeFactorsLarge() failed", 1, 2);

			primes = primeFactors(691979840);
			int ans3[] = { 2, 2, 2, 2, 2, 2, 5, 23, 149, 631 };
			Assert::AreEqual(10, primes->count, L"TestprimeFactorsLarge() failed", 1, 2);
			Assert::AreEqual(true, areEqualArrays(primes->list, ans3, 10), L"TestprimeFactorsLarge() failed", 1, 2);
		}
    };
}

