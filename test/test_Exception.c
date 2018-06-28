#include <stdio.h>
#include "CException.h"
#include "unity.h"
#include "Exception.h"



void setUp(void)
{
}

void tearDown(void)
{
}

//names is array 3 of pointers to char
char *name[] = {
	"Ali",
	"David",
	"Ah Beng",
	"Sally"
};


char *getName(int index)
{	
	if((index >= 4) || (index < 0))
	{
		Throw("Error: Out of bound of the array.");
	}
	return name[index];
}


void test_getName_given_1_expect_David(void) {
	
	char *name;
	CEXCEPTION_T e;
	
	Try
	{
		name = getName(1);
		TEST_ASSERT_EQUAL_STRING("David",name);
	}
	Catch(e)
	{
		TEST_FAIL_MESSAGE("Expected no exception thrown ERR_OUT_OF_BOUND to be thrown, but none");
	}

	
}

void test_getName_given_minus_1_expect_ERR_OUT_OF_BOUND(void) {
	
	char *name;
	CEXCEPTION_T e;
	
	Try
	{
		name = getName(-1);
		TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND to be thrown, but none");
	}
	Catch(e)
	{
		printf("Under test_getName_given_minus_1_expect_ERR_OUT_OF_BOUND \n");
		printf(e);
	}
	
}

void test_getName_given_4_expect_ERR_OUT_OF_BOUND(void) {
	
	char *name;
	CEXCEPTION_T e;
	
	Try
	{
		name = getName(4);
		TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND to be thrown, but none");
	}
	Catch(e)
	{
		printf("Under test_getName_given_4_expect_ERR_OUT_OF_BOUND \n");
		printf(e);
	}

	
}