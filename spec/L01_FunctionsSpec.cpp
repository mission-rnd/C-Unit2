/*
 
 Note:
 You read the code in L01_Functions.cpp file and understand the behaviour.
 And replace the blanks with correct expected output in this file.
 
 */

#include "stdafx.h"

#include "../src/L01_Functions.cpp"
#include "TestHelperMethods.h"
#include "../src/BinaryTree.h"

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
		[TestMethod, Timeout(3000)]
		void TestheightOfTreeEmptyTree(){
			int height = heightOfTree(NULL);
			Assert::AreEqual(___, height);
		}

		[TestMethod, Timeout(3000)]
		void TestheightOfTreeUnaryTree(){
			int nodeValues[] = { 1, 2, 3, 4, 5, 6, 7};
			treeNode *root = createTree(nodeValues, 7);
			int height = heightOfTree(root);
			Assert::AreEqual(___, height);
		}

		[TestMethod, Timeout(3000)]
		void TestheightOfTreeBalancedTree(){
			int nodeValues[] = { 4, 6, 2, 1, 3, 5, 7 };
			treeNode *root = createTree(nodeValues, 7);
			int height = heightOfTree(root);
			Assert::AreEqual(___, height);
		}

		[TestMethod, Timeout(3000)]
		void TestheightOfTreeSmall(){
			treeNode *root;
			int height;
			int nodevalues1[] = { 1 };
			root = createTree(nodevalues1, 1);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);

			int nodevalues2[] = { 1, 1 };
			root = createTree(nodevalues2, 2);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);

			int nodevalues3[] = { 1, 2, 2 };
			root = createTree(nodevalues3, 3);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);

			int nodevalues4[] = { 1,2,3 };
			root = createTree(nodevalues4, 3);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);

			int nodevalues5[] = { 2, 1, 3 };
			root = createTree(nodevalues5, 3);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);

			int nodevalues6[] = { 3, 2, 1 };
			root = createTree(nodevalues6, 3);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);
		}

		[TestMethod, Timeout(3000)]
		void TestheightOfTreeMedium(){
			treeNode *root;
			int height;
			int nodevalues1[] = { 1, 3, 5, 2, 5, 34, 3 };
			root = createTree(nodevalues1, 7);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);

			int nodevalues2[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			root = createTree(nodevalues2, 9);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);

			int nodevalues3[] = { 2, 4, 1, 4, 7, 3, 6, 8, 3 };
			root = createTree(nodevalues3, 9);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);

			int nodevalues4[] = { 4, 3, 5, 2, 6, 1 };
			root = createTree(nodevalues4, 6);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);

			int nodevalues5[] = { 5, 4, 2, 3, 6, 1 };
			root = createTree(nodevalues5, 6);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);

			int nodevalues6[] = { 93, 23, 45, 11, 9, 1 };
			root = createTree(nodevalues6, 6);
			height = heightOfTree(root);
			Assert::AreEqual(___, height);
		}

		[TestMethod, Timeout(3000)]
		void TestFunctionsCallingEachOther(){
			int res;
			int numbers1[] = { 1, 2, 3, 4, 5, 6 };
			res = youDoTheWork(numbers1, 6);
			Assert::AreEqual(___, res, L"youDoTheWork() failed", 1, 2);

			int numbers2[] = { 3, 5};
			res = youDoTheWork(numbers2, 2);
			Assert::AreEqual(___, res, L"youDoTheWork() failed", 1, 2);

			int numbers3[] = { 1, 2, 3, 4, 5, 6 };
			res = youDoTheWork(numbers3, 6);
			Assert::AreEqual(___, res, L"youDoTheWork() failed", 1, 2);

			int numbers4[] = { 52 };
			res = youDoTheWork(numbers4, 1);
			Assert::AreEqual(___, res, L"youDoTheWork() failed", 1, 2);

			int numbers5[] = { 3, 5, 6, 3, 72, 6 };
			res = firstYouDoThisPart(numbers5, 6);
			Assert::AreEqual(___, res, L"youDoTheWork() failed", 1, 2);

			int numbers6[] = { 1 };
			res = youDoTheWork(numbers6, 1);
			Assert::AreEqual(___, res, L"youDoTheWork() failed", 1, 2);

			int numbers7[] = { 90,20 };
			res = youDoTheWork(numbers7, 2);
			Assert::AreEqual(___, res, L"youDoTheWork() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestsortNonDescending(){
			int numbers1[] = {1,3,1,4,2,45,3};
			int ans1[] =  ______ ;
			sortNonDescending(numbers1, 7);
			Assert::AreEqual(true, areEqualArrays(numbers1, ans1, 7), L"sortNonDescending() failed", 1, 2);

			int numbers2[] = { 1, 1, 1, 1, 1, 1, 1 };
			int ans2[] = ______;
			sortNonDescending(numbers2, 7);
			Assert::AreEqual(true, areEqualArrays(numbers2, ans2, 7), L"sortNonDescending() failed", 1, 2);

			int numbers3[] = { 1, 2, 3, 4, 5, 6 };
			int ans3[] = ______;
			sortNonDescending(numbers3, 6);
			Assert::AreEqual(true, areEqualArrays(numbers3, ans3, 6), L"sortNonDescending() failed", 1, 2);

		}

		[TestMethod, Timeout(3000)]
		void TestsortNonAscending(){
			int numbers1[] = { 1, 5, 3, 2, 5, 3, 3 };
			int ans1[] = ______;
			sortNonAscending(numbers1, 7);
			Assert::AreEqual(true, areEqualArrays(numbers1, ans1, 7), L"sortNonDescending() failed", 1, 2);

			int numbers2[] = { 0,0,0,0,0,0,0 };
			int ans2[] = ______;
			sortNonAscending(numbers2, 7);
			Assert::AreEqual(true, areEqualArrays(numbers2, ans2, 7), L"sortNonDescending() failed", 1, 2);

			int numbers3[] = { 6, 5, 4, 3, 2, 1 };
			int ans3[] = ______;
			sortNonAscending(numbers3, 6);
			Assert::AreEqual(true, areEqualArrays(numbers3, ans3, 6), L"sortNonDescending() failed", 1, 2);

		}

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
