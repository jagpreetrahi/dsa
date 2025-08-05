/* Quick Sort is a sorting  algorithm that based on the divide and conqueror strategy. It uses the nlogn comparison. It is in-places algorithm
  It does by selecting a pivot element , it can be --
   1. first or last element
   2. middle element
   3. random element
  
   After placing the pivot to its correct position , all the smaller unsorted elements are to be places on its left side
   and the greater elements on its right side.
  

  How it works -> 1. Select a pivot.
        2. Rearrange the array i.e. all the smaller elements on its left and all greater elements on its right side.
        3. Divide the array into subarray, until the size of an array is to a single element.
        4. Repeat the process until the array is sorted.
    
    Time Complexity -> o(logn) - due to divide the array into sub array.
        O(n) due to merging the blocks
        Total TC -> O(n logn)
    Space Complexity -> it does by recursion depth , not the array copying
        best case or average -> O(n) due to pivot divide the array into two half leading to log n recursive call  .
        worst case -> O(n) due to pivot always pick smaller or larger , leading to unbalanced partition  and n recursive call                           
                
*/

#include <iostream>
#include <vector>
using namespace std;

// if the pivot is first element -> TC -> O(n)
int firstElementPartition(vector<int> &arr, int low, int high){
    int i = low; 
    int j = high -1; 
    int pivot = arr[low];
    while(i<j){

        while(arr[i] <= pivot && i <= high -1){
            i++;
        }

        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i<j) swap(arr[i] , arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

// Lomuto Partition Schema
int partition(vector<int> &arr, int low, int high){

    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void qs(vector<int> &arr, int low, int high){

    if(low < high){
        int partitionIndex = partition(arr, low , high);
        qs(arr, low, partitionIndex - 1);
        qs(arr, partitionIndex + 1, high);
    }
}


vector<int> quickSort(vector<int> &arr, int low ,int high){
    qs(arr, low , high);
    return arr;
}

int main(){

    vector<int> arr = {5,2,1,7,3,4};
    int size = arr.size();
    int low = 0;
    int high = size -1 ;
    cout<<"Before the sorting "<<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i]<< " ";
    }
    
    arr = quickSort(arr, low, high);
    cout<<"After the sorting "<<endl;
    for(int i = 0; i< size; i++){
        cout <<arr[i]<< " ";
    }
    return 0;
}