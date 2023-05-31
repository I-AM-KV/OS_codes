#include<iostream>
using namespace std;

int size=8;
void FCFS(int arr[], int head)
{
    int count=0;
    int distance, track;
    for(int i=0;i<size;i++){
        track=arr[i];
        distance=abs(track-head);
        count+=distance;
        head=track;
    }
    
    cout<<"Sequence is:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"Total number of operations:"<<count<<endl;
}
int main(){
    int arr[size] = {98,183,41,122,14,124,65,67};
    int head = 53;
    FCFS(arr,head);
    return 0;
}