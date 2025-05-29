#include<iostream>
using namespace std;

void BubbleSort(int arr[], int len){
    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    
    int arr[] = {1,4,2,5,3,74,36,9,8,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, len);
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
