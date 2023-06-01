// Priority -- Non Preemptive
#include<iostream>
using namespace std;
int at[5],bt[5],p[5],pId[5];

int allDone(int count){
	for(int i=0 ; i<count ; i++){
		if(bt[i] != 0)
			return 0;
	}
	return 1;
}

int main()
{
	int wt,tat,rt,count,i,j;
	int currTime, prevTime, procExec;
	wt=tat=rt=0;
	currTime = prevTime = procExec = 0;
	cout<<"Enter Number of Processes : ";
	cin>>count;
	//Take Input
	for(i=0 ; i<count ; i++)
	{
		cout<<"Enter Burst Time, Arrival Time and Priority for "<<i+1<<" process : ";
		cin>>bt[i]>>at[i]>>p[i];
		pId[i]=i+1;
	}
	//Sort wrt AT
	for(i=0 ; i<count ; i++){
		for(j=0 ; j<count-1 ; j++){
			if(at[j]>at[j+1]){
				int temp = bt[j+1];
				bt[j+1] = bt[j];
				bt[j] = temp;

				temp = at[j+1];
				at[j+1]= at[j];
				at[j] = temp;

				temp = pId[j+1];
				pId[j+1] = pId[j];
				pId[j] = temp;

				temp = p[j+1];
				p[j+1] = p[j];
				p[j] = temp;
			}
		}
	}
	int maxAt = at[count-1];

	//Executing process at At[0]
	tat += bt[0];
	cout<<"P"<<pId[0]<<" -- AT:"<<at[0]<<", BT:"<<bt[0]<<", Priority: "<<p[0]<<", WT:"<<wt<<", TAT:"<<tat<<", RT:"<<rt<<endl;
	prevTime = currTime;
	currTime += bt[0];
	bt[0] = 0;
	procExec++;

	while(!allDone(count))
	{
		int temp = 0;
		//Check if There is any process In Ready Queue
		for (i=0 ; i<count; i++){
			if (at[i] <= currTime)
				temp++;
		}

		//If There is any Process than temp > executedProcesses
		if(temp > procExec){
			//Sort acc to Priority
			for(i=0 ; i<temp; i++){
				for(j=0 ; j<temp-1; j++){
					if (p[j]>p[j+1]){
						int temp1 = bt[j];
						bt[j] = bt[j+1];
						bt[j+1] = temp1;

						temp1 = at[j];
						at[j] = at[j+1];
						at[j+1] = temp1;

						temp1 = pId[j];
						pId[j] = pId[j+1];
						pId[j+1] = temp1;

						temp1 = p[j];
						p[j] = p[j+1];
						p[j+1] = temp1;
					}
				}
			}

			i = 0;
			while(bt[i]==0)
				i++;

			wt = currTime - at[i];
			tat = wt + bt[i];
			cout<<"P"<<pId[i]<<" -- AT:"<<at[i]<<", BT:"<<bt[i]<<", Priority:"<<p[i]<<", WT:"<<wt<<", TAT:"<<tat<<", RT:"<<rt<<endl;
			prevTime = currTime;
			currTime += bt[i];
			bt[i] = 0;
			procExec++;
		}
		else{
			currTime++;
			wt = 0;
		}
	}
	cout<<"All Processes End after "<<currTime<<" units";
    return 0;
}