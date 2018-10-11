#include<iostream>
#include<string.h>
using namespace std;

struct spm
{
 int row,col;
 int nval;
};

class sparse
{
  //  int row,col;
// int nval;
 spm sp1[10],sp2[10],sp3[20],spltr[10],fstr[10];
 int mat1[10][10],mat2[10][10]; //data members
 int r1,r2,c1,c2,i,j,k;
 public:
 sparse()             //default constructor
 {
  r1=r2=i=0;
  j=k=0;
  c1=c2=0;
 }
 void getmat();
 void showmat();       //member function
 void addspm();
 void simpl_trnspose();
 void fast_trnspose();
};


void sparse::getmat()
{

 cout<<"\nHow many rows in mat1:";
 cin>>r1;
 cout<<"\nHow many cols in mat1:";
 cin>>c1;
 for(i=0;i<r1;i++)
 {
  for(j=0;j<c1;j++)
  {
   cout<<"\nEnter ["<<i<< "]["<<j<<"] value of mat1: ";
   cin>>mat1[i][j];
  }
 }
 //To store second matrix
 cout<<"\nHow many rows in mat2:";
 cin>>r2;
 cout<<"\nHow many cols in mat2:";
 cin>>c2;
 for(i=0;i<r2;i++)
 {
  for(j=0;j<c2;j++)
  {
   cout<<"\nEnter ["<<i<< "]["<<j<<"] value of mat2: ";
   cin>>mat2[i][j];
  }
 }
}


void sparse::showmat()
{

 cout<<"\n Matrix 1 value are as follows\n";
 for(i=0;i<r1;i++)
 {
  for(j=0;j<c1;j++)
  {
   cout<<"\t"<<mat1[i][j];
  }
  cout<<"\n";
 }

 cout<<"\n Matrix 2 value are as follows\n";
 for(i=0;i<r2;i++)
 {
  for(j=0;j<c2;j++)
  {
   cout<<"\t"<<mat2[i][j];
  }
  cout<<"\n";
 }
}


void sparse::addspm()
{
 int n1,n2;
 n1=n2=0;

 sp1[0].row=r1;
 sp1[0].col=c1;
 k=1;
 cout<<"\n Sparse matrix1 non_zero value are as follows:\n";
 for(i=0;i<r1;i++)
 {
  for(j=0;j<c1;j++)
  {
   if(mat1[i][j]!=0)
   {
    sp1[k].row=i;
    sp1[k].col=j;
    sp1[k].nval=mat1[i][j];
    k=k+1;
   }
  }
 }
 sp1[0].nval=k-1;

 cout<<"\nRow\tCol\tnval";
 for(i=0;i<k;i++)
 {
  cout<<"\n"<<sp1[i].row<<"\t"<<sp1[i].col<<"\t"<<sp1[i].nval;
 }

 cout<<"\n\nSparse matrix2 non_zero value are as follows:\n";
 sp2[0].row=r2;
 sp2[0].col=c2;
 k=1;
 for(i=0;i<r2;i++)
 {
  for(j=0;j<c2;j++)
  {
   if(mat2[i][j]!=0)
   {
    sp2[k].row=i;
    sp2[k].col=j;
    sp2[k].nval=mat2[i][j];
    k=k+1;
   }
  }
 }
 sp2[0].nval=k-1;

 cout<<"\nRow\tCol\tnval";
 for(i=0;i<k;i++)
 {
  cout<<"\n"<<sp2[i].row<<"\t"<<sp2[i].col<<"\t"<<sp2[i].nval;
 }

 n1=sp1[0].nval;
 n2=sp2[0].nval;
 i=j=k=1;
 cout<<"\n No of term in sp1:"<<n1<<"\tNo of term in sp2:"<<n2;
 //2.Store the largest row and colom term of both matrices in sp3 row and col.
 if(sp1[0].row>sp2[0].row)
 {
  sp3[0].row=sp1[0].row;
 }
 else
 {
  sp3[0].row=sp2[0].row;
 }

 if(sp1[0].col>sp2[0].col)
 {
  sp3[0].col=sp1[0].col;
 }
 else
 {
  sp3[0].col=sp2[0].col;
 }

 while((i<=n1)&&(j<=n2))//check for both term
 {
  if(sp1[i].row==sp2[j].row)//check if rows are same in sp1 and sp2.
  {
   if(sp1[i].col==sp2[j].col)//check if cols are same in sp1 and sp2.
   {
    sp3[k].row=sp1[i].row;
    sp3[k].col=sp1[i].col;
    sp3[k].nval=sp1[i].nval+sp2[j].nval; //if yes add both non zero values and store in sp3 with row,col and values detail.
    cout<<"\nvalu of add:"<<sp3[k].nval;
    i++;
    j++; //increment all indexes.
    k++;
    cout<<"\nval of i:"<<i<<"\tval of j:"<<j<<"\tval of k:"<<k;

   }
   else if(sp1[i].col<sp2[j].col)//check col of sp1 is less than col of sp2
   {
    sp3[k].row=sp1[i].row;
    sp3[k].col=sp1[i].col;
    sp3[k].nval=sp1[i].nval; //if yes store all values of sp1 in sp3
    i++;
    k++; //increment i and k.
    cout<<"\nval of i:"<<i<<"\tval of K:"<<k;
   }
   else
   {
    sp3[k].row=sp2[j].row;
    sp3[k].col=sp2[j].col;   //if no store all values of sp2 in sp3
    sp3[k].nval=sp2[j].nval;
    j++;
    k++; //increment j and k.
    cout<<"\nval of j:"<<j<<"\tval of K:"<<k;
   }
  }
  else if(sp1[i].row<sp2[j].row)//check row of sp1 is less than row of sp2
  {
   sp3[k].row=sp1[i].row;
   sp3[k].col=sp1[i].col;
   sp3[k].nval=sp1[i].nval; //if yes store all values of sp1 in sp3
   i++;
   k++;
   cout<<"\nval of i:"<<i<<"\tval of K:"<<k;
  }
  else
  {
   sp3[k].row=sp2[j].row;
   sp3[k].col=sp2[j].col;     //if no store all values of sp2 in sp3
   sp3[k].nval=sp2[j].nval;
   j++;
   k++;
   cout<<"\nval of j:"<<j<<"\tval of K:"<<k;
  }
 }//end of while loop
 while(i<=n1)    //Store remaining terms of sp1 in sp3 if above while (i<=n1&&j<=n2) is not true
 {
  sp3[k].row=sp1[i].row;
  sp3[k].col=sp1[i].col;
  sp3[k].nval=sp1[i].nval;
  i++;
  k++;
  cout<<"\nval of outer while i:"<<i<<"\tval of K:"<<k;
 }
 while(j<=n2)
 {
  sp3[k].row=sp2[j].row; //Store remaining terms of sp2 in sp3 if above while (i<=n1&&j<=n2) is not true.
  sp3[k].col=sp2[j].col;
  sp3[k].nval=sp2[j].nval;
  j++;
  k++;
  cout<<"\nval of  outer while j:"<<j<<"\tval of K:"<<k;
 }
 sp3[0].nval=k-1;
 //Display the addition result which is inside sp3.
 cout<<"\nRow\tCol\tnval";
 for(i=0;i<k;i++)
 {
  cout<<"\n"<<sp3[i].row<<"\t"<<sp3[i].col<<"\t"<<sp3[i].nval;
 }
}

