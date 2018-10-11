#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
    struct node* prev;
};


class Number{
    int bits;
    struct node *head, *p;
public:
    void accept();
    void display(int);
    void onesc(Number);
    int twosc(Number);
    int add_num(Number,Number);

};
//-----------------------------------------------------------
void Number::accept(){
    cout<<"Enter number of bits : ";
    cin>>bits;

    struct node *temp;

    temp=new node;
    cin>>temp->data;
    temp->prev=temp->next=NULL;
    head=temp;
    p=head;

    for(int i=0;i<(bits-1);i++)
    {
        temp=new node;
        cin>>temp->data;
        p->next=temp;
        temp->prev=p;
        p=p->next;
    }

    p->next=NULL;
}
//-------------------------------------------------------------
void Number::display(int flag)
{
    p=head;
    if(flag==1)
    {
        for(int i=0;i<bits+1;i++)
        {
            cout<<p->data;
            p=p->next;
        }
    }
    else
    {
        for(int i=0;i<bits;i++)
        {
            cout<<p->data;
            p=p->next;
        }

    }

}
//-------------------------------------------------------------
void Number::onesc(Number N){

    struct node *temp;

    bits=N.bits;
    N.p=N.head;

    temp=new node;
    if(N.p->data==0)
        temp->data=1;
    else if(N.p->data==1)
        temp->data=0;

    temp->next=temp->prev=NULL;
    head=temp;
    p=head;
    N.p=N.p->next;

    for(int i=0;i<(bits-1);i++)
    {
        if(N.p->data==0)
        {
            temp=new node;
            temp->data=1;
            p->next=temp;
            temp->prev=p;
            p=p->next;
        }
        else if(N.p->data==1)
        {
            temp=new node;
            temp->data=0;
            temp->prev=p;
            p->next=temp;
            p=p->next;
        }

        N.p=N.p->next;

    }

    p->next=NULL;

}
//------------------------------------------------------------
int Number::twosc(Number C1)
{
    struct node *temp;

    int cnt=1;
    int flag=0;
    bits=C1.bits;

    temp=new node;
    temp->data=C1.head->data;
    temp->prev=temp->next=NULL;
    head=temp;
    p=head;

    C1.p=C1.head->next;

    for(int i=0;i<bits-1;i++)
    {
            temp=new node;
            temp->data=C1.p->data;
            temp->prev=p;
            p->next=temp;
            p=p->next;
            C1.p=C1.p->next;
    }

    p->next=NULL;

    p=head;

    while(p->next!=NULL)
    {
        p=p->next;
    }

    if(p->data==0)
        p->data=1;
    else
    {
        p->data=0;
        p=p->prev;
        while(p->data!=0)
        {
            p->data=0;

            cnt++;

            if(cnt==bits)
            {
                //cout<<cnt;
                temp=new node;
                temp->next=head;
                head->prev=temp;
                temp->data=0;
                head=temp;
                //p=head;
                flag=1;
            }

            p=p->prev;
        }
        p->data=1;
    }

    return flag;
}
//-------------------------------------------------------------
int Number :: add_num(Number a, Number b)
{
    int carry,flag;
    struct node *temp;

    bits=a.bits;
    a.p=a.head;
    b.p=b.head;

    //--------------------------------------------
    while(a.p->next!=NULL)
        a.p=a.p->next;

    while(b.p->next!=NULL)
        b.p=b.p->next;

    //------------------------------------------
    if(a.p->data==0 && b.p->data==0)
    {
        temp=new node;
        temp->data=0;
        carry=0;
        temp->next=temp->prev=NULL;
        p=temp;
        a.p=a.p->prev;
        b.p=b.p->prev;
    }

    else if(a.p->data==0 && b.p->data==1)
    {
        temp=new node;
        temp->data=1;
        carry=0;
        temp->next=temp->prev=NULL;
        p=temp;
        a.p=a.p->prev;
        b.p=b.p->prev;
    }

    else if(a.p->data==1 && b.p->data==0)
    {
        temp=new node;
        temp->data=1;
        carry=0;
        temp->next=temp->prev=NULL;
        p=temp;
        a.p=a.p->prev;
        b.p=b.p->prev;
    }

    else if(a.p->data==1 && b.p->data==1)
    {
        temp=new node;
        temp->data=0;
        temp->next=temp->prev=NULL;
        p=temp;
        carry=1;
        a.p=a.p->prev;
        b.p=b.p->prev;
    }

    //------------------------------------------------------------

    while(a.p && b.p)
    {

        if(carry==0)
        {
            if(a.p->data==0 && b.p->data==0)
            {
                temp=new node;
                temp->data=0;
                carry=0;
                temp->next=p;
                p->prev=temp;
                p=p->prev;
                a.p=a.p->prev;
                b.p=b.p->prev;
            }

            else if(a.p->data==0 && b.p->data==1)
            {
                temp=new node;
                temp->data=1;
                carry=0;
                temp->next=p;
                p->prev=temp;
                p=p->prev;
                a.p=a.p->prev;
                b.p=b.p->prev;
            }

            else if(a.p->data==1 && b.p->data==0)
            {
                temp=new node;
                temp->data=1;
                carry=0;
                temp->next=p;
                p->prev=temp;
                p=p->prev;
                a.p=a.p->prev;
                b.p=b.p->prev;
            }

            else if(a.p->data==1 && b.p->data==1)
            {
                temp=new node;
                temp->data=0;
                temp->next=p;
                p->prev=temp;
                p=p->prev;
                carry=1;
                a.p=a.p->prev;
                b.p=b.p->prev;
            }

        }

        else if(carry==1)
        {
            if(a.p->data==0 && b.p->data==0)
            {
                temp=new node;
                temp->data=1;
                carry=0;
                temp->next=p;
                p->prev=temp;
                p=p->prev;
                a.p=a.p->prev;
                b.p=b.p->prev;
            }

            else if(a.p->data==0 && b.p->data==1)
            {
                temp=new node;
                temp->data=0;
                carry=1;
                temp->next=p;
                p->prev=temp;
                p=p->prev;
                a.p=a.p->prev;
                b.p=b.p->prev;
            }

            else if(a.p->data==1 && b.p->data==0)
            {
                temp=new node;
                temp->data=0;
                carry=1;
                temp->next=p;
                p->prev=temp;
                p=p->prev;
                a.p=a.p->prev;
                b.p=b.p->prev;
            }

            else if(a.p->data==1 && b.p->data==1)
            {
                temp=new node;
                temp->data=1;
                carry=1;
                temp->next=p;
                p->prev=temp;
                p=p->prev;
                a.p=a.p->prev;
                b.p=b.p->prev;
            }

        }

        head=p;
    }


    if(carry==1)
    {
        temp=new node;
        temp->data=1;
        temp->next=p;
        p->prev=temp;
        p=temp;
        head=temp;
        flag=1;
    }


    return flag;
}
//-------------------------------------------------------------
int main()
{
    int choice;
    int flag=0;
    bool done=false;

    Number N,C1,C2;
    Number N1,N2,SUM;

    cout<<"1. Enter binary number."<<endl;
    cout<<"2. Display number."<<endl;
    cout<<"3. Display 1's complement."<<endl;
    cout<<"4. Display 2's complement."<<endl;
    cout<<"5. Add two binary numbers. "<<endl;
    cout<<"6. Exit."<<endl;

    do{

        cout<<"\n\nEnter the operation you want to perform : ";
        cin>>choice;

        switch(choice)
        {
            case 1 :    N.accept();
                        break;

            case 2 :    cout<<"The binary number is : ";
                        N.display(flag);
                        break;

            case 3 :    cout<<"1's complement is : ";
                        C1.onesc(N);
                        C1.display(flag);
                        break;

            case 4 :    cout<<"2's complement is : ";
                        flag=C2.twosc(C1);
                        C2.display(flag);
                        break;

            case 5 :    cout<<"\nEnter first number : "<<endl;
                        N1.accept();
                        cout<<"\nEnter second number : "<<endl;
                        N2.accept();
                        cout<<"\nYou entered : "<<endl;
                        N1.display(flag);
                        cout<<"\n";
                        N2.display(flag);
                        cout<<"\n\n";
                        cout<<"Addition of both numbers : ";
                        flag=SUM.add_num(N1,N2);
                        SUM.display(flag);

            case 6 :    done=true;
                        break;


        }


    }while(done==false);
return 0;
}
