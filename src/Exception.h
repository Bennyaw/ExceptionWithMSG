#ifndef _EXCEPTION_H
#define _EXCEPTION_H

/*typedef struct                    //for c only
{
  int errorCode;
  char *errorMsg;
}Exception;*/

typedef struct Exception Exception; //for c++ and c
struct Exception
{
  int errorCode;
  char *errorMsg;
};
#endif // _EXCEPTION_H
