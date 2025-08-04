#include<iostream>

using namespace std;

void BubbleSort(int arr[], int size){
    // base case;
   if(size == 1) return ;
   for(int j = 0; j<= size-2; j++){
     if(arr[j] > arr[j + 1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
     }
   }
   BubbleSort(arr, size-1);
  
}




int main(){

    int arr[] = {5,1,4,2,8};
    int size = sizeof(arr)/ sizeof(arr[0]);
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