void sparse::simpl_trnspose()
{
 //chainging the rows of sp1  to columns in spltr structure.
 spltr[0].row=sp3[0].col;
 spltr[0].col=sp3[0].row;
 spltr[0].nval=sp3[0].nval;
 k=1;
 for(i=0;i<=spltr[0].row;i++)//To check number of colms
 {
  for(j=0;j<=spltr[0].nval;j++)//To check value in total no of non zero values
  {
   if(sp3[j].col==i)// if found swap the rows into colom and colm into rows.
   {
    spltr[k].row=sp3[j].col;
    spltr[k].col=sp3[j].row;
    spltr[k].nval=sp3[j].nval;
    k++;
   }
  }
 }//Total time required to execute is O(n*n).
 cout<<"\n\n Simple Transpose of addition matrix are as follows...";
 cout<<"\nRow\tCol\tnval";
 for(i=0;i<k-1;i++)
 {
  cout<<"\n"<<spltr[i].row<<"\t"<<spltr[i].col<<"\t"<<spltr[i].nval;
 }
}

void sparse::fast_trnspose()
{
 int term[5],pos[5];
 //First 0th row interchange row and col value.
 fstr[0].row=sp3[0].col;
 fstr[0].col=sp3[0].row;
 fstr[0].nval=sp3[0].nval;
 //initialize the term as zero.
 for(i=0;i<=sp3[0].col;i++)
 {
  term[i]=0;
 }
 //Now find out how mnay times the col occures in nonzero value.
 for(i=1;i<=sp3[0].nval;i++)
 {
  //term[sp3[i].col]=term[sp3[i].col]+1;
  term[sp3[i].col]++;
 }
 //find out the actual position of each term i:e coloms in row.
 pos[0]=1;
 for(i=1;i<=sp3[0].col;i++)
 {
  pos[i]=pos[(i-1)]+term[(i-1)];
 }
 //fid the position and interchange the value.
 for(i=1;i<=sp3[0].nval;i++)
 {
  j=pos[sp3[i].col];
  fstr[j].row=sp3[i].col;
  fstr[j].col=sp3[i].row;
  fstr[j].nval=sp3[i].nval;
  pos[sp3[i].col]=j+1;
 }
 cout<<"\n\n Fast Transpose of addition matrix are as follows...";
 cout<<"\nRow\tCol\tnval";
 for(i=0;i<=fstr[0].nval;i++)
 {
  cout<<"\n"<<fstr[i].row<<"\t"<<fstr[i].col<<"\t"<<fstr[i].nval;
 }
}


int main()
{
 int n;
 sparse s1;  //s1 object of class sparse
 s1.getmat();
 s1.showmat();  //calling of member functions.
 s1.addspm();
 s1.simpl_trnspose();
 s1.fast_trnspose();
// getch();
 cout<<"\nPress one to exit....";
 cin>>n;

 return 0;
}
