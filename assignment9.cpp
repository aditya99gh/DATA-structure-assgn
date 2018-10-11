#include<iostream>
#include<string>
#define MAX 30
using namespace std;

template<class T>
class Conversion
{
    char infix[30],postfix[30];
    T stack[MAX];
    int top,i,j;

public:
        Conversion()
        {
            top=-1;
            i=j=0;
        }
        void getexp();
        int isstackempty();
        int isstackfull();
        void push(T A);
        T pop();
        T gettop();
        void display();
       // void check();
        void intopost();
        void evaluation();
        int priority(char x);

};
template<class T>
void Conversion<T>::getexp()
{
    cout<<"\nEnter the expression for conversion : \n";
    cin>>infix;
    cout<<"\nThe entered expression is : "<<infix<<"\n";

}

template<class T>
int Conversion<T>::isstackempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

template<class T>
int Conversion<T>::isstackfull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

template<class T>
void Conversion<T>::push(T A)
{
    if(!isstackfull())
    {
        top++;
        stack[top]=A;
    }
    else
        cout<<"\nStack OVERFLOW!!!\n";
}

template<class T>
T Conversion<T>::pop()
{
    T temp;
    if(!isstackempty())
    {
        temp=stack[top];
        top--;
    }
    else
        cout<<"\nStack is Empty.\n";
    return temp;
}

template<class T>
void Conversion<T>::display()
{
    if(!isstackempty())
    {
    cout<<"\nThe stack content is as follows : \n";
    for(int i=0;i<=top;i++)
    cout<<stack[i]<<" ";
    }
    else
        cout<<"\nStack is Empty.\n";
}

template<class T>
T Conversion<T>::gettop()
{
    if(!isstackempty())
        return stack[top];
    else
    {
        cout<<"\nStack is Empty.\n";
        return '0';
    }
}

template<class T>
void Conversion<T>::intopost()
{
    char token,x;
    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
         if( (token=='(') )
             push(token);
         else  if( (token==')'))
         {
             while((x=pop())!='(')
            {
                postfix[j]=x;
                j++;
            }
         }
         else if((token=='+')||(token=='-')||(token=='*')||(token=='/')||(token=='%')||(token=='^'))
         {
             while(priority(stack[top])>=priority(token))
             {
                 x=pop();
                 postfix[j]=x;
                 j++;
             }
             push(token);
         }
         else
         {
             postfix[j]=token;
             j++;
         }
    }
    while(top!=-1)
    {
        x=pop();
        postfix[j]=x;
        j++;
    }
    postfix[j]='\0';
    cout<<"\n"<<postfix;

}

template<class T>
int Conversion<T>::priority(char x)
{
    if(x=='(')
        return 0;
    else if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='%'||x=='/')
        return 2;
    else if(x=='^')
        return 3;
}

int main()
{
    Conversion<char> convert;
    Conversion<int> evaluate;

    convert.getexp();
    convert.intopost();

    return 0;
}
