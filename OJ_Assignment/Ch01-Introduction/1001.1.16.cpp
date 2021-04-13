#include <cstdio>

int main(){
	int x, y, z;
  
  	scanf("%d %d %d", &x, &y, &z);
  	if(x < y){
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
  	if(z > x)
        printf("%d %d %d\n", z, x, y);
  	else if(z < y)
        printf("%d %d %d\n", x, y, z);
  	else
        printf("%d %d %d\n", x, z, y);
  
  	return 0;  
}