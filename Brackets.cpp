#include<iostream>
using namespace std;

char stack[100],tos=-1;

//Push  the elements

void push(char e)
{
	tos++;
	stack[tos]=e;
}

//Decrement top of stack

void pop()
{
	tos--;
}

int main()
{
	string expr="{()}[]";

	for(int i=0;i<expr.length();i++)
	{
		
		if(expr[i]=='(' || expr[i]=='[' || expr[i]=='{')
		{
			//push the open brackets untill closing bracket comes

			push(expr[i]);
			continue;
		}

		
		else if(expr[i]==')' || expr[i]==']' || expr[i]=='}')
		{
			//check for "(" closing bracket

			if(expr[i]==')')
			{
				if(stack[tos]=='(')
				{
					pop();
				}
				else
				{
					cout<<"UNBALANCED EXPRESSION";
					break;
				}
			}


			//check for "{" closing bracket

			if(expr[i]=='}')
			{
				if(stack[tos]=='{')
				{
					pop();
				}
				else
				{
					cout<<"UNBALANCED EXPRESSION";
					break;
				}
			}
			
			//check for "[" closing bracket

			if(expr[i]==']')
			{
				if(stack[tos]=='[')
				{
					pop();
				}
				else
				{
					cout<<"UNBALANCED EXPRESSION";
					break;
				}
			}
		}

	}

//If stack  is empty Then Balanced expression

	if(tos==-1)
	{
	cout<<"BALANCED EXPRESSION";
	}

	getchar();
}
