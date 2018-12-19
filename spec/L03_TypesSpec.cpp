/*
 
 Note:
 You read the code in L03_Types.cpp file and understand the behaviour.
 And replace the blanks with correct expected output in this file.
 
 */

#include "stdafx.h"

#include "../src/L03_Types.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
    [TestClass]
    public ref class L03_TypesSpec
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
		[TestMethod]
		void TestcomputeSumAndProduct01(){
			int sum = 0, product = 0;

			sum, product = computeSumAndProduct01(2, 0);
			Assert::AreEqual(___, sum, L"computeSumAndProduct01(2, 0) sum failed", 1, 2);
			Assert::AreEqual(___, product, L"computeSumAndProduct01(2, 0) product failed", 1, 2);

			sum, product = computeSumAndProduct01(2, 4);
			Assert::AreEqual(___, sum, L"computeSumAndProduct01(2, 4) sum failed", 1, 2);
			Assert::AreEqual(___, product, L"computeSumAndProduct01(2, 4) product failed", 1, 2);

			sum, product = computeSumAndProduct01(2, 8);
			Assert::AreEqual(___, sum, L"computeSumAndProduct01(2, 8) sum failed", 1, 2);
			Assert::AreEqual(___, product, L"computeSumAndProduct01(2, 8) product failed", 1, 2);
		}

		[TestMethod]
		void TestcomputeSumAndProduct02(){
			int sum = 0, product = 0;

			computeSumAndProduct02(2, 0, sum, product);
			Assert::AreEqual(___, sum, L"computeSumAndProduct02(2, 0) sum failed", 1, 2);
			Assert::AreEqual(___, product, L"computeSumAndProduct02(2, 0) product failed", 1, 2);

			computeSumAndProduct02(2, 4, sum, product);
			Assert::AreEqual(___, sum, L"computeSumAndProduct02(2, 4) sum failed", 1, 2);
			Assert::AreEqual(___, product, L"computeSumAndProduct02(2, 4) product failed", 1, 2);

			computeSumAndProduct02(2, 8, sum, product);
			Assert::AreEqual(___, sum, L"computeSumAndProduct02(2, 8) sum failed", 1, 2);
			Assert::AreEqual(___, product, L"computeSumAndProduct02(2, 8) product failed", 1, 2);
		}

		[TestMethod]
		void TestcomputeSumAndProduct11(){
			SAP res;

			res = computeSumAndProduct11(19, 0);
			Assert::AreEqual(___, res.sum, L"computeSumAndProduct11(19, 0) sum failed", 1, 2);
			Assert::AreEqual(___, res.product, L"computeSumAndProduct11(19, 0) product failed", 1, 2);

			res = computeSumAndProduct11(6, 5);
			Assert::AreEqual(___, res.sum, L"computeSumAndProduct11(6, 5) sum failed", 1, 2);
			Assert::AreEqual(___, res.product, L"computeSumAndProduct11(6, 5) product failed", 1, 2);

			res = computeSumAndProduct11(3, 2);
			Assert::AreEqual(___, res.sum, L"computeSumAndProduct11(3, 2) sum failed", 1, 2);
			Assert::AreEqual(___, res.product, L"computeSumAndProduct11(3, 2) product failed", 1, 2);
		}

		[TestMethod]
		void TestcomputeSumAndProduct21(){
			SAP *res = (SAP *)malloc(sizeof(SAP));

			computeSumAndProduct21(4, 4, res);
			Assert::AreEqual(___, res->sum, L"computeSumAndProduct21(4, 4) sum failed", 1, 2);
			Assert::AreEqual(___, res->product, L"computeSumAndProduct21(4, 4) product failed", 1, 2);

			computeSumAndProduct21(1, 5, res);
			Assert::AreEqual(___, res->sum, L"computeSumAndProduct21(4, 4) sum failed", 1, 2);
			Assert::AreEqual(___, res->product, L"computeSumAndProduct21(4, 4) product failed", 1, 2);

			computeSumAndProduct21(13, 6, res);
			Assert::AreEqual(___, res->sum, L"computeSumAndProduct21(4, 4) sum failed", 1, 2);
			Assert::AreEqual(___, res->product, L"computeSumAndProduct21(4, 4) product failed", 1, 2);
		}

		[TestMethod]
		void TestcomputeSumAndProduct31(){
			int sum = 0, product = 0;

			computeSumAndProduct31(10, 20, &sum, &product);
			Assert::AreEqual(___, sum, L"omputeSumAndProduct31(10, 20) sum failed", 1, 2);
			Assert::AreEqual(___, product, L"omputeSumAndProduct31(10, 20) product failed", 1, 2);

			computeSumAndProduct31(0, 12, &sum, &product);
			Assert::AreEqual(___, sum, L"omputeSumAndProduct31(0, 12) sum failed", 1, 2);
			Assert::AreEqual(___, product, L"omputeSumAndProduct31(0, 12) product failed", 1, 2);

			computeSumAndProduct31(34, 25, &sum, &product);
			Assert::AreEqual(___, sum, L"omputeSumAndProduct31(34, 25) sum failed", 1, 2);
			Assert::AreEqual(___, product, L"omputeSumAndProduct31(34, 25) product failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestcomputeSumAndProduct42(){
			int *res;

			res = computeSumAndProduct42(15, 1);
			Assert::AreEqual(___, res[0], L"computeSumAndProduct42(15, 1) sum failed", 1, 2);
			Assert::AreEqual(___, res[1], L"computeSumAndProduct42(15, 1) product failed", 1, 2);

			res = computeSumAndProduct42(31, 3);
			Assert::AreEqual(___, res[0], L"computeSumAndProduct42(31, 3) sum failed", 1, 2);
			Assert::AreEqual(___, res[1], L"computeSumAndProduct42(31, 3) product failed", 1, 2);

			res = computeSumAndProduct42(12, 5);
			Assert::AreEqual(___, res[0], L"computeSumAndProduct42(12, 5) sum failed", 1, 2);
			Assert::AreEqual(___, res[1], L"computeSumAndProduct42(12, 5) product failed", 1, 2);
		}

		[TestMethod]
		void TestcomputeSumAndProduct43(){
			SAP *res;

			res = computeSumAndProduct43(25, 11);
			Assert::AreEqual(___, res->sum, L"computeSumAndProduct43(25, 11) sum failed", 1, 2);
			Assert::AreEqual(___, res->product, L"computeSumAndProduct43(25, 11) product failed", 1, 2);

			res = computeSumAndProduct43(21, 4);
			Assert::AreEqual(___, res->sum, L"computeSumAndProduct43(21, 4) sum failed", 1, 2);
			Assert::AreEqual(___, res->product, L"computeSumAndProduct43(21, 4) product failed", 1, 2);

			res = computeSumAndProduct43(2, 7);
			Assert::AreEqual(___, res->sum, L"computeSumAndProduct43(2, 7) sum failed", 1, 2);
			Assert::AreEqual(___, res->product, L"computeSumAndProduct43(2, 7) product failed", 1, 2);
		}

		[TestMethod]
		void TestcomputeSumAndProduct42WithMystery(){
			int *res;

			res = computeSumAndProduct42WithMystery(15, 1);
			Assert::AreEqual(___, res[0], L"computeSumAndProduct42WithMystery(15, 1) sum failed", 1, 2);
			Assert::AreEqual(___, res[1], L"computeSumAndProduct42WithMystery(15, 1) product failed", 1, 2);

			res = computeSumAndProduct42WithMystery(31, 3);
			Assert::AreEqual(___, res[0], L"computeSumAndProduct42WithMystery(31, 3) sum failed", 1, 2);
			Assert::AreEqual(___, res[1], L"computeSumAndProduct42WithMystery(31, 3) product failed", 1, 2);

			res = computeSumAndProduct42WithMystery(12, 5);
			Assert::AreEqual(___, res[0], L"computeSumAndProduct42WithMystery(12, 5) sum failed", 1, 2);
			Assert::AreEqual(___, res[1], L"computeSumAndProduct42WithMystery(12, 5) product failed", 1, 2);
		}

		[TestMethod]
		void TestcomputeSumAndProduct43WithMystery(){
			SAP *res;

			res = computeSumAndProduct43WithMystery(25, 11);
			Assert::AreEqual(___, res->sum, L"computeSumAndProduct43WithMystery(25, 11) sum failed", 1, 2);
			Assert::AreEqual(___, res->product, L"computeSumAndProduct43WithMystery(25, 11) product failed", 1, 2);

			res = computeSumAndProduct43WithMystery(21, 4);
			Assert::AreEqual(___, res->sum, L"computeSumAndProduct43WithMystery(21, 4) sum failed", 1, 2);
			Assert::AreEqual(___, res->product, L"computeSumAndProduct43WithMystery(21, 4) product failed", 1, 2);

			res = computeSumAndProduct43(2, 7);
			Assert::AreEqual(___, res->sum, L"computeSumAndProduct43WithMystery(2, 7) sum failed", 1, 2);
			Assert::AreEqual(___, res->product, L"computeSumAndProduct43WithMystery(2, 7) product failed", 1, 2);
		}
    };
}

