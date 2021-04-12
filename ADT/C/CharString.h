#ifndef _CHAR_STRING_H
#define _CHAR_STRING_H

#ifndef OK
    #define OK          1
#endif
#ifndef ERROR
    #define ERROR       0
#endif
#ifndef OVERFLOW
    #define OVERFLOW    -1
#endif

typedef int Status;
typedef char * CString;

//initialize string
void StrInit_C(CString * T);
//generate string T equals to const string chars
Status StrAssign_C(CString * T, const char * chars);
//copy string S to string T
Status StrCopy_C(CString * T, CString S);
//return positive value if S > T, zero if S == T, or negative value if S < T
int StrCompare_C(CString S, CString T);
//return the num of elems of string S
int StrLength_C(CString S);
//set string S empty
void ClearString_C(CString * S);
//return new string T connected by S1 and S2
Status Concat_C(CString * T, CString S1, CString S2);
//use Sub to return substring which starts from the posth char and have len elems
Status SubString_C(CString * Sub, CString S, int pos, int len);
//return the first position where T in S after pos, return 0 if T doesn't exist
int Index_C(CString S, CString T, int pos);
//insert string T before the posth char of string S
Status StrInsert_C(CString * S, int pos, CString T);
//delete substring who started at the posth char and have len chars
Status StrDelete_C(CString * S, int pos, int len);
//use V to replace all substrings equals to T in string S
Status Replace_C(CString * S, CString T, CString V);
//destroy string S
Status DestroyString(CString * S);

#endif
