#include <iostream>
#include <gtest/gtest.h>
#include "classString.hpp"

/* Subject:                Implement Class String.
Requirement:       
Using c++ basic grammar
Using 5G code style
Write a demo for how to use.
Suggest to write UT using google test
Suggest to work following TDD rules
Suggest to use pointer ‘this’
Array can be used
Malloc/free or new/delete can be used
 
Topic:
###Implement six kinds of constructor functions.
###Please for forbidden the default constructor
###Implement destructor function
###Please overload operator  << (stand output)  + (addition)   ==(equal) 
###Implement getLength() : return the getLength of string
###Implement compare(): 1 >, 0 ==, -1 <
 
Knowledge point:
The base knowledge about class
The function overload
Friend function
And so on */

TEST(FunTest, fiveConstructorFunctionTest) 
{
	String str0("mamingxing");
	ASSERT_STREQ("mamingxing", str0.getStr());
	
	String str1(str0);
	ASSERT_STREQ("mamingxing", str1.getStr());
	
	String str2 = std::move(str0);
	ASSERT_STREQ("mamingxing", str2.getStr());
	
	String str3{"ma"};
	str3 = str1;
	ASSERT_STREQ("mamingxing", str3.getStr());
	
	String str4{"ma"};
	str4 = std::move(str3);
	ASSERT_STREQ("mamingxing", str4.getStr());
}

TEST(FunTest, getLengthFunctionTest) 
{
	String str0("12345");
	ASSERT_EQ(5, str0.getLength());
}

TEST(FunTest, compareFunctionTest) 
{
	String str0("12345");
	String str1("12345");
	String str2("25");
	String str3("078");
	char cstr1[] = "12345";
	char cstr2[] = "34";
	char cstr3[] = "09";
	
	ASSERT_EQ(0, str0.compare(str1));
	ASSERT_EQ(-1, str0.compare(str2));	
	ASSERT_EQ(1, str0.compare(str3));

	ASSERT_EQ(0, str0.compare(cstr1));
	ASSERT_EQ(-1, str0.compare(cstr2));
	ASSERT_EQ(1, str0.compare(cstr3));
}

TEST(FunTest, overloadOperatorFunctionTest) 
{
	// String str("00");
	// std::cout << "input a string to test cin:";
	// std::cin >> str;
	// std::cout << "the string you input is:" << str << std::endl;
	
	String str("");
	String stra("ma");
	String strb("mingxing");
	String strc("mingxingma");
	
	str = stra + strb;
	ASSERT_STREQ("mamingxing", str.getStr());
	str = strb + stra;
	ASSERT_STREQ("mingxingma", str.getStr());	
	
	ASSERT_EQ(false, str==strb);
	ASSERT_EQ(true, str==strc);
}

TEST(FunTest, memberFunctionTest) 
{
	String str("");
	String str0("128");
	str.PushBack('a');
	ASSERT_STREQ("a", str.getStr());
	str.append("bcdefghijklmn0");
	ASSERT_STREQ("abcdefghijklmn0", str.getStr());
	str.PopBack();
	ASSERT_STREQ("abcdefghijklmn", str.getStr());
	int a = str.Find('l');
	ASSERT_EQ(11, a);
	a = str.Find("mn");
	ASSERT_EQ(12, a);
	
	str.Swap(str0);
	ASSERT_STREQ("128", str.getStr());
	ASSERT_STREQ("abcdefghijklmn", str0.getStr());
	
	str.Insert(2, "34567");
	ASSERT_STREQ("12345678", str.getStr());
	str.Insert(7, '9');
	ASSERT_STREQ("123456798", str.getStr());
}

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}










