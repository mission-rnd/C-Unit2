/*
 
 Note:
 You read the code in L04_Memory.cpp file and understand the behaviour.
 And replace the blanks with correct expected output in this file.
 
 */

#include "stdafx.h"

#include "../src/L04_Memory.cpp"
#include "TestHelperMethods.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
    [TestClass]
    public ref class L04_MemorySpec
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
		void TestmakeMystery(){
			Assert::AreEqual(true, areEqualStrings(____, makeMystery()), L"makeMystery() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestmemoryFirstByte(){
			Assert::AreEqual(___, memoryFirstByte(0), L"memoryFirstByte(0) failed", 1, 2);
			Assert::AreEqual(___, memoryFirstByte(0xffffff), L"memoryFirstByte(0xffffff) failed", 1, 2);
			Assert::AreEqual(___, memoryFirstByte(0x64), L"memoryFirstByte(0x64) failed", 1, 2);
			Assert::AreEqual(___, memoryFirstByte(0x40000000), L"memoryFirstByte(0x40000000) failed", 1, 2);
			Assert::AreEqual(___, memoryFirstByte(0x7fffffff), L"memoryFirstByte(0x7fffffff) failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestmemoryLastByte(){
			Assert::AreEqual(___, memoryLastByte(0), L"memoryFirstByte(0) failed", 1, 2);
			Assert::AreEqual(___, memoryLastByte(0xffffff), L"memoryFirstByte(0xffffff) failed", 1, 2);
			Assert::AreEqual(___, memoryLastByte(0x64), L"memoryFirstByte(0x64) failed", 1, 2);
			Assert::AreEqual(___, memoryLastByte(0x40000000), L"memoryFirstByte(0x40000000) failed", 1, 2);
			Assert::AreEqual(___, memoryLastByte(0x7fffffff), L"memoryFirstByte(0x7fffffff) failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestohISee(){
			Assert::AreEqual(___, ohISee(), L"ohIsee() failed", 1, 2);
		}
    };
}

