#define NO_DLL

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../VSTest/src/core.h"
#include "../../VSTest/src/core.cpp"
#include "../../VSTest/src/functions.cpp"
#include "../../VSTest/src/string_process.cpp"
#include "../../VSTest/src/graph_process.cpp"
#include "../../VSTest/src/simple_chain_count.cpp"
#include "../../VSTest/src/simple_chain_model.cpp"
#include "../../VSTest/src/simple_chain_word.cpp"
#include "../../VSTest/src/word_chain_count.cpp"
#include "../../VSTest/src/word_chain_model.cpp"
#include "../../VSTest/src/word_chain_word.cpp"

#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			std::cout << "hello, world";
			Assert::AreEqual(11, 11);
		}


		TEST_METHOD(Test1)
		{
			char *words[] = { "ab", "b" };
			char *result[2];
			int len = gen_chain_word(words, 2, result, 0, 0, false);

			Assert::AreEqual(len, 2);
			Assert::AreEqual(result[0], "ab");
			Assert::AreEqual(result[1], "b");
		}

		TEST_METHOD(Test11)
		{
			char *words[] = { "ab", "b" };
			char *result[2];
			int len = gen_chain_word(words, 2, result, 'a', 0, false);

			Assert::AreEqual(len, 2);
			Assert::AreEqual(result[0], "ab");
			Assert::AreEqual(result[1], "b");
		}

		TEST_METHOD(Test12)
		{
			char *words[] = { "ab", "b" };
			char *result[2];
			int len = gen_chain_word(words, 2, result, 'a', 'b', false);

			Assert::AreEqual(len, 2);
			Assert::AreEqual(result[0], "ab");
			Assert::AreEqual(result[1], "b");
		}
		TEST_METHOD(Test123)
		{
			char *words[] = { "ab", "b" };
			char *result[2];
			int len = gen_chain_word(words, 2, result, 'a', 'b', true);

			Assert::AreEqual(len, 2);
			Assert::AreEqual(result[0], "ab");
			Assert::AreEqual(result[1], "b");
		}
		TEST_METHOD(Test2)
		{
			char *words[] = { "ab", "b" };
			char *result[2];
			int len = gen_chain_char(words, 2, result, 0, 0, false);

			Assert::AreEqual(len, 2);
			Assert::AreEqual(result[0], "ab");
			Assert::AreEqual(result[1], "b");
		}

		TEST_METHOD(Test3)
		{
			char *words[] = { "ab", "b" };
			char *result[2];
			int len = gen_chain_word(words, 2, result, 0, 0, true);

			Assert::AreEqual(len, 2);
			Assert::AreEqual(result[0], "ab");
			Assert::AreEqual(result[1], "b");
		}
		TEST_METHOD(Test31)
		{
			char *words[] = { "ab", "b" };
			char *result[2];
			int len = gen_chain_word(words, 2, result, 'a', 0, true);

			Assert::AreEqual(len, 2);
			Assert::AreEqual(result[0], "ab");
			Assert::AreEqual(result[1], "b");
		}
		TEST_METHOD(Test32)
		{
			char *words[] = { "ab", "b" };
			char *result[2];
			int len = gen_chain_word(words, 2, result, 'a', 'b', true);

			Assert::AreEqual(len, 2);
			Assert::AreEqual(result[0], "ab");
			Assert::AreEqual(result[1], "b");
		}
		TEST_METHOD(Test321)
		{
			char *words[] = { "ab", "b" };
			char *result[2];
			int len = gen_chain_word(words, 2, result, 'a', 'b', false);

			Assert::AreEqual(len, 2);
			Assert::AreEqual(result[0], "ab");
			Assert::AreEqual(result[1], "b");
		}
		TEST_METHOD(Test4)
		{
			char *words[] = { "ab", "b" };
			char *result[2];
			int len = gen_chain_char(words, 2, result, 0, 0, true);

			Assert::AreEqual(len, 2);
			Assert::AreEqual(result[0], "ab");
			Assert::AreEqual(result[1], "b");
		}

	};
}