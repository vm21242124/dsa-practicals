#include <iostream>
//heapify is the process making heap from given array
//we can find the no of leaf node by (size/2)+1 eg arr size of 5 (5/2)+1 3 there are 3 leaf nodes 
//ie they are already in correct position n/2+1 to n
//we have to process only 1 to n/2+1 index

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n&& arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

int main()
{
    
    int arr[6]={-1,50,54,30,40,10};
    int n=5;
    cout<<"printing before heapify"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"printing after heapify"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
