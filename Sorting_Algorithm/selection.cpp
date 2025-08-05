/* Selection sort is a sorting algorithm that repeatedly select the min-element of the array and moves to the beginning

  How it works -> 1. Start from the first element.
     2. Find the minimum element in the unsorted part.
     3. Swap it with the current element.
     4. Moves to the next positon and repeat the process agian until the array is sorted
    
    Time Complexity -> best or average or worst -> O(n^2) for worst case - it still check all elemens to find minimum
    Space Complexity ->  O(1)                         
                
*/
#include <iostream>
using namespace std;

void selectionSort(int arr[], int size){

    if(size == 0){
        cout<<"No element to be sorted";
    }
    // outer loop for start from the first index and goes up to the last element
    
    for(int i = 0; i <size -1; i++){
       int minElement = i;
       for(int j = i + 1; j<size; j++){
          if(arr[j] < arr[minElement]){
            minElement = j;
          }
       }
       int temp = arr[minElement];
       arr[minElement] = arr[i];
       arr[i] = temp;
       
    }
    cout <<"After the sorting "<<endl;
    for(int i = 0 ; i<size; i++){
        cout <<arr[i]<<" ";
    }

}


int main(){

    int arr[] = {5,2,7,3,1,8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<"Before sorting the array "<<endl;
    for(int i = 0; i<size; i++){
        cout <<arr[i]<<" ";
    }
    selectionSort(arr,size);
    
    return 0;
}