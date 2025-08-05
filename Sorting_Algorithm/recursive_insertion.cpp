/* In this algorithm , we use recursive appraoch in order to sort the unsorted array into sorted one instead of using the 
  iteration approach. 
  How it works ->  recursively call the function by increase the i pointer and decrease the j pointer to places the current elment to is left side.

    Time Complexity -> average or worst -> O(n^2) and best case -> O(n) if array is already sorted.
    Space Complexity ->  O(n) due to the recursion stack    
*/
#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int> & arr, int size, int i){

   // base case
   if(i == size) return;
   int j = i; // imagine this represent the i + 1 index 
   while(j > 0 && arr[j-1] > arr[j]){
      swap(arr[j-1] , arr[j]);
      j--;
   }
   InsertionSort(arr, size, i + 1);
    
}

vector<int> recursiveInsertionSort(vector <int> &arr, int size){

    int i = 0; // for iterate through the unsorted array
    InsertionSort(arr, size, i);
    return arr;

}


int main(){

    vector <int> arr = {13,46,24,52,20,9};
    int size = arr.size();

    cout<<"Before sorting the algo"<<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    arr = recursiveInsertionSort(arr, size);
    cout<<"After the sorting "<<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}