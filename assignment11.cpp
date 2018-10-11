#include <iostream>
using namespace std;
#define MAX 10

class Pizza
{
    int order[10];
    int front,rear;
public:
    Pizza()
{
        front=rear=-1;
}
    bool place_order(int order_id);
    void serve_order();
    void order_queue();
};

bool Pizza::place_order(int order_id)
{
    if(rear==-1)
    {
        front=rear=0;
        order[rear]=order_id;
        return true;
    }
    else
    {
        int position=(rear+1)%MAX;
        if(position==front)
        {
            cout<<"\n The Parlor is full!";
            return false;
        }
        else
        {
            rear=position;
            order[rear]=order_id;
            return true;
        }
    }
}

void Pizza::serve_order()
{
    if(front==-1)
    {
        cout<<"\n No orders placed!";
        return;
    }
    else
    {
        cout<<"\nOrder ID"<<order[front]<<"is ready! Enjoy your Pizza!";
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
    }
}

void Pizza::order_queue()
{
    if(front==-1)
    {
        cout<<"\nNo orders placed!";
    }
    else
    {
            cout<<"\nOrders are:";
            for(int i=0;i!=rear;i=((i+1)%MAX))
            {
                cout<<order[i]<<" ";
            }
            cout<<order[rear];
    }
}
int main() {
    int choice,order_id=0;
    cout<<"\nPizza Barn\n";
    cout<<"----------------------------------------------------------------";
    while(choice!=4)
    {
        cout<<"\n1.Place Order";
        cout<<"\n2.Serve Order";
        cout<<"\n3.Order Queue Display";
        cout<<"\n4.EXIT";
        cout<<"\nEnter Choice:";
        cin>>choice;
        Pizza obj;

        switch(choice)
        {
        case 1:
            order_id++;
            if(obj.place_order(order_id))
            {
                cout<<"\nOrder Place!Order ID: "<<order_id;
                cout<<"\n----------------------------------------------------------------";
            }
            else
            {
                order_id--;
            }
            break;

        case 2:
            obj.serve_order();
            break;

        case 3:
            obj.order_queue();
            break;
        }
    };
    cout<<"\nThanking for placing the order! Visit again!";
        return 0;
    }
