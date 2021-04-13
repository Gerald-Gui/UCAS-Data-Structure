#include <cstdio>

int gFunc(int m, int n){
    if(m == 0)
      return 0;
    return gFunc(m - 1, 2 * n) + n;
}

int main(){
	int m, n;
	scanf("%d,%d", &m, &n);
	printf("%d", gFunc(m,n));
	return 0;
}