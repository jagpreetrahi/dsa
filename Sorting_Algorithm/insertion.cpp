/* Insertion sort is a sorting algorithm that perform better on small datasets.

  How it works -> Select an element in each iteration from the unsorted array and places to its appropriate posotion.
    
    Time Complexity -> average or worst -> O(n^2) and best case -> O(n) if array is already sorted.
    Space Complexity ->  O(1)                         
                
*/
#include <iostream>
using namespace std;

void insertionSort(int arr[] , int size){

    for(int i = 0; i <size; i++){
       int j = i;
       while(j > 0 && arr[j-1] > arr[j]){
          int temp = arr[j-1];
          arr[j-1] = arr[j];
          arr[j] = temp;
          j--;
       }
    }

    cout<<"After the sorting "<<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i] << " ";
    }
}

int main(){

    int arr[] = {5,3,7,1,2,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout <<"Before the sorting "<<endl;
    for(int i = 0 ; i<size; i++){
        cout <<arr[i] << " ";
    }
    insertionSort(arr, size);
    return 0;
}