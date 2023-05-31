// FCFS -- With Arrival Time
#include<iostream>
using namespace std;

int main()
{
	int bt[5],at[5],pId[5],ct=0;
	int wt,tat,rt,count,i,j;float avgtat,avgwt;
	wt=tat=rt=avgtat=avgwt=0;

	

	cout<<"Enter Number of Processes : ";
	cin>>count;

	//Take Input
	for(i=0 ; i<count ; i++)
	{
		cout<<"Enter Burst Time and Arrival Time  for "<<i+1<<" process : ";
		cin>>bt[i]>>at[i];
		pId[i]=i+1;
	}
	//Sort wrt AT
	for(i=0 ; i<count ; i++){
		for(j=0 ; j<count-1 ; j++){
			if(at[j]>at[j+1]){
				int temp = at[j+1];
				at[j+1] = at[j];
				at[j] = temp;

				temp = bt[j+1];
				bt[j+1] = bt[j];
				bt[j] = temp;

				temp = pId[j+1];
				pId[j+1] = pId[j];
				pId[j] = temp;
			}
		}
	}

cout<<endl<<"Process\t  Arrival time\t    Burst time \tComp time\tWait time\tTat"<<endl;
	for(i=0 ; i<count ; i++)
	{
		ct=ct+bt[i];
		tat=ct-at[i];
		avgtat+=tat;
		wt=tat-bt[i];
		avgwt+=wt;
		cout<<"P["<<pId[i]<<"]"<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<ct<<"\t\t"<<wt<<"\t"<<tat<<endl;	
	}
	cout<<"Average turn around time : "<<(avgtat/count)<<endl;
	cout<<"Average waiting time : "<<(avgwt/count);
	return 0;
}