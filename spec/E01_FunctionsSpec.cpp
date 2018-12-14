/*
 
 Note:
 *****important******
 DO NOT modify anything in this file.
 
 Implement the function stubs in E01_Functions.cpp to make
 all the test cases in this file to pass.
 */

#include "stdafx.h"

#include "../src/E01_Functions.cpp"
#include "TestHelperMethods.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
    [TestClass]
    public ref class E01_FunctionsSpec
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
        // Number of leaf nodes
//        6
//        1
//        1
//        2
//        1 2
//        2
//        2 1
//        3
//        1 2 3
//        3
//        2 1 3
//        3
//        3 2 1
//
//
//        1
//        1
//        1
//        1
//        2
//        1
    };
}
