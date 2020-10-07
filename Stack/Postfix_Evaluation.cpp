#include <iostream>
#include <stack>
using namespace std;

char s[100];
int MaxSize, tos;

void initStack(int size)
{
    MaxSize = size;
}


void push(char e) 
{
    tos++;
    s[tos] = e;
}

char pop() 
{
    char temp = s[tos];
    tos--;
    return temp;
}

char atTop() 
{
    return s[tos];
}



// Function to evaluate given postfix expression
int postfixEval(string exp)
{
	

	for (int i = 0; i < exp.length(); i++)
	{

		if (exp[i] >= '0' && exp[i] <= '9') {
			push(exp[i] - '0');
		}
		// if current char is an operator
		else
		{
			// pop top two elements from the stack
			int first = atTop();
			pop();

			int second = atTop();
			pop();

			// evaluate the expression x op y, and push the
			// result back to the stack
			if (exp[i] == '+')
				push(second + first);

			else if (exp[i] == '-')
				push(second - first);

			else if (exp[i] == '*')
				push(second * first);

			else if (exp[i] == '/')
				push(second / first);
		}
	}
//expression result
	return atTop();
}

int main()
{
	string exp = "138*+";

	cout <<"Result is:" <<postfixEval(exp);

	return 0;
}