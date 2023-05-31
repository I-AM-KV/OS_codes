// SSTF Disk Scheduling Algorithm
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int queue[100],t[100];
	int head,seek=0,n,i,j,temp;
	float avg;

	cout<<"Enter the size of Queue: ";
	cin>>n;
	cout<<"Enter the  Process Sequence: ";
	for(i=0;i<n;i++)
		cin>>queue[i];
	cout<<"Enter the initial head position: ";
	cin>>head;

	for(i=1;i<n;i++)
		t[i]=abs(head-queue[i]);

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(t[i]>t[j]){
				temp=t[i];
				t[i]=t[j];
				t[j]=temp;
				temp=queue[i];
				queue[i]=queue[j];
				queue[j]=temp;
			}
		}
	}
	for(i=1;i<n-1;i++){
		seek=seek+abs(head-queue[i]);
		head=queue[i];
	}
    
	cout<<"Total Seek Time is "<<seek<<endl;
	avg=seek/(float)n;
	cout<<"Average Seek Time is "<<avg;
	return 0;
}