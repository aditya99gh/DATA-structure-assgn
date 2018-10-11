#include <iostream>
using namespace std;

int main()
{
    int l1=0,l2=0,i,j;
    char c[40];
    char a[20]="Hello";
    char b[20]="World";

    cout<<"string 1:";
    for( i=0;a[i]!='\0';i++)
        cout<<a[i];
    cout<<"\nstring 2:";
    for(i=0;b[i]!='\0';i++)
        cout<<b[i];

    //strlen
    for(i=0;a[i]!='\0';i++)
        l1++;
    cout<<"\n\nlength of string 1:"<<l1;
    for(i=0;b[i]!='\0';i++)
        l2++;
    cout<<"\nlength of string 2:"<<l2;

    //strcat
    for( i=0;a[i]!='\0';i++)
        c[i]=a[i];
    for(j=0;b[j]!='\0';j++)
    {
        c[i]=b[j];
        i++;
    }
    c[i]='\0';
    cout<<"\n\nafter concatenation:";
    for( i=0;c[i]!='\0';i++)
        cout<<c[i];

    //strcmp
    for(i=0,j=0;a[i]!='\0' && b[j]!='\0';i++,j++)
    {
        if(a[i]!=b[j])
        {
            int p= (int)a[i];
            int s =(int)b[j];
            break;
        }
    }
    cout<<"\n\nafter comparison:";
    if(a>b)
        cout<<"string 1 is greater than string 2";
    else if(a==b)
        cout<<"string 1 is equal to string 2";
    else
        cout<<"string 1 is less than string 2";

    //strcpy
    for( i=0;b[i]!='\0';i++)
        a[i]=b[i];
    cout<<"\n\nafter copying string 2 to string 1:";
    for( i=0;a[i]!='\0';i++)
        cout<<a[i];

    //reverse
    i=0;j=l2-1;
    while(i<j)
    {
        char temp;
        temp=b[i];
        b[i]=b[j];
        b[j]=temp;
        i++;
        j--;
    }
    cout<<"\n\nreversed string:";
    for(i=0;b[i]!='\0';i++)
        cout<<b[i];

    return 0;
}
