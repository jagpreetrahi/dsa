#include <iostream>
#include <vector>
using namespace std;

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