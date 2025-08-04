#include<iostream>
using namespace std;

void  BubbleSort(int* arr, int size){
   
    for(int i = 0; i<size-1; i++){
        // for best case just check the one iteration only like that
        int didSwap = 0;
        for(int j = i + 1; j <= size-1 ; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
    }
   
}

int main(){

    int arr[] = {5,1,4,2,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout<<"Befor sorting "<<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    BubbleSort(arr, size);
    cout<<"After sorting "<<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}