
#include <iostream>
#include <bits/stdc++.h>


using namespace std;
vector<int> getarr(){
    int n;
    cout<<"enter the size of arr"<<endl;
    std::cin >> n;
    vector<int>res;
    
    while(n--){
        int temp;
        cin>>temp;
        res.push_back(temp);
    }
    return res;
}
void Merge(vector<int>&arr,int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    vector<int>l1,r1;

    //making 2 half arrays and filling it
    for(i=0;i<n1;i++){
        l1.push_back(arr[left+i]);
    }
    for(j=0;j<n2;j++){
        r1.push_back(arr[mid+1+j]);
    }
    i=0;j=0;
    k=left;
    while(i<n1&&j<n2){
        if(l1[i]<=r1[j]){
            arr[k++]=l1[i++];
        }else{
            arr[k++]=r1[j++];
        }
    }
    while(i<n1){
        arr[k++]=l1[i++];
    }
    while(j<n2){
        arr[k++]=r1[j++];
    }
}
void Mergesort(vector<int>&arr,int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        Mergesort(arr,left,mid);
        Mergesort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}
void printarr(vector<int>v){
    cout<<"the array elements are"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int>v=getarr();
    cout<<"array before sort"<<endl;
    printarr(v);
    Mergesort(v,0,v.size()-1);
    cout<<"array after sort"<<endl;
    printarr(v);
}
