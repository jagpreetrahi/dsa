#include <iostream>
#include <vector>
using namespace std;

void merge(vector <int> & arr, int low, int mid ,int high){

    // pointer for compare the array elements
    int left = low;
    int right = mid + 1;
    // temporrary array;
    vector <int> temp;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    // for the left halve remain element
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
      // for the right halve remain element
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    // traversing to the temp array and assign to the original array
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
    
}

// this is only for divide the array into the sub-array
void mergeSort(vector <int> &arr, int low , int high){
    
    // base case
    if(low >= high) return;
    int mid = (low + high)/2;
    // divide the array left half
    mergeSort(arr, low , mid);
    // divide the array right halves
    mergeSort(arr, mid + 1, high);
    // merge them into the sorted way
    merge(arr, low, mid , high);
    
}


int main(){

    vector<int> arr = {8,2,5,1,7,3};
    int size = arr.size();
    int low = 0;
    int high = size - 1;
    cout<<"before sorting the array"<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    mergeSort(arr, low, high);
    cout<<"after the sorting"<<endl;
    for(int i =0; i<size; i++){
        cout<<arr[i]<< " ";
    }
    return 0;
}