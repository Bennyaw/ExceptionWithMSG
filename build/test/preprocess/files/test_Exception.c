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



void throwError2(int errorCode,char *msg )

{

  Exception *ex = (Exception *)malloc(sizeof(Exception));

  ex->errorCode = errorCode;

  ex->errorMsg = msg;

  Throw(ex);

}









char *getName(int index)

{

 if((index >= 4) || (index < 0))

 {



  throwError(3,"Error: Out of bound of the array. Index given was %d.",index);

 }

 return name[index];

}



int add(int num,...)

{

  va_list valist;

  int i,sum=0;





  

 __builtin_va_start(

 valist

 ,

 num

 )

                     ;

  for (i = 0; i < num; i++) {

      sum += 

            __builtin_va_arg(

            valist

            ,

            int

            )

                               ;

     }



  

 __builtin_va_end(

 valist

 )

               ;

  return sum;

}

void printfAllNumbers(char *format,...)

{

  va_list valist;

  int neededSize;

  char *buffer;

  Exception *ex = (Exception *)malloc(sizeof(Exception));



  

 __builtin_va_start(

 valist

 ,

 format

 )

                        ;

  neededSize = vsnprintf(

                        ((void *)0)

                            ,0,format,valist)+1;

  buffer = malloc(neededSize);

  vsnprintf(buffer,neededSize,format,valist);



  

 __builtin_va_end(

 valist

 )

               ;



  ex ->errorMsg = buffer;



  printf(buffer);

}



void test_printAllNumbers(void)

{

  printfAllNumbers("%f,%d,%x,%s",123.5678,6342,255, "Ooi");

}





void test_add_given_1_2_3_4_5_expect_15(void)

{

  int result = add(5,1,2,3,4,5);



  UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_INT);

}



void test_add_given_9_8_7_expect_24(void)

{

  int result = add(3,9,8,7);



  UnityAssertEqualNumber((UNITY_INT)((24)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(120), UNITY_DISPLAY_STYLE_INT);

}



void test_add_given_6_28_2_0_10_1_expect_47(void)

{

  int result = add(6,6,28,2,0,10,1);



  UnityAssertEqualNumber((UNITY_INT)((47)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(127), UNITY_DISPLAY_STYLE_INT);

}



void test_getName_given_1_expect_David(void) {



 char *name;

 Exception* e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((Exception*)0x5A5A5A5A); ; if (

_setjmp((

NewFrame

), __builtin_frame_address (0)) 

== 0) { if (1)

 {

  name = getName(1);

  UnityAssertEqualString((const char*)(("David")), (const char*)((name)), (

 ((void *)0)

 ), (UNITY_UINT)(138));

 }

 else { } CExceptionFrames[MY_ID].Exception = ((Exception*)0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((Exception*)0x5A5A5A5A))

 {

  UnityFail( ((e->errorMsg)), (UNITY_UINT)(142));

 }





}



void test_getName_given_minus_1_expect_ERR_OUT_OF_BOUND(void) {



 char *name;

 Exception* e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((Exception*)0x5A5A5A5A); ; if (

_setjmp((

NewFrame

), __builtin_frame_address (0)) 

== 0) { if (1)

 {

  name = getName(-1);

  UnityFail( (("Expected ERR_OUT_OF_BOUND to be thrown, but none")), (UNITY_UINT)(156));

 }

 else { } CExceptionFrames[MY_ID].Exception = ((Exception*)0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((Exception*)0x5A5A5A5A))

 {

  printf("Under test_getName_given_minus_1_expect_ERR_OUT_OF_BOUND \n");

  printf("(error code : %d)", e->errorCode);

    free(e);

 }



}



void test_getName_given_4_expect_ERR_OUT_OF_BOUND(void) {



 char *name;

 Exception* e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((Exception*)0x5A5A5A5A); ; if (

_setjmp((

NewFrame

), __builtin_frame_address (0)) 

== 0) { if (1)

 {

  name = getName(4);

  UnityFail( (("Expected ERR_OUT_OF_BOUND to be thrown, but none")), (UNITY_UINT)(175));

 }

 else { } CExceptionFrames[MY_ID].Exception = ((Exception*)0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((Exception*)0x5A5A5A5A))

 {

  printf("Under test_getName_given_4_expect_ERR_OUT_OF_BOUND \n");

  printf(e->errorMsg);

    free(e);

 }





}
