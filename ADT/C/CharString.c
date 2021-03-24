#include <stdlib.h>
#include <string.h>

#define OK      1
#define ERROR   0
#define OVERFLOW    -1

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

void StrInit_C(CString * T){
    if(*T != NULL)
        free(*T);
    *T = NULL;
}

Status StrAssign_C(CString * T, const char * chars){
    int len = strlen(chars) + 1;
    *T = malloc(sizeof(char) * len);
    if(*T == NULL)
        exit(OVERFLOW);
    for(int i = 0; i < len; i++)
        (*T)[i] = chars[i];
}

Status StrCopy_C(CString * T, CString S){
    if(*T != NULL){
        free(*T);
        *T = NULL;
    }
    int len = StrLength_C(S) + 1;
    if((*T = malloc(sizeof(char) * len)) == NULL)
        exit(OVERFLOW);
    for(int i = 0; i < len; i++)
        (*T)[i] = S[i];
}

int StrCompare_C(CString S, CString T){
    for(int i = 0; S[i] != '\0' && T[i] != '\0'; i++)
        if(S[i] != T[i])
            return S[i] - T[i];
    return StrLength_C(S) - StrLength_C(T);
}

int StrLength_C(CString S){
    int cnt = 0;
    while(S[cnt] != '\0')
        cnt++;
    return cnt;
}

void ClearString_C(CString * S){
    if(*S != NULL)
        free(*S);
    *S = NULL;
}

Status Concat_C(CString * T, CString S1, CString S2){
    int len_1 = StrLength_C(S1), len_2 = StrLength_C(S2);
    if(*T != NULL){
        free(*T);
        *T = NULL;
    }
    if((*T = malloc(sizeof(char) * (len_1 + len_2 + 1))) == NULL)
        exit(OVERFLOW);
    for(int i = 0; i < len_1; i++)
        (*T)[i] = S1[i];
    for(int i = 0; i <= len_2; i++)
        (*T)[i] = S2[i];
    return OK;
}

Status SubString_C(CString * Sub, CString S, int pos, int len){
    if(pos < 1 || len < 1 || pos + len > StrLength_C(S))
        return ERROR;
    if(*Sub != NULL){
        free(*Sub);
        *Sub = NULL;
    }
    if((*Sub = malloc(sizeof(char) * (StrLength_C(S) + 1))) == NULL)
        exit(OVERFLOW);
    for(int i = 0; i < len; i++)
        (*Sub)[i] = S[i + pos - 1];
    (*Sub)[len] = '\0';
    return OK;
}

int Index_C(CString S, CString T, int pos){
    if(pos <= 0 || pos > StrLength_C(S))
        return -1;
    int i, j;
    int len_S = StrLength_C(S), len_T = StrLength_C(T);
    for(i = pos - 1; i < len_S; i++){
        if(len_S - i < len_T)
            break;
        for(j = 0; j < len_T; j++){
            if(S[i + j] != T[j])
                break;
            if(j == len_T - 1 && S[i + j] == T[j])
                return i + 1;
        }
    }
    return 0;
}

Status StrInsert_C(CString * S, int pos, CString T){
    int len_S = StrLength_C(*S), len_T = StrLength_C(T);
    if(pos < 1 || pos > len_S)
        return ERROR;
    len_S += len_T;
    if((*S = realloc(*S, sizeof(char) * (len_S + 1))) == NULL)
        exit(OVERFLOW);
    for(int i = len_S; i >= len_T + pos - 1; i--)
        (*S)[i] = (*S)[i - len_T];
    for(int i = 0; i < len_T; i++)
        (*S)[pos - 1 + i] = T[i];
    return OK;
}

Status StrDelete_C(CString * S, int pos, int len){
    int len_S = StrLength_C(*S) + 1;
    if(pos < 1 || pos > len_S - len + 1)
        return ERROR;
    for(int i = pos - 1; i <= len_S - len; i++)
        (*S)[i] = (*S)[i + len];
    len_S -= len;
    if((*S = realloc(*S, len_S * sizeof(char))) == NULL)
        exit(OVERFLOW);
    return OK;
}

Status Replace_C(CString * S, CString T, CString V){
    int pos = 1;
    if(StrLength_C(T) == 0)
        return ERROR;
    while((pos = Index_C(*S, T, pos)) > 0){
        if(StrDelete_C(S, pos, StrLength_C(T)) != OK)
            return ERROR;
        if(StrInsert_C(S, pos, V) != OK)
            return ERROR;
        pos += StrLength_C(V);
    }
    return OK;
}

Status DestroyString(CString * S){
    if(*S != NULL){
        free(*S);
        *S = NULL;
    }
    return OK;
}
