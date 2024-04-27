#include<bits/stdc++.h>

using namespace std;


void merge(int array[],int const left , int const mid , int const right){
    int const subArrayOne = mid - left +1;
    int const subArrayTwo = right - mid; 
    
    auto *leftArray = new int[subArrayOne];
    auto *rightArray = new int[subArrayTwo];

    for(auto i =0 ; i < subArrayOne ; i++){
        leftArray[i] = array[left +i]; 
    }
    for(auto i = 0; i < subArrayTwo ; i++){
        rightArray[i] = array[mid+1+i];
    }
    
    auto indexOfSubArrayOne =0 , indexOfSubArrayTwo =0;
    int indexOfMergedAraray = left;

    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
        if(leftArray[indexOfSubArrayOne]<=rightArray[indexOfSubArrayTwo]){
            array[indexOfMergedAraray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }else{
            array[indexOfMergedAraray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedAraray++;
    }

    while(indexOfSubArrayOne  < subArrayOne){
        array[indexOfMergedAraray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedAraray++;    
    }
     while(indexOfSubArrayTwo < subArrayTwo){
        array[indexOfMergedAraray] = rightArray[indexOfSubArrayTwo];
        indexOfMergedAraray++;
        indexOfSubArrayTwo++;
     }

    
    delete[] leftArray;
    delete[] rightArray;

}

void mergeSort(int array[] , int const begin , int const end){
    if(begin >= end) return;

    int mid = begin + (end - begin ) / 2;
    mergeSort(array,begin , mid);
    mergeSort(array,mid+1,end);
    merge(array,begin,mid,end);

}

void printArray( int array[] , int size){
    
    cout << endl; 
    for(int i = 0 ; i< size ; i++){
        cout<< array[i] << " ";
    }
    cout<<endl;
}




int main(){

    int array[] = {12,11,13,5,6,7};
    int array_size = sizeof(array)/sizeof(array[0]);

    mergeSort(array,0,array_size-1);
    printArray(array,array_size);
}