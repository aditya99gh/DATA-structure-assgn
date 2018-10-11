#include<iostream>
#include<string>
#define MAX 30
using namespace std;

class stack_app
{
    char stack_exp[MAX],exp[50];
    int top;
public:
    stack_app()
    {
        top=-1;
    }
    void getexp();
    int isstackempty();
    int isstackfull();
    void push(char A);
    void pop();
    char gettop();
    void display();
    void check();
};

void stack_app::getexp()
{
    cout<<"\nEnter the expression to check for its validity .\n";
    cin>>exp;
    cout<<"\nThe entered expression is : "<<exp<<"\n";

}
int stack_app::isstackempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int stack_app::isstackfull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

void stack_app::push(char A)
{
    if(!isstackfull())
    {
        top++;
        stack_exp[top]=A;
    }
    else
        cout<<"\nStack OVERFLOW!!!\n";
}

void stack_app::pop()
{
    if(!isstackempty())
    {
        char temp;
        temp=stack_exp[top];
        top--;
    }
    else
        cout<<"\nStack is Empty.\n";
}

void stack_app::display()
{
    if(!isstackempty())
    {
    cout<<"\nThe stack content is as follows : \n";
    for(int i=0;i<=top;i++)
    cout<<stack_exp[i]<<" ";
    }
    else
        cout<<"\nStack is empty.\n";
}

char stack_app::gettop()
{
    if(!isstackempty())
        return stack_exp[top];
    else
    {
        cout<<"\nStack is empty.\n";
        return '0';
    }
}

void stack_app::check()
{
    int flag;
    char x,token;
    for(int i = 0; exp[i]!='\0' ; i++)
    {
        token = exp[i];
        if( (token=='(') || (token=='{') || (token=='[') )
            push(token);

        if( (token==')') || (token=='}') || (token==']') )
        {
            if(!isstackempty())
            {
                x=gettop();
                if( (x=='(' && token==')') || (x=='{' && token=='}') || (x=='[' && token==']') )
                {
            pop();
            flag=1;
                }
                else
                {
            flag=0;
                    cout<<"\nMISMATCH FOUND!!!\n";
                    break;
                }
            }
            else
            {
        flag=0;
                cout<<"\n\nIRREGULARITY IN NUMBER OF OPENING OR CLOSING BRACKETS.\n";
                break;
            }
        }
    }
    if(flag!=0)
    {
    if(isstackempty())
        flag=1;
    else
    flag=0;
    }
    if(flag==0)
    cout<<"\nThus, the expression is unbalanced.";
    else
    cout<<"\nThe expression is balanced.\n";


}


int main()
{
       char ch,fi;
    int d;
    bool c=0;
    stack_app A;
    do
    {
        cout<<"\n~~~~~~~~~~~~~~~~  MENU  ~~~~~~~~~~~~~~~~\nEnter\n'1' - To enter the expression.\n'2' - To display the contents of the stack.\n'3' - To check whether the stack is empty or not.\n'4' - To check whether the stack is full or not.\n'5' - To enter an element into the stack.\n'6' - To remove an element from the stack.\n'7' - To view the first element of the stack.\n'8' - To check the validity of the expression.\n'e' - Exit.\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cin>>ch;

        switch(ch)
        {
        case '1':
            A.getexp();
               break;
        case '2':
            A.display();
            break;
        case '3':
            d=A.isstackempty();
            if(d==1)
                cout<<"\nThe stack is empty.\n";
            else
                cout<<"\nThe stack is not empty.\n";
            break;
        case '4':
            d=A.isstackfull();
            if(d==1)
                cout<<"\nThe stack is full.\n";
            else
                cout<<"\nThe stack is not full.\n";
            break;
        case '5':
            cout<<"\nEnter the element : ";
            cin>>ch;
            A.push(ch);
            break;
        case '6':
            A.pop();
            break;
        case '7':
            A.gettop();
            break;
        case '8':
            A.check();
            break;
        case 'e':
            c=1;
            break;
        default :
            cout<<"\nINVALID ENTRY OF OPERATION.\n";
        }
    }while(c==0);

    cout<<"\n**************  FINISH  **************\n";
    return 0;
}
