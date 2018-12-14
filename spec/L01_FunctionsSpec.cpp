/*
 
 Note:
 You read the code in L01_Functions.cpp file and understand the behaviour.
 And replace the blanks with correct expected output in this file.
 
 */

#include "stdafx.h"

#include "../src/L01_Functions.cpp"
#include "TestHelperMethods.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class L01_FunctionsSpec
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
        
        //
        // height of tree test cases
        // one, two, three nodes
        //
        
//        6
//
//        1
//        1
//
//        2
//        1 2
//
//        2
//        2 1
//
//        3
//        1 2 3
//        3
//        2 1 3
//        3
//        3 2 1
//
//
//
//        1
//        2
//        2
//        3
//        2
//        3
//
        
        // four, five, six
//        4
//        6
//        4 3 5 2 6 1
//        6
//        5 4 2 3 6 1
//        6
//        93 23 45 11 9 1
//        6
//        1 2 3 4 5 6
//
//
//        4
//        4
//        5
//        6
//
        
        
	};
}
