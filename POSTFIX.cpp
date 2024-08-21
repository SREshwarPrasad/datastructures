//INFIX TO POSTFIX

#include<iostream>
#include<string.h>
#define max 100
using namespace std; 
char str[max], stk[max], post[max];
int n, top=-1;
int precedence(char c)
{	
	int p;
	switch(c)
	{
		case '^': p=5; break;
		case '/':
		case '*': p=4; break;
		case '-':
		case '+': p=3; break;
		case '(': p=2; break;
	}
	return p;
}
void push(char a)
{
	top+=1;
	stk[top]=a;
}
int empty()
{
	return (top==-1)?1:0;
}
char pop()
{
	char s=stk[top];
	top-=1;
	return s;
}
int main()
{
	int j=0;
	char t,x;
	cout<<"Enter string: ";
	cin>>str;
	for(int i=0; str[i]!='\0';i++)
	{
		if(isalpha(str[i]) || isdigit(str[i]))
		{
			post[j]=str[i];
			j+=1;
		}
		else if (str[i]==')')
		{
			while (stk[top]!='(')
			{
				t=pop();
				post[j]=t;
				j+=1;
			}
			x=pop();
		}
		else if (precedence(stk[top])<precedence(str[i]) || empty() || (str[i]=='('))
			{
				cout<<str[i]<<"pushed \n";
				push(str[i]);
			}
		else 
		{
			while ( precedence(stk[top])>=precedence(str[i]) && !empty()) 
			{
				t=pop();
				post[j]=t;
				j+=1;
			}
			push(str[i]);
		}
	}
	while (!empty())
	{	
		t=pop();
		post[j]=t;
		j+=1;
	}
	post[j]='\0';
	cout<<"Postfix expression : "<<post;
	return 0;
}
