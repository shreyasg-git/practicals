
//name:suhas mavatkar
//roll.no:44
//practical no:2

#include <iostream>

using namespace std;


void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
   
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        
    }
}


void selection(int *arr, int n){
    int imin;
    for(int i=0;i<n;i++){
        imin = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[imin]){
                imin=j;
            }
        }
        swap(&arr[i],&arr[imin]);
    }
    
}

int main()
{
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //dispalying the array
    cout<<"the array is: ";
    display(arr,n);
    //selection sorting the array
    selection(arr,n);
    //after sorting, dispalying
    cout<<"\nsorted arr is: ";
    display(arr,n);
    return 0;
}
