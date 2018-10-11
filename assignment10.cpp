/*A double-ended queue(deque) is a linear list in which additions and deletions may be made at
either end. Obtain a data representation mapping a deque into a one-dimensional array.
Write C++ program to simulate deque with functions to add and delete elements from either end of
the deque.*/

#include<iostream>
using namespace std;
#define SIZE 10

class Deque
{
    struct dque
    {
        int Darr[SIZE];
        int Front,Rear;
    }dq;


public:
    Deque(){dq.Front=-1;dq.Rear=-1;}
    int accept();
    void display();
    int isempty();
    int isfull();
    void insert_front();
    void insert_back();
    void delete_front();
    void delete_back();
};
//-------------------------------------

void Deque::display()
{

    if(isempty())
    {
        cout<<"Empty Deque"<<endl;
    }

    else if(dq.Front==0 && dq.Rear==0)
        cout<<dq.Darr[dq.Front]<<endl;

    else
    {
        for(int i=dq.Front; i<=dq.Rear; i++)
            cout<<dq.Darr[i]<<" ";
    }

}

//-------------------------------------------

int Deque::accept()
{
    int element;
    cout<<"Enter element to be inserted : ";
    cin>>element;

    return element;
}
//-------------------------------------------

int Deque::isempty()
{
    if(dq.Front==-1 && dq.Rear==-1)
        return 1;
    else
        return 0;
}
//--------------------------------------

int Deque::isfull()
{
    if(dq.Front==0 && dq.Rear==SIZE)
        return 1;
    else
        return 0;
}
//---------------------------------------

void Deque::insert_front()
{
    int element;

    if(isempty())
    {
        element=accept();
        dq.Front++;
        dq.Rear++;
        dq.Darr[dq.Front]=element;
    }

    else if(dq.Front==0)
        cout<<"Cannot insert at Front."<<endl;

    else if(!isfull())
    {
        element=accept();
        dq.Front--;
        dq.Darr[dq.Front]=element;
    }

    else
        cout<<"Cannot insert at Front. Front position occupied."<<endl;
}

//----------------------------------------------

void Deque::insert_back()
{
    int element;

    if(isempty())
    {
        element=accept();
        dq.Front++;
        dq.Rear++;
        dq.Darr[dq.Front]=element;
    }

    else if(!isfull())
    {
        element=accept();
        dq.Rear++;
        dq.Darr[dq.Rear]=element;
    }

    else
        cout<<"Cannot insert at Rear. Deque Full";

}

//-------------------------------------------------------

void Deque::delete_front()
{
    if(isempty())
        cout<<"Empty Deque. Please insert an element."<<endl;

    else if(dq.Front==dq.Rear)
    {
        dq.Darr[dq.Front]=0;
        dq.Front=-1;
        dq.Rear=-1;
        cout<<"Element deleted."<<endl;
    }

    else
    {
        dq.Darr[dq.Front]=0;
        dq.Front++;
        cout<<"Element deleted."<<endl;
    }

}

//---------------------------------------------------------

void Deque::delete_back()
{

    if(isempty())
        cout<<"Empty Deque. Please insert an element."<<endl;

    else if(dq.Front==dq.Rear)
    {
        dq.Darr[dq.Front]=0;
        dq.Front=-1;
        dq.Rear=-1;
        cout<<"Element deleted."<<endl;
    }

    else
    {
        dq.Darr[dq.Rear]=0;
        dq.Rear--;
        cout<<"Element deleted."<<endl;
    }





}


//-------------------------------------------------------

int main()
{
    Deque D_obj;
    int choice;

    cout<<"Welcome"<<endl;
    cout<<"1. Insert from Front."<<endl;
    cout<<"2. Insert from Back."<<endl;
    cout<<"3. Delete from Front."<<endl;
    cout<<"4. Delete from Back."<<endl;
    cout<<"5. Display Deque."<<endl;
    cout<<"6. Exit."<<endl;


    do{
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1 :    D_obj.insert_front();
                        break;

            case 2 :    D_obj.insert_back();
                        break;

            case 3 :    D_obj.delete_front();
                        break;

            case 4 :    D_obj.delete_back();
                        break;

            case 5 :    D_obj.display();
                        break;

        }

    }while(choice!=6);

    cout<<"\nThank You.";

return 0;
}
