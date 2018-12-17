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

		int compare(Base256Number *num1, Base256Number *num2){
            if (num1->numberOfDigits != num2->numberOfDigits) {
                return 0;
            }
			for (unsigned int i = 0; i < num1->numberOfDigits; i++){
                if (num1->digits[i] != num2->digits[i]) {
                    return 0;
                }
			}
			return 1;
		}
        
        int getNumberOfDigits(int n, int base) {
            int numberOfDigits = 0;
            do {
                numberOfDigits++;
                n /= base;
            } while (n > 0);
            
            return numberOfDigits;
        }
        
        int saveNumberInString(char *oStr, int n) {
            char charDigit[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
            int nDigits = getNumberOfDigits(n, 10);
            for (int pos = nDigits - 1; pos >= 0 ; pos--) {
                oStr[pos] = charDigit[n % 10];
                n /= 10;
            }
            return nDigits;
        }
        
        // {4, [11, 254, 0, 15] }
        char *formatBase256Number(Base256Number *pNumber) {
            
            // find the result string length
            int totalStringLength = 7; // constants in format format: {%d, [%a] }
            
            totalStringLength += getNumberOfDigits(pNumber->numberOfDigits, 10);
            for (unsigned int i = 0; i < pNumber->numberOfDigits; i++) {
                totalStringLength += getNumberOfDigits(pNumber->digits[i], 10);
            }
            
            totalStringLength += 2*(pNumber->numberOfDigits - 1);
            
            // reserve memory
            char *formatString = (char *)malloc(totalStringLength+1);
            formatString[totalStringLength] = '\0';
            
            // copy first part
            formatString[0] = '('; // assert treats this differently '{';
            
            int currentPos = 1;
            // fill the number in the given format
            int numberOfDigits = pNumber->numberOfDigits;
            
            currentPos += saveNumberInString(&formatString[currentPos], numberOfDigits);
            
            formatString[currentPos] = ',';
            formatString[currentPos + 1] = ' ';
            formatString[currentPos + 2] = '[';
            currentPos += 3;
            
            // now numbers in the array
            for (int i = 0 ; i < numberOfDigits; i++) {
                int b256Digit = pNumber->digits[i];
                
                currentPos += saveNumberInString(&formatString[currentPos], b256Digit);
                formatString[currentPos] = ',';
                formatString[currentPos + 1] = ' ';
                currentPos += 2;
            }
            currentPos -= 2;
            
            // close array and end the string
            formatString[currentPos] = ']';
            formatString[currentPos + 1] = ' ';
            formatString[currentPos + 2] = ')'; // assert treats this differently '}';
            
            // set the terminations char
            formatString[totalStringLength] = '\0';
            
            return formatString;
        }

        
        // Print base 256
		[TestMethod, Timeout(3000)]
		void TestprintBase256Number_00(){
			char format[] = "IPV4: %D";
			unsigned int numberOfDigits = 4;
			UInt8 digits[] = {15, 0, 255, 255};
			Base256Number pNumber = { numberOfDigits, digits };
			char expectedOutput[] = "IPV4: 255.255.0.15";
			char* actualOutput = printBase256Number(format, &pNumber);
            Assert::AreEqual(true, areEqualStrings(actualOutput, expectedOutput),
                             L"\nExpect: \"" + (gcnew String(expectedOutput)) +
                             L"\"\nActual: \"" + (gcnew String(actualOutput)) + L"\"",
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestprintBase256Number_01(){
			char format[] = "IPV6: %H";
			unsigned int numberOfDigits = 6;
			UInt8 digits[] = { 11, 10, 15, 0, 255, 255 };
			Base256Number pNumber = { numberOfDigits, digits };
			char expectedOutput[] = "IPV6: ff:ff:00:0f:0a:0b";
			char* actualOutput = printBase256Number(format, &pNumber);
            Assert::AreEqual(true, areEqualStrings(actualOutput, expectedOutput),
                             L"\nExpect: \"" + (gcnew String(expectedOutput)) +
                             L"\"\nActual: \"" + (gcnew String(actualOutput)) + L"\"",
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestprintBase256Number_02(){
            char format[] = "Single Digit: %D?";
			unsigned int numberOfDigits = 1;
			UInt8 digits[] = { 225 };
			Base256Number pNumber = { numberOfDigits, digits };
			char expectedOutput[] = "Single Digit: 225?";
			char* actualOutput = printBase256Number(format, &pNumber);
            Assert::AreEqual(true, areEqualStrings(actualOutput, expectedOutput),
                             L"\nExpect: \"" + (gcnew String(expectedOutput)) +
                             L"\"\nActual: \"" + (gcnew String(actualOutput)) + L"\"",
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestprintBase256Number_03(){
            char format[] = "Just Zero: %H?";
			unsigned int numberOfDigits = 1;
			UInt8 digits[] = { 0 };
			Base256Number pNumber = { numberOfDigits, digits };
			char expectedOutput[] = "Just Zero: 00?";
			char* actualOutput = printBase256Number(format, &pNumber);
            Assert::AreEqual(true, areEqualStrings(actualOutput, expectedOutput),
                             L"\nExpect: \"" + (gcnew String(expectedOutput)) +
                             L"\"\nActual: \"" + (gcnew String(actualOutput)) + L"\"",
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestprintBase256Number_04(){
			char format[] =  "Just Zero: %D";
			unsigned int numberOfDigits = 1;
			UInt8 digits[] = { 0 };
			Base256Number pNumber = { numberOfDigits, digits };
			char expectedOutput[] =  "Just Zero: 0";
			char* actualOutput = printBase256Number(format, &pNumber);
            Assert::AreEqual(true, areEqualStrings(actualOutput, expectedOutput),
                             L"\nExpect: \"" + (gcnew String(expectedOutput)) +
                             L"\"\nActual: \"" + (gcnew String(actualOutput)) + L"\"",
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestprintBase256Number_05(){
			char format[] = "so %H looks like";
			unsigned int numberOfDigits = 3;
			UInt8 digits[] = { 15, 0, 255 };
			Base256Number pNumber = { numberOfDigits, digits };
			char expectedOutput[] = "so ff:00:0f looks like";
			char* actualOutput = printBase256Number(format, &pNumber);
            Assert::AreEqual(true, areEqualStrings(actualOutput, expectedOutput),
                             L"\nExpect: \"" + (gcnew String(expectedOutput)) +
                             L"\"\nActual: \"" + (gcnew String(actualOutput)) + L"\"",
                             1, 2);
		}
    
        [TestMethod, Timeout(3000)]
        void TestprintBase256Number_06(){
            char format[] = "so %D looks like";
            unsigned int numberOfDigits = 3;
            UInt8 digits[] = {15, 0, 255 };
            Base256Number pNumber = { numberOfDigits, digits };
            char expectedOutput[] = "so 255.0.15 looks like";
            char* actualOutput = printBase256Number(format, &pNumber);
            Assert::AreEqual(true, areEqualStrings(actualOutput, expectedOutput),
                             L"\nExpect: \"" + (gcnew String(expectedOutput)) +
                             L"\"\nActual: \"" + (gcnew String(actualOutput)) + L"\"",
                             1, 2);
        }

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_00(){
			unsigned int numberOfDigits1 = 1;
			UInt8 digits1[] = { 0 };
			unsigned int numberOfDigits2 = 1;
			UInt8 digits2[] = { 0 };
			unsigned int numberOfDigitsSum = 1;
			UInt8 digitsSum[] = { 0 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			Base256Number* actualOutput = addInBase256(&pNumber1, &pNumber2);
			Base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_01(){
			unsigned int numberOfDigits1 = 2;
			UInt8 digits1[] = { 0, 12 };
			unsigned int numberOfDigits2 = 2;
			UInt8 digits2[] = { 0, 25 };
			unsigned int numberOfDigitsSum = 2;
			UInt8 digitsSum[] = { 0, 37 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			Base256Number* actualOutput = addInBase256(&pNumber1, &pNumber2);
			Base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_02(){
			unsigned int numberOfDigits1 = 3;
			UInt8 digits1[] = { 0, 12, 45};
			unsigned int numberOfDigits2 = 2;
			UInt8 digits2[] = { 0, 25 };
			unsigned int numberOfDigitsSum = 3;
			UInt8 digitsSum[] = { 0, 37, 45 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			Base256Number* actualOutput = addInBase256(&pNumber1, &pNumber2);
			Base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_03(){
			unsigned int numberOfDigits1 = 2;
			UInt8 digits1[] = { 0, 255 };
			unsigned int numberOfDigits2 = 2;
			UInt8 digits2[] = { 0, 255 };
			unsigned int numberOfDigitsSum = 3;
			UInt8 digitsSum[] = { 0, 254, 1 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			Base256Number* actualOutput = addInBase256(&pNumber1, &pNumber2);
			Base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_04(){
			unsigned int numberOfDigits1 = 4;
			UInt8 digits1[] = { 17, 29, 61, 74 };
			unsigned int numberOfDigits2 = 2;
			UInt8 digits2[] = { 66, 6 };
			unsigned int numberOfDigitsSum = 4;
			UInt8 digitsSum[] = { 83, 35, 61, 74 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			Base256Number* actualOutput = addInBase256(&pNumber1, &pNumber2);
			Base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_05(){
			unsigned int numberOfDigits1 = 5;
			UInt8 digits1[] = { 61, 74, 29, 89, 52 };
			unsigned int numberOfDigits2 = 7;
			UInt8 digits2[] = { 78, 152, 75, 45, 125, 137, 247 };
			unsigned int numberOfDigitsSum = 7;
			UInt8 digitsSum[] = { 139, 226, 104, 134, 177, 137, 247 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			Base256Number* actualOutput = addInBase256(&pNumber1, &pNumber2);
			Base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_06(){
			unsigned int numberOfDigits1 = 100;
			UInt8 digits1[] = { 118, 37, 190, 252, 36, 55, 107, 134, 227, 235, 230, 82, 94, 34, 230, 238, 20, 160, 142, 198, 182, 94, 53, 160, 64, 96, 15, 40, 177, 230, 3, 52, 30, 238, 36, 159, 172, 227, 192, 182, 235, 183, 16, 161, 242, 24, 254, 217, 150, 65, 242, 6, 251, 92, 74, 35, 115, 35, 10, 37, 188, 251, 253, 147, 74, 100, 206, 64, 108, 43, 226, 140, 209, 194, 57, 27, 254, 78, 167, 12, 172, 10, 109, 110, 16, 123, 218, 13, 188, 211, 172, 52, 183, 46, 159, 228, 169, 120, 230, 107 };
			unsigned int numberOfDigits2 = 172;
			UInt8 digits2[] = { 221, 16, 51, 237, 175, 231, 128, 154, 22, 49, 128, 117, 239, 126, 230, 35, 168, 140, 20, 25, 150, 120, 196, 23, 24, 171, 248, 170, 188, 22, 206, 136, 145, 96, 29, 213, 158, 201, 78, 124, 64, 117, 219, 144, 115, 92, 254, 155, 124, 216, 20, 58, 44, 231, 216, 179, 213, 198, 38, 168, 169, 105, 50, 24, 63, 200, 83, 30, 4, 15, 59, 66, 151, 232, 139, 1, 82, 226, 14, 10, 6, 5, 158, 119, 89, 177, 211, 109, 53, 41, 2, 114, 185, 55, 218, 44, 125, 2, 165, 233, 232, 255, 134, 221, 22, 135, 91, 120, 161, 19, 145, 70, 179, 90, 128, 79, 184, 233, 210, 42, 119, 83, 242, 37, 197, 56, 126, 58, 132, 1, 78, 194, 24, 95, 244, 12, 124, 145, 3, 174, 48, 142, 82, 5, 16, 131, 17, 43, 159, 181, 171, 165, 115, 174, 19, 58, 20, 16, 0, 71, 224, 29, 233, 40, 86, 1, 219, 232, 157, 14, 244, 128 };
			unsigned int numberOfDigitsSum = 172;
			UInt8 digitsSum[] = { 83, 54, 241, 233, 212, 30, 236, 32, 250, 28, 103, 200, 77, 161, 204, 18, 189, 44, 163, 223, 76, 215, 249, 183, 88, 11, 8, 211, 109, 253, 209, 188, 175, 78, 66, 116, 75, 173, 15, 51, 44, 45, 236, 49, 102, 117, 252, 117, 19, 26, 7, 65, 39, 68, 35, 215, 72, 234, 48, 205, 101, 101, 48, 172, 137, 44, 34, 95, 112, 58, 29, 207, 104, 171, 197, 28, 80, 49, 182, 22, 178, 15, 11, 230, 105, 44, 174, 123, 241, 252, 174, 166, 112, 102, 121, 17, 39, 123, 139, 85, 233, 255, 134, 221, 22, 135, 91, 120, 161, 19, 145, 70, 179, 90, 128, 79, 184, 233, 210, 42, 119, 83, 242, 37, 197, 56, 126, 58, 132, 1, 78, 194, 24, 95, 244, 12, 124, 145, 3, 174, 48, 142, 82, 5, 16, 131, 17, 43, 159, 181, 171, 165, 115, 174, 19, 58, 20, 16, 0, 71, 224, 29, 233, 40, 86, 1, 219, 232, 157, 14, 244, 128 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			Base256Number* actualOutput = addInBase256(&pNumber1, &pNumber2);
			Base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_07(){
			unsigned int numberOfDigits1 = 149;
			UInt8 digits1[] = { 131, 215, 200, 180, 5, 89, 222, 39, 25, 223, 170, 75, 171, 155, 156, 131, 207, 21, 158, 151, 191, 89, 139, 218, 75, 245, 25, 101, 235, 102, 62, 38, 80, 140, 121, 174, 41, 104, 134, 97, 245, 86, 164, 64, 168, 146, 27, 63, 255, 39, 230, 87, 24, 204, 191, 52, 255, 42, 246, 162, 110, 249, 24, 64, 143, 54, 181, 190, 224, 222, 70, 33, 116, 112, 10, 182, 54, 13, 195, 250, 148, 239, 55, 206, 233, 144, 138, 229, 216, 192, 72, 65, 36, 7, 222, 217, 150, 89, 55, 182, 202, 81, 157, 53, 211, 71, 249, 161, 104, 241, 250, 8, 127, 19, 248, 139, 232, 162, 252, 32, 82, 31, 224, 99, 123, 245, 219, 50, 93, 222, 127, 88, 124, 46, 124, 66, 33, 244, 38, 182, 218, 135, 140, 129, 127, 52, 69, 95, 53 };
			unsigned int numberOfDigits2 = 258;
			UInt8 digits2[] = { 43, 160, 144, 69, 120, 123, 170, 207, 246, 38, 180, 34, 137, 177, 140, 136, 182, 154, 51, 134, 13, 252, 113, 170, 57, 39, 0, 108, 115, 202, 3, 147, 72, 63, 187, 63, 133, 118, 80, 240, 226, 14, 60, 254, 206, 60, 43, 212, 255, 156, 78, 228, 15, 203, 43, 56, 32, 109, 42, 207, 229, 52, 163, 131, 41, 249, 134, 67, 129, 18, 138, 72, 84, 19, 242, 153, 181, 128, 116, 189, 86, 18, 63, 33, 116, 80, 66, 75, 191, 142, 234, 44, 21, 38, 167, 96, 173, 241, 183, 58, 18, 202, 203, 200, 41, 157, 236, 135, 243, 18, 123, 13, 53, 230, 80, 165, 62, 10, 60, 245, 157, 57, 71, 114, 152, 189, 48, 9, 254, 199, 91, 226, 31, 212, 216, 171, 67, 119, 6, 252, 129, 66, 95, 130, 123, 242, 88, 51, 132, 194, 85, 130, 139, 94, 30, 231, 180, 243, 105, 190, 202, 20, 15, 69, 201, 173, 72, 132, 201, 137, 104, 173, 162, 206, 231, 249, 214, 206, 94, 116, 130, 34, 235, 39, 185, 245, 11, 63, 253, 9, 207, 209, 3, 190, 1, 186, 82, 29, 84, 188, 27, 15, 96, 150, 150, 39, 30, 86, 128, 70, 68, 41, 124, 65, 146, 87, 104, 209, 59, 235, 0, 247, 154, 254, 72, 121, 228, 35, 172, 86, 126, 198, 113, 161, 246, 186, 54, 97, 239, 12, 99, 31, 73, 222, 230, 77, 33, 28, 190, 211, 226, 17, 171, 34, 113, 93, 103, 222 };
			unsigned int numberOfDigitsSum = 258;
			UInt8 digitsSum[] = {174, 119, 89, 250, 125, 212, 136, 247, 15, 6, 95, 110, 52, 77, 41, 12, 134, 176, 209, 29, 205, 85, 253, 132, 133, 28, 26, 209, 94, 49, 66, 185, 152, 203, 52, 238, 174, 222, 214, 81, 216, 101, 224, 62, 119, 207, 70, 19, 255, 196, 52, 60, 40, 151, 235, 108, 31, 152, 32, 114, 84, 46, 188, 195, 184, 47, 60, 2, 98, 241, 208, 105, 200, 131, 252, 79, 236, 141, 55, 184, 235, 1, 119, 239, 93, 225, 204, 48, 152, 79, 51, 110, 57, 45, 133, 58, 68, 75, 239, 240, 220, 27, 105, 254, 252, 228, 229, 41, 92, 4, 118, 22, 180, 249, 72, 49, 39, 173, 56, 22, 240, 88, 39, 214, 19, 179, 12, 60, 91, 166, 219, 58, 156, 2, 85, 238, 100, 107, 45, 178, 92, 202, 235, 3, 251, 38, 158, 146, 185, 194, 85, 130, 139, 94, 30, 231, 180, 243, 105, 190, 202, 20, 15, 69, 201, 173, 72, 132, 201, 137, 104, 173, 162, 206, 231, 249, 214, 206, 94, 116, 130, 34, 235, 39, 185, 245, 11, 63, 253, 9, 207, 209, 3, 190, 1, 186, 82, 29, 84, 188, 27, 15, 96, 150, 150, 39, 30, 86, 128, 70, 68, 41, 124, 65, 146, 87, 104, 209, 59, 235, 0, 247, 154, 254, 72, 121, 228, 35, 172, 86, 126, 198, 113, 161, 246, 186, 54, 97, 239, 12, 99, 31, 73, 222, 230, 77, 33, 28, 190, 211, 226, 17, 171, 34, 113, 93, 103, 222};
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			Base256Number* actualOutput = addInBase256(&pNumber1, &pNumber2);
			Base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestaddInBase256_08(){
			unsigned int numberOfDigits1 = 149;
			UInt8 digits1[] = { 131, 215, 200, 180, 5, 89, 222, 39, 25, 223, 170, 75, 171, 155, 156, 131, 207, 21, 158, 151, 191, 89, 139, 218, 75, 245, 25, 101, 235, 102, 62, 38, 80, 140, 121, 174, 41, 104, 134, 97, 245, 86, 164, 64, 168, 146, 27, 63, 255, 39, 230, 87, 24, 204, 191, 52, 255, 42, 246, 162, 110, 249, 24, 64, 143, 54, 181, 190, 224, 222, 70, 33, 116, 112, 10, 182, 54, 13, 195, 250, 148, 239, 55, 206, 233, 144, 138, 229, 216, 192, 72, 65, 36, 7, 222, 217, 150, 89, 55, 182, 202, 81, 157, 53, 211, 71, 249, 161, 104, 241, 250, 8, 127, 19, 248, 139, 232, 162, 252, 32, 82, 31, 224, 99, 123, 245, 219, 50, 93, 222, 127, 88, 124, 46, 124, 66, 33, 244, 38, 182, 218, 135, 140, 129, 127, 52, 69, 95, 53 };
			unsigned int numberOfDigits2 = 258;
			UInt8 digits2[] = { 43, 160, 144, 69, 120, 123, 170, 207, 246, 38, 180, 34, 137, 177, 140, 136, 182, 154, 51, 134, 13, 252, 113, 170, 57, 39, 0, 108, 115, 202, 3, 147, 72, 63, 187, 63, 133, 118, 80, 240, 226, 14, 60, 254, 206, 60, 43, 212, 255, 156, 78, 228, 15, 203, 43, 56, 32, 109, 42, 207, 229, 52, 163, 131, 41, 249, 134, 67, 129, 18, 138, 72, 84, 19, 242, 153, 181, 128, 116, 189, 86, 18, 63, 33, 116, 80, 66, 75, 191, 142, 234, 44, 21, 38, 167, 96, 173, 241, 183, 58, 18, 202, 203, 200, 41, 157, 236, 135, 243, 18, 123, 13, 53, 230, 80, 165, 62, 10, 60, 245, 157, 57, 71, 114, 152, 189, 48, 9, 254, 199, 91, 226, 31, 212, 216, 171, 67, 119, 6, 252, 129, 66, 95, 130, 123, 242, 88, 51, 132, 194, 85, 130, 139, 94, 30, 231, 180, 243, 105, 190, 202, 20, 15, 69, 201, 173, 72, 132, 201, 137, 104, 173, 162, 206, 231, 249, 214, 206, 94, 116, 130, 34, 235, 39, 185, 245, 11, 63, 253, 9, 207, 209, 3, 190, 1, 186, 82, 29, 84, 188, 27, 15, 96, 150, 150, 39, 30, 86, 128, 70, 68, 41, 124, 65, 146, 87, 104, 209, 59, 235, 0, 247, 154, 254, 72, 121, 228, 35, 172, 86, 126, 198, 113, 161, 246, 186, 54, 97, 239, 12, 99, 31, 73, 222, 230, 77, 33, 28, 190, 211, 226, 17, 171, 34, 113, 93, 103, 222 };
			unsigned int numberOfDigitsSum = 258;
            UInt8 digitsSum[] = {174, 119, 89, 250, 125, 212, 136, 247, 15, 6, 95, 110, 52, 77, 41, 12, 134, 176, 209, 29, 205, 85, 253, 132, 133, 28, 26, 209, 94, 49, 66, 185, 152, 203, 52, 238, 174, 222, 214, 81, 216, 101, 224, 62, 119, 207, 70, 19, 255, 196, 52, 60, 40, 151, 235, 108, 31, 152, 32, 114, 84, 46, 188, 195, 184, 47, 60, 2, 98, 241, 208, 105, 200, 131, 252, 79, 236, 141, 55, 184, 235, 1, 119, 239, 93, 225, 204, 48, 152, 79, 51, 110, 57, 45, 133, 58, 68, 75, 239, 240, 220, 27, 105, 254, 252, 228, 229, 41, 92, 4, 118, 22, 180, 249, 72, 49, 39, 173, 56, 22, 240, 88, 39, 214, 19, 179, 12, 60, 91, 166, 219, 58, 156, 2, 85, 238, 100, 107, 45, 178, 92, 202, 235, 3, 251, 38, 158, 146, 185, 194, 85, 130, 139, 94, 30, 231, 180, 243, 105, 190, 202, 20, 15, 69, 201, 173, 72, 132, 201, 137, 104, 173, 162, 206, 231, 249, 214, 206, 94, 116, 130, 34, 235, 39, 185, 245, 11, 63, 253, 9, 207, 209, 3, 190, 1, 186, 82, 29, 84, 188, 27, 15, 96, 150, 150, 39, 30, 86, 128, 70, 68, 41, 124, 65, 146, 87, 104, 209, 59, 235, 0, 247, 154, 254, 72, 121, 228, 35, 172, 86, 126, 198, 113, 161, 246, 186, 54, 97, 239, 12, 99, 31, 73, 222, 230, 77, 33, 28, 190, 211, 226, 17, 171, 34, 113, 93, 103, 222};
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			Base256Number* actualOutput = addInBase256(&pNumber2, &pNumber1);
			Base256Number expectedOutput = { numberOfDigitsSum, digitsSum };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}


		[TestMethod, Timeout(3000)]
		void TestisGreater_00(){
			unsigned int numberOfDigits1 = 1;
			UInt8 digits1[] = { 0 };
			unsigned int numberOfDigits2 = 1;
			UInt8 digits2[] = { 0 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			int actualOutput = isGreater(&pNumber1, &pNumber2);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisGreater_01(){
			unsigned int numberOfDigits1 = 2;
			UInt8 digits1[] = { 0, 12 };
			unsigned int numberOfDigits2 = 2;
			UInt8 digits2[] = { 0, 25 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			int actualOutput = isGreater(&pNumber1, &pNumber2);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisGreater_02(){
			unsigned int numberOfDigits1 = 3;
			UInt8 digits1[] = { 0, 12, 45 };
			unsigned int numberOfDigits2 = 2;
			UInt8 digits2[] = { 0, 25 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			int actualOutput = isGreater(&pNumber1, &pNumber2);
			int expectedOutput = 1;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisGreater_03(){
			unsigned int numberOfDigits1 = 2;
			UInt8 digits1[] = { 0, 255 };
			unsigned int numberOfDigits2 = 2;
			UInt8 digits2[] = { 0, 255 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			int actualOutput = isGreater(&pNumber1, &pNumber2);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisGreater_04(){
			unsigned int numberOfDigits1 = 4;
			UInt8 digits1[] = { 17, 29, 61, 74 };
			unsigned int numberOfDigits2 = 2;
			UInt8 digits2[] = { 66, 6 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			int actualOutput = isGreater(&pNumber1, &pNumber2);
			int expectedOutput = 1;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisGreater_05(){
			unsigned int numberOfDigits1 = 5;
			UInt8 digits1[] = { 61, 74, 29, 89, 52 };
			unsigned int numberOfDigits2 = 7;
			UInt8 digits2[] = { 78, 152, 75, 45, 125, 137, 247 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			int actualOutput = isGreater(&pNumber1, &pNumber2);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisGreater_06(){
			unsigned int numberOfDigits1 = 100;
			UInt8 digits1[] = { 118, 37, 190, 252, 36, 55, 107, 134, 227, 235, 230, 82, 94, 34, 230, 238, 20, 160, 142, 198, 182, 94, 53, 160, 64, 96, 15, 40, 177, 230, 3, 52, 30, 238, 36, 159, 172, 227, 192, 182, 235, 183, 16, 161, 242, 24, 254, 217, 150, 65, 242, 6, 251, 92, 74, 35, 115, 35, 10, 37, 188, 251, 253, 147, 74, 100, 206, 64, 108, 43, 226, 140, 209, 194, 57, 27, 254, 78, 167, 12, 172, 10, 109, 110, 16, 123, 218, 13, 188, 211, 172, 52, 183, 46, 159, 228, 169, 120, 230, 107 };
			unsigned int numberOfDigits2 = 172;
			UInt8 digits2[] = { 221, 16, 51, 237, 175, 231, 128, 154, 22, 49, 128, 117, 239, 126, 230, 35, 168, 140, 20, 25, 150, 120, 196, 23, 24, 171, 248, 170, 188, 22, 206, 136, 145, 96, 29, 213, 158, 201, 78, 124, 64, 117, 219, 144, 115, 92, 254, 155, 124, 216, 20, 58, 44, 231, 216, 179, 213, 198, 38, 168, 169, 105, 50, 24, 63, 200, 83, 30, 4, 15, 59, 66, 151, 232, 139, 1, 82, 226, 14, 10, 6, 5, 158, 119, 89, 177, 211, 109, 53, 41, 2, 114, 185, 55, 218, 44, 125, 2, 165, 233, 232, 255, 134, 221, 22, 135, 91, 120, 161, 19, 145, 70, 179, 90, 128, 79, 184, 233, 210, 42, 119, 83, 242, 37, 197, 56, 126, 58, 132, 1, 78, 194, 24, 95, 244, 12, 124, 145, 3, 174, 48, 142, 82, 5, 16, 131, 17, 43, 159, 181, 171, 165, 115, 174, 19, 58, 20, 16, 0, 71, 224, 29, 233, 40, 86, 1, 219, 232, 157, 14, 244, 128 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			int actualOutput = isGreater(&pNumber1, &pNumber2);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisGreater_07(){
			unsigned int numberOfDigits1 = 100;
			UInt8 digits1[] = { 118, 37, 190, 252, 36, 55, 107, 134, 227, 235, 230, 82, 94, 34, 230, 238, 20, 160, 142, 198, 182, 94, 53, 160, 64, 96, 15, 40, 177, 230, 3, 52, 30, 238, 36, 159, 172, 227, 192, 182, 235, 183, 16, 161, 242, 24, 254, 217, 150, 65, 242, 6, 251, 92, 74, 35, 115, 35, 10, 37, 188, 251, 253, 147, 74, 100, 206, 64, 108, 43, 226, 140, 209, 194, 57, 27, 254, 78, 167, 12, 172, 10, 109, 110, 16, 123, 218, 13, 188, 211, 172, 52, 183, 46, 159, 228, 169, 120, 230, 107 };
			unsigned int numberOfDigits2 = 100;
			UInt8 digits2[] = { 118, 37, 190, 252, 36, 55, 107, 134, 227, 235, 230, 82, 94, 34, 230, 238, 20, 160, 142, 198, 182, 94, 53, 160, 64, 96, 15, 40, 177, 230, 3, 52, 30, 238, 36, 159, 172, 227, 192, 182, 235, 183, 16, 161, 242, 24, 254, 217, 150, 65, 242, 6, 251, 92, 74, 35, 115, 35, 10, 37, 188, 251, 253, 147, 74, 100, 206, 64, 108, 43, 226, 140, 209, 194, 57, 27, 254, 78, 167, 12, 172, 10, 109, 110, 16, 123, 218, 13, 188, 211, 172, 52, 183, 46, 159, 228, 169, 120, 230, 107 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			int actualOutput = isGreater(&pNumber1, &pNumber2);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisGreater_08(){
			unsigned int numberOfDigits1 = 149;
			UInt8 digits1[] = { 131, 215, 200, 180, 5, 89, 222, 39, 25, 223, 170, 75, 171, 155, 156, 131, 207, 21, 158, 151, 191, 89, 139, 218, 75, 245, 25, 101, 235, 102, 62, 38, 80, 140, 121, 174, 41, 104, 134, 97, 245, 86, 164, 64, 168, 146, 27, 63, 255, 39, 230, 87, 24, 204, 191, 52, 255, 42, 246, 162, 110, 249, 24, 64, 143, 54, 181, 190, 224, 222, 70, 33, 116, 112, 10, 182, 54, 13, 195, 250, 148, 239, 55, 206, 233, 144, 138, 229, 216, 192, 72, 65, 36, 7, 222, 217, 150, 89, 55, 182, 202, 81, 157, 53, 211, 71, 249, 161, 104, 241, 250, 8, 127, 19, 248, 139, 232, 162, 252, 32, 82, 31, 224, 99, 123, 245, 219, 50, 93, 222, 127, 88, 124, 46, 124, 66, 33, 244, 38, 182, 218, 135, 140, 129, 127, 52, 69, 95, 53 };
			unsigned int numberOfDigits2 = 149;
			UInt8 digits2[] = { 131, 215, 200, 180, 5, 89, 222, 39, 25, 223, 170, 75, 171, 155, 156, 131, 207, 21, 158, 151, 191, 89, 139, 218, 75, 245, 25, 101, 235, 102, 62, 38, 80, 140, 121, 174, 41, 104, 134, 97, 245, 86, 164, 64, 168, 146, 27, 63, 255, 39, 230, 87, 24, 204, 191, 52, 255, 42, 246, 162, 110, 249, 24, 64, 143, 54, 181, 190, 224, 222, 70, 33, 116, 112, 10, 182, 54, 13, 195, 250, 148, 239, 55, 206, 233, 144, 138, 229, 216, 192, 72, 65, 36, 7, 222, 217, 150, 89, 55, 182, 202, 81, 157, 53, 211, 71, 249, 161, 104, 241, 250, 8, 127, 19, 248, 139, 232, 162, 252, 32, 82, 31, 224, 99, 123, 245, 219, 50, 93, 222, 127, 88, 124, 46, 124, 66, 33, 244, 38, 182, 218, 135, 140, 129, 127, 52, 69, 95, 53 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			int actualOutput = isGreater(&pNumber1, &pNumber2);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisGreater_09(){
			unsigned int numberOfDigits1 = 149;
			UInt8 digits1[] = { 131, 215, 200, 180, 5, 89, 222, 39, 25, 223, 170, 75, 171, 155, 156, 131, 207, 21, 158, 151, 191, 89, 139, 218, 75, 245, 25, 101, 235, 102, 62, 38, 80, 140, 121, 174, 41, 104, 134, 97, 245, 86, 164, 64, 168, 146, 27, 63, 255, 39, 230, 87, 24, 204, 191, 52, 255, 42, 246, 162, 110, 249, 24, 64, 143, 54, 181, 190, 224, 222, 70, 33, 116, 112, 10, 182, 54, 13, 195, 250, 148, 239, 55, 206, 233, 144, 138, 229, 216, 192, 72, 65, 36, 7, 222, 217, 150, 89, 55, 182, 202, 81, 157, 53, 211, 71, 249, 161, 104, 241, 250, 8, 127, 19, 248, 139, 232, 162, 252, 32, 82, 31, 224, 99, 123, 245, 219, 50, 93, 222, 127, 88, 124, 46, 124, 66, 33, 244, 38, 182, 218, 135, 140, 129, 127, 52, 69, 95, 53 };
			unsigned int numberOfDigits2 = 149;
			UInt8 digits2[] = { 131, 215, 200, 180, 5, 89, 222, 39, 25, 223, 170, 75, 171, 155, 156, 131, 207, 21, 158, 151, 191, 89, 139, 218, 75, 245, 25, 101, 235, 102, 62, 38, 80, 140, 121, 174, 41, 104, 134, 97, 245, 86, 164, 64, 168, 146, 27, 63, 255, 39, 230, 87, 24, 204, 191, 52, 255, 42, 246, 162, 110, 249, 24, 64, 143, 54, 181, 190, 224, 222, 70, 33, 116, 112, 10, 182, 54, 13, 195, 250, 148, 239, 55, 206, 233, 143, 138, 229, 216, 192, 72, 65, 36, 7, 222, 217, 150, 89, 55, 182, 202, 81, 157, 53, 211, 71, 249, 161, 104, 241, 250, 8, 127, 19, 248, 139, 232, 162, 252, 32, 82, 31, 224, 99, 123, 245, 219, 50, 93, 222, 127, 88, 124, 46, 124, 66, 33, 244, 38, 182, 218, 135, 140, 129, 127, 52, 69, 95, 53 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			int actualOutput = isGreater(&pNumber1, &pNumber2);
			int expectedOutput = 1;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}


        // Palindrome
		[TestMethod, Timeout(3000)]
		void TestisPalindrome_00(){
			unsigned int numberOfDigits1 = 1;
			UInt8 digits1[] = { 0 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			int actualOutput = isPalindrome(&pNumber1);
			int expectedOutput = 1;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisPalindrome_01(){
			unsigned int numberOfDigits1 = 2;
			UInt8 digits1[] = { 0, 12 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			int actualOutput = isPalindrome(&pNumber1);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisPalindrome_02(){
			unsigned int numberOfDigits1 = 3;
			UInt8 digits1[] = { 0, 12, 45 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			int actualOutput = isPalindrome(&pNumber1);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisPalindrome_03(){
			unsigned int numberOfDigits1 = 3;
			UInt8 digits1[] = { 10, 255, 10};
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			int actualOutput = isPalindrome(&pNumber1);
			int expectedOutput = 1;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisPalindrome_04(){
			unsigned int numberOfDigits1 = 4;
			UInt8 digits1[] = { 17, 29, 61, 74 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			int actualOutput = isPalindrome(&pNumber1);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisPalindrome_05(){
			unsigned int numberOfDigits1 = 5;
			UInt8 digits1[] = { 61, 74, 29, 89, 61 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			int actualOutput = isPalindrome(&pNumber1);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisPalindrome_06(){
			unsigned int numberOfDigits1 = 100;
			UInt8 digits1[] = { 118, 37, 190, 252, 36, 55, 107, 134, 227, 235, 230, 82, 94, 34, 230, 238, 20, 160, 142, 198, 182, 94, 53, 160, 64, 96, 15, 40, 177, 230, 3, 52, 30, 238, 36, 159, 172, 227, 192, 182, 235, 183, 16, 161, 242, 24, 254, 217, 150, 65, 242, 6, 251, 92, 74, 35, 115, 35, 10, 37, 188, 251, 253, 147, 74, 100, 206, 64, 108, 43, 226, 140, 209, 194, 57, 27, 254, 78, 167, 12, 172, 10, 109, 110, 16, 123, 218, 13, 188, 211, 172, 52, 183, 46, 159, 228, 169, 120, 230, 107 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			int actualOutput = isPalindrome(&pNumber1);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisPalindrome_07(){
			unsigned int numberOfDigits1 = 100;
			UInt8 digits1[] = { 118, 37, 190, 252, 36, 55, 107, 134, 227, 235, 230, 82, 94, 34, 230, 238, 20, 160, 142, 198, 182, 94, 53, 160, 64, 96, 15, 40, 177, 230, 3, 52, 30, 238, 36, 159, 172, 227, 192, 182, 235, 183, 16, 161, 242, 24, 254, 217, 150, 65, 65, 150, 217, 254, 24, 242, 161, 16, 183, 235, 182, 192, 227, 172, 159, 36, 238, 30, 52, 3, 230, 177, 40, 15, 96, 64, 160, 53, 94, 182, 198, 142, 160, 20, 238, 230, 34, 94, 82, 230, 235, 227, 134, 107, 55, 36, 252, 190, 37, 118 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			int actualOutput = isPalindrome(&pNumber1);
			int expectedOutput = 1;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisPalindrome_08(){
			unsigned int numberOfDigits1 = 149;
			UInt8 digits1[] = { 131, 215, 200, 180, 5, 89, 222, 39, 25, 223, 170, 75, 171, 155, 156, 131, 207, 21, 158, 151, 191, 89, 139, 218, 75, 245, 25, 101, 235, 102, 62, 38, 80, 140, 121, 174, 41, 104, 134, 97, 245, 86, 164, 64, 168, 146, 27, 63, 255, 39, 230, 87, 24, 204, 191, 52, 255, 42, 246, 162, 110, 249, 24, 64, 143, 54, 181, 190, 224, 222, 70, 33, 116, 112, 10, 182, 54, 13, 195, 250, 148, 239, 55, 206, 233, 144, 138, 229, 216, 192, 72, 65, 36, 7, 222, 217, 150, 89, 55, 182, 202, 81, 157, 53, 211, 71, 249, 161, 104, 241, 250, 8, 127, 19, 248, 139, 232, 162, 252, 32, 82, 31, 224, 99, 123, 245, 219, 50, 93, 222, 127, 88, 124, 46, 124, 66, 33, 244, 38, 182, 218, 135, 140, 129, 127, 52, 69, 95, 53 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			int actualOutput = isPalindrome(&pNumber1);
			int expectedOutput = 0;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestisPalindrome_09(){
			unsigned int numberOfDigits1 = 149;
			UInt8 digits1[] = { 131, 215, 200, 180, 5, 89, 222, 39, 25, 223, 170, 75, 171, 155, 156, 131, 207, 21, 158, 151, 191, 89, 139, 218, 75, 245, 25, 101, 235, 102, 62, 38, 80, 140, 121, 174, 41, 104, 134, 97, 245, 86, 164, 64, 168, 146, 27, 63, 255, 39, 230, 87, 24, 204, 191, 52, 255, 42, 246, 162, 110, 249, 24, 64, 143, 54, 181, 190, 224, 222, 70, 33, 116, 112, 10, 112, 116, 33, 70, 222, 224, 190, 181, 54, 143, 64, 24, 249, 110, 162, 246, 42, 255, 52, 191, 204, 24, 87, 230, 39, 255, 63, 27, 146, 168, 64, 164, 86, 245, 97, 134, 104, 41, 174, 121, 140, 80, 38, 62, 102, 235, 101, 25, 245, 75, 218, 139, 89, 191, 151, 158, 21, 207, 131, 156, 155, 171, 75, 170, 223, 25, 39, 222, 89, 5, 180, 200, 215, 131 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			int actualOutput = isPalindrome(&pNumber1);
			int expectedOutput = 1;
			Assert::AreEqual(actualOutput, expectedOutput, L"TestSumOfNodesSmall() failed", 1, 2);
		}

        // Increment
		[TestMethod, Timeout(3000)]
		void TestincrementInBase256_00(){
			unsigned int numberOfDigits1 = 1;
			UInt8 digits1[] = { 0 };
			unsigned int numberOfDigitsResult = 1;
			UInt8 digitsResult[] = { 1 };
			Base256Number actualOutput = { numberOfDigits1, digits1 };
			incrementInBase256(&actualOutput);
			Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(&actualOutput);
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestincrementInBase256_01(){
			unsigned int numberOfDigits1 = 1;
			UInt8 digits1[] = { 254 };
			unsigned int numberOfDigitsResult = 1;
			UInt8 digitsResult[] = { 255 };
			Base256Number actualOutput = { numberOfDigits1, digits1 };
			incrementInBase256(&actualOutput);
			Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(&actualOutput);
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestincrementInBase256_02(){
            unsigned int numberOfDigits1 = 1;
            UInt8 *digits1 = (UInt8 *)malloc(1);
            digits1[0] = 255;
            unsigned int numberOfDigitsResult = 2;
            UInt8 digitsResult[] = { 0, 1 };
			Base256Number actualOutput = { numberOfDigits1, digits1 };
			incrementInBase256(&actualOutput);
			Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(&actualOutput);
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestincrementInBase256_03(){
            unsigned int numberOfDigits1 = 2;
            UInt8 digits1[] = { 0, 255 };
            unsigned int numberOfDigitsResult = 2;
            UInt8 digitsResult[] = { 1, 255 };
			Base256Number actualOutput = { numberOfDigits1, digits1 };
			incrementInBase256(&actualOutput);
			Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(&actualOutput);
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
        void TestincrementInBase256_04(){
            unsigned int numberOfDigits1 = 5;
            UInt8 digits1[] = { 255, 255, 254, 255, 255 };
            unsigned int numberOfDigitsResult = 5;
            UInt8 digitsResult[] = { 0, 0, 255, 255, 255 };
			Base256Number actualOutput = { numberOfDigits1, digits1 };
			incrementInBase256(&actualOutput);
			Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(&actualOutput);
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestincrementInBase256_05(){
            unsigned int numberOfDigits1 = 3;
            UInt8 *digits1 = (UInt8 *)malloc(3);
            digits1[0] = 255;
            digits1[1] = 255;
            digits1[2] = 255;
            unsigned int numberOfDigitsResult = 4;
            UInt8 digitsResult[] = { 0, 0, 0, 1 };
			Base256Number actualOutput = { numberOfDigits1, digits1 };
			incrementInBase256(&actualOutput);
			Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(&actualOutput);
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestincrementInBase256_06(){
			unsigned int numberOfDigits1 = 2;
			UInt8 digits1[] = { 1, 255 };
			unsigned int numberOfDigitsResult = 2;
			UInt8 digitsResult[] = { 2, 255 };
			Base256Number actualOutput = { numberOfDigits1, digits1 };
			incrementInBase256(&actualOutput);
			Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(&actualOutput);
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestincrementInBase256_07(){
            unsigned int numberOfDigits1 = 3;
            UInt8 digits1[] = { 0, 0, 1 };
            unsigned int numberOfDigitsResult = 3;
            UInt8 digitsResult[] = { 1, 0, 1 };
			Base256Number actualOutput = { numberOfDigits1, digits1 };
			incrementInBase256(&actualOutput);
			Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(&actualOutput);
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestincrementInBase256_08(){
            unsigned int numberOfDigits1 = 3;
            UInt8 *digits1 = (UInt8 *)malloc(3);
            digits1[0] = 255;
            digits1[1] = 255;
            digits1[2] = 255;
			unsigned int numberOfDigitsResult = 4;
			UInt8 digitsResult[] = { 0, 0, 0, 1 };
			Base256Number actualOutput = { numberOfDigits1, digits1 };
			incrementInBase256(&actualOutput);
			Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(&actualOutput);
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}

        [TestMethod, Timeout(3000)]
        void TestincrementInBase256_09(){
            unsigned int numberOfDigits1 = 2;
            UInt8 digits1[] = { 0, 255 };
            unsigned int numberOfDigitsResult = 2;
            UInt8 digitsResult[] = { 1, 255};
            Base256Number actualOutput = { numberOfDigits1, digits1 };
            incrementInBase256(&actualOutput);
            Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput), L"TestSumOfNodesSmall() failed", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void TestincrementInBase256_10(){
            unsigned int numberOfDigits1 = 3;
            UInt8 digits1[] = { 255, 1, 255 };
            unsigned int numberOfDigitsResult = 3;
            UInt8 digitsResult[] = { 0, 2, 255 };
            Base256Number actualOutput = { numberOfDigits1, digits1 };
            incrementInBase256(&actualOutput);
            Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput), L"TestSumOfNodesSmall() failed", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void TestincrementInBase256_11(){
            unsigned int numberOfDigits1 = 2;
            UInt8 digits1[] = { 255, 20 };
            unsigned int numberOfDigitsResult = 2;
            UInt8 digitsResult[] = { 0, 21 };
            Base256Number actualOutput = { numberOfDigits1, digits1 };
            incrementInBase256(&actualOutput);
            Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput), L"TestSumOfNodesSmall() failed", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void TestincrementInBase256_12(){
            unsigned int numberOfDigits1 = 8;
            UInt8 digits1[] = { 255, 255, 255, 255, 255, 0, 17, 29};
            unsigned int numberOfDigitsResult = 8;
            UInt8 digitsResult[] = { 0, 0, 0, 0, 0, 1, 17, 29 };
            Base256Number actualOutput = { numberOfDigits1, digits1 };
            incrementInBase256(&actualOutput);
            Base256Number expectedOutput = { numberOfDigitsResult, digitsResult };
            Assert::AreEqual(1, compare(&actualOutput, &expectedOutput), L"TestSumOfNodesSmall() failed", 1, 2);
        }
        
        // DIV
		[TestMethod, Timeout(30000)] // 30 sec
		void TestintegerDivisionInBase256_00(){
			unsigned int numberOfDigits1 = 3;
			UInt8 digits1[] = { 0, 0, 1 };
			unsigned int numberOfDigits2 = 2;
			UInt8 digits2[] = { 0, 1 };
			unsigned int numberOfDigitsQoutitent = 2;
			UInt8 digitsQoutitent[] = { 0, 1 };
			Base256Number pNumber1 = { numberOfDigits1, digits1 };
			Base256Number pNumber2 = { numberOfDigits2, digits2 };
			Base256Number* actualOutput = integerDivisionInBase256(&pNumber1, &pNumber2);
			Base256Number expectedOutput = { numberOfDigitsQoutitent, digitsQoutitent };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
		}
        
        [TestMethod, Timeout(30000)] // 30 sec
        void TestintegerDivisionInBase256_02(){
            unsigned int numberOfDigits1 = 1;
            UInt8 digits1[] = { 255 };
            unsigned int numberOfDigits2 = 1;
            UInt8 digits2[] = { 2 };
            unsigned int numberOfDigitsQoutitent = 1;
            UInt8 digitsQoutitent[] = { 127 };
            Base256Number pNumber1 = { numberOfDigits1, digits1 };
            Base256Number pNumber2 = { numberOfDigits2, digits2 };
            Base256Number* actualOutput = integerDivisionInBase256(&pNumber1, &pNumber2);
            Base256Number expectedOutput = { numberOfDigitsQoutitent, digitsQoutitent };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
        }
        
        [TestMethod, Timeout(30000)] // 30 sec
        void TestintegerDivisionInBase256_03(){
            unsigned int numberOfDigits1 = 4;
            UInt8 digits1[] = { 255, 255, 0, 2 };
            unsigned int numberOfDigits2 = 3;
            UInt8 digits2[] = { 2, 240, 250 };
            unsigned int numberOfDigitsQoutitent = 1;
            UInt8 digitsQoutitent[] = { 2 };
            Base256Number pNumber1 = { numberOfDigits1, digits1 };
            Base256Number pNumber2 = { numberOfDigits2, digits2 };
            Base256Number* actualOutput = integerDivisionInBase256(&pNumber1, &pNumber2);
            Base256Number expectedOutput = { numberOfDigitsQoutitent, digitsQoutitent };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
        }

        [TestMethod, Timeout(30000)] // 30 sec
        void TestintegerDivisionInBase256_04(){
            unsigned int numberOfDigits1 = 4;
            UInt8 digits1[] = { 0, 0, 0, 1 };
            unsigned int numberOfDigits2 = 2;
            UInt8 digits2[] = { 0, 1 };
            unsigned int numberOfDigitsQoutitent = 3;
            UInt8 digitsQoutitent[] = { 0, 0, 1 };
            Base256Number pNumber1 = { numberOfDigits1, digits1 };
            Base256Number pNumber2 = { numberOfDigits2, digits2 };
            Base256Number* actualOutput = integerDivisionInBase256(&pNumber1, &pNumber2);
            Base256Number expectedOutput = { numberOfDigitsQoutitent, digitsQoutitent };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
        }
        
        // a/a = 1
        [TestMethod, Timeout(30000)] // 30 sec
        void TestintegerDivisionInBase256_05(){
            unsigned int numberOfDigits1 = 4;
            UInt8 digits1[] = { 0, 0, 0, 1 };
            unsigned int numberOfDigits2 = 4;
            UInt8 digits2[] = { 0, 0, 0, 1 };
            unsigned int numberOfDigitsQoutitent = 1;
            UInt8 digitsQoutitent[] = { 1 };
            Base256Number pNumber1 = { numberOfDigits1, digits1 };
            Base256Number pNumber2 = { numberOfDigits2, digits2 };
            Base256Number* actualOutput = integerDivisionInBase256(&pNumber1, &pNumber2);
            Base256Number expectedOutput = { numberOfDigitsQoutitent, digitsQoutitent };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
        }
        
        // 0 / (some number)
        [TestMethod, Timeout(30000)] // 30 sec
        void TestintegerDivisionInBase256_06(){
            unsigned int numberOfDigits1 = 1;
            UInt8 digits1[] = { 0 };
            unsigned int numberOfDigits2 = 4;
            UInt8 digits2[] = { 0, 0, 0, 1 };
            unsigned int numberOfDigitsQoutitent = 1;
            UInt8 digitsQoutitent[] = { 0 };
            Base256Number pNumber1 = { numberOfDigits1, digits1 };
            Base256Number pNumber2 = { numberOfDigits2, digits2 };
            Base256Number* actualOutput = integerDivisionInBase256(&pNumber1, &pNumber2);
            Base256Number expectedOutput = { numberOfDigitsQoutitent, digitsQoutitent };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
        }
        
        // MUL
        [TestMethod, Timeout(30000)] // 30 sec
        void TestmultiplyInBase256_00(){
            unsigned int numberOfDigits1 = 2;
            UInt8 digits1[] = { 0, 1 };
            unsigned int numberOfDigits2 = 2;
            UInt8 digits2[] = { 0, 1 };
            unsigned int productNumberOfDigits = 3;
            UInt8 productDigits1[] = { 0, 0, 1 };
            Base256Number pNumber1 = { numberOfDigits1, digits1 };
            Base256Number pNumber2 = { numberOfDigits2, digits2 };
            Base256Number* actualOutput = multiplyInBase256(&pNumber1, &pNumber2);
            Base256Number expectedOutput = { productNumberOfDigits, productDigits1 };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void TestmultiplyInBase256_01(){
            unsigned int numberOfDigits1 = 1;
            UInt8 digits1[] = { 0 };
            unsigned int numberOfDigits2 = 2;
            UInt8 digits2[] = { 0, 1 };
            unsigned int productNumberOfDigits = 1;
            UInt8 productDigits1[] = { 0 };
            Base256Number pNumber1 = { numberOfDigits1, digits1 };
            Base256Number pNumber2 = { numberOfDigits2, digits2 };
            Base256Number* actualOutput = multiplyInBase256(&pNumber1, &pNumber2);
            Base256Number expectedOutput = { productNumberOfDigits, productDigits1 };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void TestmultiplyInBase256_02(){
            unsigned int numberOfDigits1 = 1;
            UInt8 digits1[] = { 255 };
            unsigned int numberOfDigits2 = 1;
            UInt8 digits2[] = { 0 };
            unsigned int productNumberOfDigits = 1;
            UInt8 productDigits1[] = { 0 };
            Base256Number pNumber1 = { numberOfDigits1, digits1 };
            Base256Number pNumber2 = { numberOfDigits2, digits2 };
            Base256Number* actualOutput = multiplyInBase256(&pNumber1, &pNumber2);
            Base256Number expectedOutput = { productNumberOfDigits, productDigits1 };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void TestmultiplyInBase256_03(){
            unsigned int numberOfDigits1 = 1;
            UInt8 digits1[] = { 0 };
            unsigned int numberOfDigits2 = 1;
            UInt8 digits2[] = { 0 };
            unsigned int productNumberOfDigits = 1;
            UInt8 productDigits1[] = { 0 };
            Base256Number pNumber1 = { numberOfDigits1, digits1 };
            Base256Number pNumber2 = { numberOfDigits2, digits2 };
            Base256Number* actualOutput = multiplyInBase256(&pNumber1, &pNumber2);
            Base256Number expectedOutput = { productNumberOfDigits, productDigits1 };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void TestmultiplyInBase256_04(){
            unsigned int numberOfDigits1 = 2;
            UInt8 digits1[] = { 255, 255 };
            unsigned int numberOfDigits2 = 1;
            UInt8 digits2[] = { 255 };
            unsigned int productNumberOfDigits = 3;
            UInt8 productDigits1[] = { 1, 255, 254 };
            Base256Number pNumber1 = { numberOfDigits1, digits1 };
            Base256Number pNumber2 = { numberOfDigits2, digits2 };
            Base256Number* actualOutput = multiplyInBase256(&pNumber1, &pNumber2);
            Base256Number expectedOutput = { productNumberOfDigits, productDigits1 };
            char *eStr = formatBase256Number(&expectedOutput);
            char *aStr = formatBase256Number(actualOutput);
            Assert::AreEqual(1, compare(actualOutput, &expectedOutput),
                             L"\nExpect: " + (gcnew String(eStr)) +
                             L"\nActual: " + (gcnew String(aStr)),
                             1, 2);
        }
    };
}

