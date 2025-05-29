#include<iostream>
using namespace std;

void SelectionSort(int arr[], int len){
    for(int i=0; i<len-1; i++){
        int minIndex = i;
        for(int j=i+1; j<len; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }

        }

        swap(arr[minIndex], arr[i]);
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


int main(){
    
    int arr[] = {1,4,2,5,3,7,6,9,8,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr, len);
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
