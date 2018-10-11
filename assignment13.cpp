/*
 * 11th1st.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: student
 */

#include<iostream>
#define M 100
using  namespace std;

class sorting
{
	double per[M];
	int n,top;
public:
	void getn();
	void accept();
	void displaybest();
	void selection_sort();
	void bubble_sort();
	void insertion_sort();

};

void sorting::getn()
{
	cout<<"\nEnter the number of students : ";
	cin>>n;
}

void sorting::accept()
{
	cout<<"\nEnter the percentage of students.\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<i+1<<". ";
		cin>>per[i];
	}
}

void sorting::displaybest()
{
	cout<<"\nThe top 5 scores are :\t";
	for(int i=n-1;i>n-6;i--)
	{
		cout<<per[i]<<"%\t";
	}
}

void sorting::selection_sort()
{
	int temp,min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(per[j]<per[min])
				min=j;
		}
		if(min!=i)
		{
			temp=per[i];
			per[i]=per[min];
			per[min]=temp;
		}
	}
}


void sorting::bubble_sort()
{
	int temp;
	for(int i=1;i<n-1;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(per[j]>per[j+1])
			{
				temp=per[j];
				per[j]=per[j+1];
				per[j+1]=temp;
			}
		}
	}
}

void sorting::insertion_sort()
{
	int temp,j;
	for(int i=0;i<n-1;i++)
	{
		temp=per[i];
		j=i-1;
		while(j>0&&per[j]>temp)
		{
			per[j+1]=per[j];
			j--;
		}
		per[j+1]=temp;
	}
}


int main()
{
	sorting FE1,FE2,FE3;
	char ch;
	int op;
	do
	{
		cout<<"\nEnter\n1 - For BUBBLE SORT.\n2 - For INSERTION SORT.\n3 - For SELECTION SORT.\n";
		cin>>op;
		switch(op)
		{
		case 1:
				FE1.getn();
				FE1.accept();
				FE1.selection_sort();
				FE1.displaybest();
			break;
		case 2 :
				FE2.getn();
				FE2.accept();
				FE2.bubble_sort();
				FE2.displaybest();
			break;
		case 3 :
				FE3.getn();
				FE3.accept();
				FE3.insertion_sort();
				FE3.displaybest();
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

