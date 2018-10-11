#include<iostream>
#include<string>
using namespace std;

struct node
{
    int prn;
    string name;
    struct node *next;
};
//-------------------------------------------------------------------
class LinkList
{
    node *p,*q,*head;
    int n=0;
public:
    void add_node();
    void display_LL();
    void delete_node();
    void merge_LL(LinkList,LinkList);
    int cal_members();

};
//-------------------------------------------------------------------
void LinkList::add_node()
{

    node *temp;
    temp=new node;
    cout<<"Enter student name : ";
    cin>>temp->name;
    cout<<"Enter student PRN : ";
    cin>>temp->prn;
    temp->next=NULL;


    if(n==0)
    {
        p=temp;
        head=p;
    }
    else
    {
        p->next=temp;
        p=p->next;
    }

    n++;

}
//----------------------------------------------------------------------
void LinkList::display_LL()
{
    if(n==0)
        cout<<"No elements in Linked List."<<endl;
    else
    {
       	    cout<<"\n\nCLUB CONSIST OF MEMBERS:\n**************************************************";
	    p=head;
	    cout<<"\n\t\tPRESIDENT";
	    cout<<"\n\tName :"<<p->name;
	    cout<<"\tPRN no :"<<p->prn;
	    cout<<"\n\tMEMBERS";
	    p=p->next;
	 while(p->next!=NULL)
	    {
		cout<<"\n\tName :"<<p->name;
		cout<<"\tPRN no :"<<p->prn;
		p=p->next;
	    }
	    cout<<"\n\t\tSECRETARY";
	    cout<<"\n\tName :"<<p->name;
	    cout<<"\tPRN no :"<<p->prn;
	    cout<<"\n\n***************************************************\n";
    }
}
//----------------------------------------------------------------------
void LinkList::merge_LL(LinkList L1, LinkList L2)
{
    head=NULL;
    p=head;

    L1.p=L1.head;
    L2.p=L2.head;

    if(L1.p&&L2.p)
    {
        if(L1.p->prn<=L2.p->prn)
        {
            q=new node;
            q->name=L1.p->name;
            q->prn=L1.p->prn;
            L1.p=L1.p->next;
            n++;
        }
        else
        {
            q=new node;
            q->name=L2.p->name;
            q->prn=L2.p->prn;
            L2.p=L2.p->next;
            n++;
        }

        head=q;
        p=q;
        q=q->next;
    }

    while(L1.p&&L2.p)
    {
        if(L1.p->prn<=L2.p->prn)
        {
            q=new node;
            q->name=L1.p->name;
            q->prn=L1.p->prn;

            p->next=q;
            q=q->next;
            p=p->next;
            L1.p=L1.p->next;
            n++;
        }
        else
        {
            q=new node;
            q->name=L2.p->name;
            q->prn=L2.p->prn;

            p->next=q;
            q=q->next;
            p=p->next;
            L2.p=L2.p->next;
            n++;
        }
    }

    if(L1.p==NULL)
    {
        while(L2.p)
        {
            q=new node;
            q->name=L2.p->name;
            q->prn=L2.p->prn;

            p->next=q;
            q=q->next;
            p=p->next;
            L2.p=L2.p->next;
            n++;
        }
    }

    if(L2.p==NULL)
    {
        while(L1.p)
        {
            q=new node;
            q->name=L1.p->name;
            q->prn=L1.p->prn;

            p->next=q;
            q=q->next;
            p=p->next;
            L1.p=L1.p->next;
            n++;
        }
    }

}
//----------------------------------------------------------------------
void LinkList::delete_node()
{
    int flag=0;

    int d_prn;
    cout<<"Enter PRN of student whose entry is to be deleted : ";
    cin>>d_prn;

    q=head;
    while(q)
    {
        if(q->prn==d_prn)
        {
            flag=1;
        }
        q=q->next;
    }

    if(flag==0)
        cout<<"The entry does not exist!"<<endl;
    else
    {
        q=head;
        p=q->next;

        if(q->prn==d_prn)
        {
            head=p;
            delete(q);
        }
        else
        {
            while(p->prn!=d_prn)
            {
                p=p->next;
                q=q->next;

            }
            if(p->next==NULL)
            {
                q->next=NULL;
                delete(p);
            }
            else
            {
                q->next=p->next;
                delete(p);
            }
        }

    }


}
//----------------------------------------------------------------------
int LinkList::cal_members()
{
    int cnt=0;

    p=head;
    while(p)
    {
        cnt++;
        p=p->next;
    }

    return cnt;
}

//-----------------------------------------------------------------------
int main()
{
    int choice1,choice2;
    bool done1,done2;
    done1=false;

    int n1,n2;

    LinkList L1,L2,L3;

    do
    {
        cout<<"\n**** Welcome to Pinnacle Club ****"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"1. SE club."<<endl;
        cout<<"2. TE club. "<<endl;
        cout<<"3. Merge both clubs. "<<endl;
        cout<<"4. Exit."<<endl;

        cout<<"\nEnter your choice : ";
        cin>>choice1;

        switch(choice1)
        {
            case 1 :
                    done2=false;
                    cout<<"\n**** Welcome to SE club ****"<<endl;
                    cout<<"--------------------------------"<<endl;
                    cout<<"1. Add entry. "<<endl;
                    cout<<"2. Display all entries."<<endl;
                    cout<<"3. Delete an entry."<<endl;
                    cout<<"4. Display total number of members."<<endl;
                    cout<<"5. Go back."<<endl;

                    do{
                        cout<<"\nEnter operation for club-A : ";
                        cin>>choice2;
                        switch(choice2)
                        {
                            case 1 :    L1.add_node();
                                        break;
                            case 2 :    L1.display_LL();
                                        break;
                            case 3 :    L1.delete_node();
                                        break;
                            case 4 :    n1=L1.cal_members();
                                        cout<<"Total members in SE club are : "<<n1<<endl;
                                        break;
                            case 5 :    done2=true;
                                        break;
                        }
                    }while(done2==false);
                    break;

            case 2 :
                    done2=false;
                    cout<<"\n**** Welcome to TE club ****:"<<endl;
                    cout<<"--------------------------------"<<endl;
                    cout<<"1. Add entry. "<<endl;
                    cout<<"2. Display all entries."<<endl;
                    cout<<"3. Delete an entry."<<endl;
                    cout<<"4. Display total number of members."<<endl;
                    cout<<"5. Go back. "<<endl;

                    do{
                        cout<<"\nEnter operation for TE club: ";
                        cin>>choice2;
                        switch(choice2)
                        {
                            case 1 :    L2.add_node();
                                        break;
                            case 2 :    L2.display_LL();
                                        break;
                            case 3 :    L2.delete_node();
                                        break;
                            case 4 :    n2=L2.cal_members();
                                        cout<<"Total members in TE club are : "<<n2<<endl;
                                        break;
                            case 5 :    done2=true;
                                        break;
                        }
                    } 
			while(done2==false);
                    	break;

            case 3 :    L3.merge_LL(L1,L2);
                        L3.display_LL();
                        break;

            case 4 :
                    done1=true;
                    break;

        }
    }
	while(done1==false);


    return 0;
}
