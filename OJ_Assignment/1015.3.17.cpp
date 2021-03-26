#include <cstdio>

typedef struct ListNode{
    char ch;
    ListNode * nxt;
} * LinkStack;

int main(){
    int flg = 0;
    char c, tmp;
    LinkStack S = nullptr;
    ListNode * p = nullptr;

    while((c = getchar()) != '@'){
        if(flg == 0){
            if(c == '&')
                flg = 1;
            else{
                p = new ListNode;
                p->ch = c;
                p->nxt = S;
                S = p;
            }
        }else if(flg == 1){
            if(S == nullptr){
                printf("0\n");
                return 0;
            }else if(S->ch == c){
                p = S;
                tmp = S->ch;
                S = p->nxt;
                delete p;
                p = nullptr;
            }
        }
    }

    if(S == nullptr)
        printf("1\n");
    else
        printf("0\n");

    return 0;
}