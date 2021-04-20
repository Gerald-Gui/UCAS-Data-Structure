#include <iostream>

using namespace std;

int pow(int base, int times);

int main(){
    int x, n, a;
    int sum = 0;

    cin >> x >> n;
    for(int i = 0; i <= n; i++){
        cin >> a;
        sum += a * pow(x, i);
    }

    cout << sum << endl;

    return 0;
}

int pow(int base, int times){
    if(times == 0)
        return 1;
    int tmp = base;
    for(int i = 1; i < times; i++)
        base *= tmp;
    return base;
}