#include <iostream>
#include<string.h>
#include<conio.h>
using namespace std;

int stack[100];
int tos = -1;
char postfix[100],e;
int z;

//push the elements 

void push(char e)
{
	tos++;
	stack[tos] = e;
}

char pop()
{
	char temp;
	temp = stack[tos];
	tos--;
	return temp;
}
int atTop()
{
	return stack[tos];
}
int priority(char op)
{
	switch(op)
	{
	case '+':case'-':
		return 1;
		break;

	case '*':case '/':case '%':
		return 2;
		break;

	case '^':
		return 3;
		break;

	case '(':
		return 0;
		break;
	}
}

int main()
{
	int pr1,pr2;
	
	char infix[100];
	
	cout<<"enter the infix expression \n";
	cin>>infix;
	
	for(int i=0;infix[i]!='\0';i++)
	{
        
        //if operand,then push onto stack directly
        
		if((infix[i]>='a' && infix[i]<='z')||(infix[i]>='A' && infix[i]<='Z'))
		{
				postfix[z] = infix[i];
			    z++;
			
		}
		
		//If operator
		
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='%' || infix[i]=='^' || infix[i]=='(' || infix[i]==')' )
		{
		    
		    //If stack is empty,then push the operator 
		    
			if(tos == -1)
			{
				push(infix[i]);
			}
			
			else
			{
				pr1 = priority(atTop());
				pr2 = priority(infix[i]);

                //if '(' ,then push on stack
                
				if(infix[i]=='(')
				{
					push(infix[i]);
				}
				
				//if ')' then pop the elements till '(' comes
				
				else if(infix[i]==')')
				{
				    
					while(tos!=-1)
					{
						char temp = pop();
						if(temp!='(')
						{
						   postfix[z] = temp;
					    	z++;
						}
					}
				}
				
				//if instack operator priority is < upcoming operator priority
				
				else if(pr2<=pr1)
				{
					while(tos!=-1)
					{
						postfix[z] = pop();
						z++;
					}
					push(infix[i]);
				}
				else
				{
					push(infix[i]);
				}
				

			}
		}
	}
	while(tos!=-1)
	{
		postfix[z] = pop();
			z++;
	}
	//Print the postfix expression
	cout<<"Postfix Expression is:";
	for(int i=0;postfix[i]!='\0';i++)
	{
		cout<<postfix[i];
	}
	getch();
return 0;
}

/* output 
enter the infix expression
(a+b)/(c*d)
Postfix Expression is:ab+cd*/
       

*/                 			