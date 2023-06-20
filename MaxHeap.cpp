#include <iostream>
//heap is compleate binary tree ie sorted 
//max heap eg
//         60
//     50      40
// 30      20
//impl possible in form of array 
//we can access the left child 2*i
//we can access the right child 2*i+1
//we can find parent of child i/2


using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;   
    }
    void insert(int val){
        size=size+1;
        int ind=size;
        arr[ind]=val;
        while(ind>1){
            int parent=ind/2;
            if(arr[parent]<arr[ind]){
                swap(arr[ind],arr[parent]);
                ind=parent;
                
            }else{
                return;
            }
        }
    }
    //deletion
    void deleteroot(){
        if(size==0){
            cout<<"the heap is empty"<<endl;
            return;
        }
        //step 1 put last element in first postion
        arr[1]=arr[size];
        size--; //decreasing size because noone can access
        int i=1;
        //step 2 taking all node to its correct position 
        while(i<size){
            int leftchildind=2*i;
            int rightchildind=2*i+1;
            if(leftchildind<size && arr[i]<arr[leftchildind]){
                swap(arr[i],arr[leftchildind]);
                i=leftchildind;
            }else if(rightchildind<size&& arr[i]<arr[rightchildind]){
                swap(arr[i],arr[rightchildind]);
                i=rightchildind;
            }else{
                return;
            }
        }
    }
    
    
    
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(5);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.print();
    h.deleteroot();
    h.print();

    return 0;
}
