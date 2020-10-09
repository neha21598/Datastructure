#include<iostream>
using namespace std;

int Q[100],Maxsize,front,rear,count=0;

void createQueue(int size)
{
    front=0;
    rear=-1;
    Maxsize=size;
}

int isFull()
{
    if(count==Maxsize)
    return 1;
    else
    return 0;
}

void Enqueue(int e)
{
    if(isFull())
    cout<<"Queue Full";
    
    else
    {
    rear++;
    Q[rear]=e;
    }
}

int isEmpty()
{
    if(front>rear)
    return 1;
    
    else
    return 0;
}

int DeQueue()
{
    int temp;
    
    if(isEmpty())
    cout<<"Queue is Empty";
    
    else
    {
        
        front++;
        temp=Q[front];
        return temp;
        
    }
}

void printQueue()
{
    int i;
    for(i=front;i<=rear;i++)
    cout<<Q[i];
}

int main()
{
    int size,ch,e;
    
    cout<<"Enter size:";
    cin>>size;
    
    createQueue(size);
    
    do{
        cout<<"\n1.Enqueue \n2.Dequeue \n3.print Queue \n0.Exit";
        
        cout<<"\n Enter Your choice:";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
            cout<<"Enter element:";
            cin>>e;
            
            Enqueue(e);
            break;
            
            case 2:
            DeQueue();
            break;
            
            case 3:
            printQueue();
            break;
            
            case 0:
            cout<<"Exit";
            break;
            
        }
    }while(ch!=0);
        
    }
    


