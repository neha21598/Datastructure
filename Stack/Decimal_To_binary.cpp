
#include<iostream>
using namespace std;
int stack[100],tos=-1,e;

void push(int e)
{
	tos++;
	stack[tos]=e;
}

int pop()
{
	int temp;
	temp=stack[tos];
	tos--;
	return temp;
}


int main()
{
	int no,rem;
	cout<<"Enter a number";
	cin>>no;
	
	while(no!=0)
	{
	    rem=no%2;
		no=no/2;
		

		push(rem);
	}
 while(tos!=-1) 
 {
   e=pop();
	  
      cout << e;
   }


}