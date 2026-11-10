#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\USSER\Desktop\лаби\ап 8.1 іт\ап 8.1 іт\ап 8.1 іт.cpp"   

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTestWhile)
    {
    public:

        // 1. Порожній рядок та рядок без "while"
        TEST_METHOD(TestNoWhile)
        {
            char t[101];

            Assert::AreEqual(0, Count(""));
            Assert::AreEqual(0, Count("hello world"));
            Assert::AreEqual(0, Count("whil whle"));

            Assert::AreEqual("", Change("", t));
            Assert::AreEqual("hello world", Change("hello world", t));
        }

        // 2. Одна група "while"
        TEST_METHOD(TestOneWhile)
        {
            char t[101];

            Assert::AreEqual(1, Count("while"));
            Assert::AreEqual(1, Count("awhileb"));

            Assert::AreEqual("***", Change("while", t));
            Assert::AreEqual("a***b", Change("awhileb", t));
        }

        // 3. Кілька груп "while"
        TEST_METHOD(TestSeveralWhile)
        {
            char t[101];

            Assert::AreEqual(2, Count("while x while"));
            Assert::AreEqual(3, Count("while1while2while"));

            Assert::AreEqual("*** x ***", Change("while x while", t));
            Assert::AreEqual("***1***2***", Change("while1while2while", t));
        }

        // 4. Групи, що стоять упритул, та неповні/перекручені групи
        TEST_METHOD(TestEdgeCases)
        {
            char t[101];

            Assert::AreEqual(2, Count("whilewhile"));
            Assert::AreEqual("******", Change("whilewhile", t));

            Assert::AreEqual(1, Count("whilwhile"));
            Assert::AreEqual("whil***", Change("whilwhile", t));

            Assert::AreEqual(0, Count("WHILE"));
            Assert::AreEqual("WHILE", Change("WHILE", t));
        }
    };
}