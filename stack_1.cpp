#include<iostream>
using namespace std;

int Maxsize,e,tos,s[100];

void initStack(int size)
{
	Maxsize=size;
	tos=-1;
}

void push(int e)
{
	tos++;
	s[tos]=e;
}

int isFull()
{
	if(tos==Maxsize-1)
	return 1;
	else
	return 0;
}

int pop()
{
	int temp;
	temp=s[tos];
	tos--;
	return temp;
}

int isEmpty()
{
	if(tos==-1)
	return 1;

	else
		return  0;
}

void printStack()
{
	cout<<"\n Elements in stack are:";
	for(int i=tos;i>=0;i--)
	cout<<s[i];
}

int atTop()
{
	return s[tos];
}

int main()
{
	int size,ch;

	cout<<"\n Enter size:";
	cin>>size;

	initStack(size);

	do
	{
		cout<<"\n 1.push \n 2.pop \n 3.atTop \n 4.Print \n 0.Exit\n ";
		
		cout<<"\nEnter your choice:";
		cin>>ch;

		switch(ch)
		{
		case 1:
			if(isFull()==1)
			cout<<"\nStack is Full";

			else
			{
				cout<<"\nEnter Element";
				cin>>e;

				push(e);
			}

			break;
		
		case 2:
			if(isEmpty()==1)
				cout<<"\n Stack is Empty";

			else
			{
				e=pop();
				cout<<"\n Popped Element is:"<<e;
			}

			break;

		case 3:
			if(isEmpty()==1)
				cout<<"\n Stack is Empty";
			else
			{
				e=atTop();
				cout<<"\n Top element is:"<<e;
			}

			break;

		case 4:
			if(isEmpty()==1)
				cout<<"\n Stack is Empty";
			else
			{
				printStack();
			}

			break;

		case 0:
			cout<<"\n ERROR";
			break;


		default:cout<<"\n Invalid Choice";
			break;

		}

	}while(ch!=0);
}
