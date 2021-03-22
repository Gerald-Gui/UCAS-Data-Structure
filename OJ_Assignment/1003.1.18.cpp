#include <cstdio>
#include <cctype>

int main(){
    int cntM[5] = {0}, cntF[5] = {0};
    char type, school, gender;
    int score = 0;
    char c;
    int i = 0;

    while((c = getchar()) != EOF){
        if(isalpha(c))
            switch(++i){
                case 1:
                    type = c;
                    break;
                case 2:
                    gender = c;
                    break;
                case 3:
                    school = c;
                    break;
            }
        else if(isdigit(c))
            if(score != 0)
                score = score * 10 + c - '0';
            else
                score = c - '0';
        else if(c == '\n'){
            if(gender == 'M')
                cntM[school - 'A'] += score;
            else
                cntF[school - 'A'] += score;
            i = score = 0;
        }
    }

    for(i = 0; i < 5; i++){
        if(cntM[i] > 0)
            printf("%c M %d\n", i + 'A', cntM[i]);
        if(cntF[i] > 0)
            printf("%c F %d\n", i + 'A', cntF[i]);
        if(cntM[i] + cntF[i] > 0)
            printf("%c %d\n", i + 'A', cntM[i] + cntF[i]);
    }

    return 0;
}