#include <stdlib.h>

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

void StrInit_H(HString * T){
    T->ch = NULL;
    T->len = 0;
}

Status StrAssign_H(HString * T, const char * chars){
    if(T->ch != NULL){
        free(T->ch);
        T->ch = NULL;
    }
    T->len = 0;
    for(char * c = chars; *c != '\0'; T->len++)
        c++;
    if(T->len != 0){
        T->ch = malloc(T->len * sizeof(char));
        if(T->ch == NULL)
            exit(OVERFLOW);
        for(int i = 0; i < T->len; i++)
            T->ch[i] = chars[i];
    }
    return OK;
}

Status StrCopy_H(HString * T, HString S){
    if(T->ch != NULL){
        free(T->ch);
        T->ch = NULL;
    }
    T->len = S.len;
    if((T->ch = malloc(T->len * sizeof(char))) == NULL)
        exit(OVERFLOW);
    for(int i = 0; i < T->len; i++)
        T->ch[i] = S.ch[i];
    return OK;
}

int StrCompare_H(HString S, HString T){
    for(int i = 0; i < S.len && i < T.len; i++)
        if(S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    return S.len - T.len;
}

int StrLength_H(HString S){
    return S.len;
}

void ClearString_H(HString * S){
    if(S->ch != NULL)
        free(S->ch);
    S->ch = NULL;
    S->len = 0;
}

Status Concat_H(HString * T, HString S1, HString S2){
    if(T->ch != NULL)
        free(T->ch);
    T->ch = NULL;
    T->len = S1.len + S2.len;
    if(T->len == 0)
        return OK;
    if((T->ch = malloc(sizeof(char) * (T->len))) == NULL)
        exit(OVERFLOW);
    for(int i = 0; i < S1.len; i++)
        T->ch[i] = S1.ch[i];
    for(int i = 0; i < S2.len; i++)
        T->ch[i + S1.len] = S2.ch[i];
    return OK;
}

Status SubString_H(HString * Sub, HString S, int pos, int len){
    if(pos < 1 || pos > StrLength_H(S) || len < 0 || len > StrLength_H(S) - pos + 1)
        return ERROR;
    if(Sub->ch != NULL)
        free(Sub->ch);
    Sub->ch = NULL;
    Sub->len = len;
    if(len != 0){
        if((Sub->ch = malloc(Sub->len * sizeof(char)) == NULL))
            exit(OVERFLOW);
        for(int i = 0; i < len; i++)
            Sub->ch[i] = S.ch[pos - 1 + i];
    }
    return OK;
}

int Index_H(HString S, HString T, int pos){
    if(pos <= 0 || pos > S.len)
        return -1;
    int i, j;
    for(i = pos - 1; i < S.len; i++){
        if(S.len - i < T.len)
            break;
        for(j = 0; j < T.len; j++){
            if(S.ch[i + j] != T.ch[j])
                break;
            if(j == T.len - 1 && S.ch[i + j] == T.ch[j])
                return i + 1;
        }
    }
    return 0;
}

Status StrInsert_H(HString * S, int pos, HString T){
    if(pos < 1 || pos > S->len)
        return ERROR;
    S->len += T.len;
    S->ch = realloc(S->ch, S->len * sizeof(char));
    if(S->ch == NULL)
        exit(OVERFLOW);
    for(int i = S->len; i >= T.len + pos - 1; i--)
        S->ch[i] = S->ch[i - T.len];
    for(int i = 0; i < T.len; i++)
        S->ch[pos - 1 + i] = T.ch[i];
    return OK;
}

Status StrDelete_H(HString * S, int pos, int len){
    if(pos < 1 || pos > S->len - len + 1)
        return ERROR;
    for(int i = pos - 1; i < S->len - len; i++)
        S->ch[i] = S->ch[i + len];
    S->len -= len;
    S->ch = realloc(S->ch, S->len * sizeof(char));
    if(S->ch == NULL)
        exit(OVERFLOW);
    return OK;
}

Status Replace_H(HString * S, HString T, HString V){
    int pos = 1;
    if(T.len == 0)
        return ERROR;
    while((pos = Index_H(*S, T, pos)) > 0){
        if(StrDelete_H(S, pos, T.len) != OK)
            return ERROR;
        if(StrInsert_H(S, pos, V) != OK)
            return ERROR;
        pos += V.len;
    }
    return OK;
}

Status DestroyString_H(HString * S){
    S->len = 0;
    if(S->ch != NULL)
        free(S->ch);
    S->ch = NULL;
    return OK;
}
