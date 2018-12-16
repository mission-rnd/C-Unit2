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

        //
        // For Recursive functions
        //
        
        //
        // sum of digits and it's mysterious brother
        //
        
        [TestMethod, Timeout(3000)]
        void TestsumOfDigitsSingleDigits(){
            int sum = sumOfDigits(8);
            Assert::AreEqual(___, sum);
            
            sum = sumOfDigits(0);
            Assert::AreEqual(___, sum);
        }
        
        [TestMethod, Timeout(3000)]
        void TestsumOfDigitsDoubleDigits(){
            int sum = sumOfDigits(89);
            Assert::AreEqual(___, sum);
            
            sum = sumOfDigits(10);
            Assert::AreEqual(___, sum);
        }
        
        [TestMethod, Timeout(3000)]
        void TestsumOfDigitsMultipleDigits(){
            int sum = sumOfDigits(8539);
            Assert::AreEqual(___, sum);
            
            sum = sumOfDigits(103323);
            Assert::AreEqual(___, sum);
            
            sum = sumOfDigits(99999);
            Assert::AreEqual(___, sum);
        }
        
        // mysterious one
        [TestMethod, Timeout(3000)]
        void TestsumOfDigitsMysterySingleDigits(){
            int sum = sumOfDigitsMystery(8);
            Assert::AreEqual(___, sum);
            
            sum = sumOfDigitsMystery(0);
            Assert::AreEqual(___, sum);
        }
        
        [TestMethod, Timeout(3000)]
        void TestsumOfDigitsMysteryDoubleDigits(){
            int sum = sumOfDigitsMystery(89);
            Assert::AreEqual(___, sum);
            
            sum = sumOfDigitsMystery(10);
            Assert::AreEqual(___, sum);
        }
        
        [TestMethod, Timeout(3000)]
        void TestsumOfDigitsMysteryMultipleDigits(){
            int sum = sumOfDigitsMystery(8539);
            Assert::AreEqual(___, sum);
            
            sum = sumOfDigitsMystery(103323);
            Assert::AreEqual(___, sum);
            
            sum = sumOfDigitsMystery(99999);
            Assert::AreEqual(___, sum);
        }
        
        [TestMethod, Timeout(3000)]
        void TestsumOfDigitsMysteryJust99s(){
            int sum = sumOfDigitsMystery(99 * 99);
            Assert::AreEqual(___, sum);
            
            sum = sumOfDigitsMystery(999 + 999);
            Assert::AreEqual(___, sum);
            
            sum = sumOfDigitsMystery(99999 * 9);
            Assert::AreEqual(___, sum);
        }
        
        //
        // Let's check the height of some tree
        //
        // Does these tree's grow?
        // What determines the height of the binary search tree?
        // Is there a way to reduce the height?
        // Is there any advantange in having lesser height tree
        // for the same number of nodes?
        // What are these unary tree and balanced tree?
        //
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

        // Let's plant some trees.
        // Tree's are nothing but better-half of our lungs.
        // Don't forget to plant one. Better way of half-organ donation.
        
        // Not let's checkout these functions
        // asking each other to do some part work.
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
        
        // luckyly these above functions does have dead-locked each other
        // like the way we do, you do this, then I will do this.
        // Both waiting eternally with dead-lock, only gets unlocked when one is dead.
        
        //
        // Not checkout these weird sorting methods.
        // These sorting methods looks like they came from some
        // higher-order world, than the normal sort functions that we see.
        // Let's sweetly call them higher-order functions.
        //
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
        
        //
        // from now on read questions in Data Structure books, carefully
        // when they say non-decending order instead of simply saying ascending order.
        //
	};
}
