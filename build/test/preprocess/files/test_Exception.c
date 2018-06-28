#include "build/temp/_test_Exception.c"
#include "Exception.h"
#include "unity.h"
#include "CException.h"






void setUp(void)

{

}



void tearDown(void)

{

}





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

 char* e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((char*)0x5A5A5A5A); ; if (

_setjmp((

NewFrame

), __builtin_frame_address (0)) 

== 0) { if (1)

 {

  name = getName(1);

  UnityAssertEqualString((const char*)(("David")), (const char*)((name)), (

 ((void *)0)

 ), (UNITY_UINT)(43));

 }

 else { } CExceptionFrames[MY_ID].Exception = ((char*)0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((char*)0x5A5A5A5A))

 {

  UnityFail( (("Expected no exception thrown ERR_OUT_OF_BOUND to be thrown, but none")), (UNITY_UINT)(47));

 }





}



void test_getName_given_minus_1_expect_ERR_OUT_OF_BOUND(void) {



 char *name;

 char* e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((char*)0x5A5A5A5A); ; if (

_setjmp((

NewFrame

), __builtin_frame_address (0)) 

== 0) { if (1)

 {

  name = getName(-1);

  UnityFail( (("Expected ERR_OUT_OF_BOUND to be thrown, but none")), (UNITY_UINT)(61));

 }

 else { } CExceptionFrames[MY_ID].Exception = ((char*)0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((char*)0x5A5A5A5A))

 {

  printf("Under test_getName_given_minus_1_expect_ERR_OUT_OF_BOUND \n");

  printf(e);

 }



}



void test_getName_given_4_expect_ERR_OUT_OF_BOUND(void) {



 char *name;

 char* e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((char*)0x5A5A5A5A); ; if (

_setjmp((

NewFrame

), __builtin_frame_address (0)) 

== 0) { if (1)

 {

  name = getName(4);

  UnityFail( (("Expected ERR_OUT_OF_BOUND to be thrown, but none")), (UNITY_UINT)(79));

 }

 else { } CExceptionFrames[MY_ID].Exception = ((char*)0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((char*)0x5A5A5A5A))

 {

  printf("Under test_getName_given_4_expect_ERR_OUT_OF_BOUND \n");

  printf(e);

 }





}
