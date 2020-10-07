#include<iostream>
using namespace std;
char stack[100];
int tos=-1;

void push(char e)
{
    tos++;
    stack[tos]=e;
}

void pop()
{
    
    tos--;
    
}
int atTop()
{
	return stack[tos];
}

int main()
{
    char str[100];
    
    cout<<"Enter String";
    cin>>str;
    
    for(int i=0;str[i]!='\0';i++)
    {
        push(str[i]);
    }
    
     for(int i=0;str[i]!='\0';i++)
    {
        str[i]=atTop();
       pop();
       cout<<str[i];
    }

	 getchar();
}