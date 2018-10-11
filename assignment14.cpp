/*
 * qs.cpp
 *
 *  Created on: Sep 24, 2018
 *      Author: student
 */

/*
 * qsort.cpp
 *
 *  Created on: Sep 19, 2018
 *      Author: student
 */


#include<iostream>
#define M 100
using  namespace std;

class Quick_sort
{
	double per[M];
	int n,top;
public:
	void getn();
	void accept();
	void displaybest();
	void process();
	void quick_sort(int low,int high);
	int partition(int l, int h);
	void swap(int i,int j);
};

void Quick_sort::getn()
{
	cout<<"\nEnter the number of students : ";
	cin>>n;
}

void Quick_sort::accept()
{
	cout<<"\nEnter the percentage of students.\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<i+1<<". ";
		cin>>per[i];
	}
}

void Quick_sort::displaybest()
{
	cout<<"\nThe top 5 scores are :\t";
	for(int i=n-1;i>n-6;i--)
	{
		cout<<per[i]<<"%\t";
	}
}

void Quick_sort::quick_sort(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = partition(low,high);
		quick_sort(low,mid-1);
		quick_sort(mid+1,high);
	}
}


int Quick_sort::partition(int l, int h)
{
	int i,j,temp;
	i=l+1;
	j=h;

	while(1)
	{
		while(per[i++]<per[l] && i<h);
			i--;
		while(per[j--]>per[l] );
			j++;
		if(i>=j)break;
			/*temp=b[i];
			b[i]=b[j];
			b[j]=temp;*/
		swap(i,j);
	}
	swap(j,l);
	return j;
}

void Quick_sort::swap(int i,int j)
{
	if(i==j || i<0 || j>=n)return;
	int temp;
	temp=per[j];
	per[j]=per[i];
	per[i]=temp;
}
 void Quick_sort::process()
 {
	 quick_sort(0,n-1);
	// cout<<"\nThe top 5 scores are :\t";
	 	for(int i=0;i<n;i++)
	 	{
	 		cout<<per[i]<<"%\t";
	 	}
 }

int main()
{
	Quick_sort FE1;
	char ch;
	int op;
	do
	{
		cout<<"\nEnter\n1 - For Quick Sort.\n";
cin>>op;
		switch(op)
		{
		case 1:
				FE1.getn();
				FE1.accept();
				FE1.process();
				FE1.displaybest();
			break;

		default:
			cout<<"\nINVALID ENTRY\n";
		}
		cout<<"\nDo you want to continue??? (y/n) : ";
		cin>>ch;
	}while(ch=='y');
	cout<<"\n!!!END!!!\n";
	return 0;
}
//10 10 20 30 40 50 60 70 80 90 100
//5 40 50 60 20 30


