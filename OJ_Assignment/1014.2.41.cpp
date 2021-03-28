#include <cstdio>
#include <cmath>
#include <cctype>

typedef struct PolyNode{
    int coe;
    int exp;
    PolyNode * nxt;
} * LinkedPoly;

void PrintLinkPoly(LinkedPoly L){
    PolyNode * p = L->nxt;
    if(p == L)
        printf("0\n");
    else{
        while(p != L){
            if(p->coe < 0)
                printf("- ");
            else if(p != L->nxt)
                printf("+ ");
            if(abs(p->coe) != 1 || p->exp == 0)
                printf("%d", abs(p->coe));
            if(p->exp == 1)
                printf("x ");
            else if(p->exp != 0)
                printf("x^%d ", p->exp);
            else if(p->exp == 0)
                printf(" ");
            p = p->nxt;
        }
        printf("\n");
    }
}

PolyNode * GetItem(){
    char c;
    
    while(isspace(c = getchar()))
        ;
    if(c == EOF)
        return nullptr;
    PolyNode * p = new PolyNode;
    p->nxt = nullptr;
    p->coe = p->exp = 0;
    int sign = 1;
    if(c == '-')
        sign = -1;
    if(c == '-' || c == '+')
        while(isspace(c = getchar()))
            ;
    if(isdigit(c)){
        p->coe = p->coe * 10 + c - '0';
        while(isdigit(c = getchar()))
            p->coe = p->coe * 10 + c - '0';
    }
    if(c == 'x'){
        if(p->coe == 0)
            p->coe = 1;
        if((c = getchar()) != '^')
            p->exp = 1;
        else
            while(isdigit(c = getchar()))
                p->exp = p->exp * 10 + c - '0';
    }else
        p->exp = 0;
    p->coe *= sign;
    return p;
}

LinkedPoly BuildPoly(){
    PolyNode * L = new PolyNode, * p = nullptr, * q = nullptr, * prev = nullptr;
    L->nxt = L;
    while((p = GetItem()) != nullptr){
        q = L->nxt;
        prev = L;
        while(q != L){
            if(q->exp <= p->exp)
                break;
            q = q->nxt;
            prev = prev->nxt;
        }
        if(q == L){
            p->nxt = L;
            prev->nxt = p;
        }else if(q->exp == p->exp){
            q->coe += p->coe;
            if(q->coe == 0){
                prev->nxt = q->nxt;
                delete q;
                q = nullptr;
            }
            delete p;
            p = nullptr;
        }else{
            p->nxt = q;
            prev->nxt = p;
        }
    }
    return L;
}

void DifPoly(LinkedPoly L){
    PolyNode * p = L->nxt, * prev = L;
    while(p != L){
        p->coe *= p->exp;
        p->exp--;
        if(p->exp < 0){
            prev->nxt = p->nxt;
            delete p;
            p = prev->nxt;
        }else{
            p = p->nxt;
            prev = prev->nxt;
        }
    }
}

int main(){
    LinkedPoly L = BuildPoly();
    DifPoly(L);
    PrintLinkPoly(L);
    return 0;
}