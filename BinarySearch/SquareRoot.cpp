#include <iostream>
using namespace std;

int squareRoot(int n){
    int start = 0;
    int end = n;

    while(start<=end){
        long long mid = start + (end - start) / 2;
        long long val = mid * mid;

        if(val <= n){
            start = mid + 1;
        } else{
            end = mid - 1; 
        }
    }
    return end;
}

int main(){
    int n;
    
    cout << "Write the number" << endl;
    cin >> n;
    cout << squareRoot(n) << endl;
    return 0;
}