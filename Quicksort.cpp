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
void printarr(vector<int>v){
    cout<<"the array elements are"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int partionind(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot&& i<=high-1){
            i++;
        }
        while(arr[i]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quicksort(vector<int>&arr,int low,int high){
    if(low<high){
        int p_index=partionind(arr,low,high);
        quicksort(arr,low,p_index-1);
        quicksort(arr,p_index+1,high);
    }
}

int main()
{
    std::vector<int> v=getarr();
    cout<<"array before sort"<<endl;
    printarr(v);
    cout<<"array after sort"<<endl;
    quicksort(v,0,v.size()-1);
    printarr(v);
}
