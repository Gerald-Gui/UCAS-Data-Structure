#ifndef _HEAP_STRING_H
#define _HEAP_STRING_H

#define OK      1
#define ERROR   0
#define OVERFLOW    -1

typedef int Status;
typedef struct{
    char * ch;
    int len;
} HString;

//initialize string
void StrInit_H(HString * T);
//generate string T equals to const string chars
Status StrAssign_H(HString * T, const char * chars);
//copy string S to string T
Status StrCopy_H(HString * T, HString S);
//return positive value if S > T, zero if S == T, or negative value if S < T
int StrCompare_H(HString S, HString T);
//return the num of elems of string S
int StrLength_H(HString S);
//set string S empty
void ClearString_H(HString * S);
//return new string T connected by S1 and S2
Status Concat_H(HString * T, HString S1, HString S2);
//use Sub to return substring which starts from the posth char and have len elems
Status SubString_H(HString * Sub, HString S, int pos, int len);
//return the first position where T in S after pos, return 0 if T doesn't exist
int Index_H(HString S, HString T, int pos);
//insert string T before the posth char of string S
Status StrInsert_H(HString * S, int pos, HString T);
//delete substring who started at the posth char and have len chars
Status StrDelete_H(HString * S, int pos, int len);
//use V to replace all substrings equals to T in string S
Status Replace_H(HString * S, HString T, HString V);
//destroy string S
Status DestroyString_H(HString * S);

#endif
