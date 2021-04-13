#include <iostream>
#include <cstring>

using namespace std;

constexpr int arrsize = 200;

int main(){
    int arr[arrsize];
    memset(arr, 0, sizeof(int) * arrsize);
    arr[0] = 1;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        arr[i] = i * arr[i / 2];
    cout << arr[n] << endl;
    return 0;
}