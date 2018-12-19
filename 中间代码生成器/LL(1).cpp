#include<stdlib.h>
#include<iostream>
#include<stack>

char locate[5][9] = {0};

using namespace std;
stack <char>syn;
stack <char>sem;
char w;
int t = 1;
int located(char x, char w);
void initial() {
	locate[0][0] = '1';
	locate[0][5] = '1';
	locate[1][1] = '2';
	locate[1][2] = '3';
	locate[1][6] = '4';
	locate[1][7] = '4';
	locate[2][0] = '5';
	locate[2][5] = '5';
	locate[3][1] = '8';
	locate[3][2] = '8';
	locate[3][3] = '6';
	locate[3][4] = '7';
	locate[3][6] = '8';
	locate[3][7] = '8';
	locate[4][0] = '9';
	locate[4][5] = '0';
}
void push(char x, char w)
{
	char l = located(x, w);
	switch (l) {
	case '1':
		syn.push('A');
		syn.push('T');
		break;
	case '2':
		syn.push('A');
		syn.push('+');
		syn.push('G');
		syn.push('T');
		syn.push('+');
		break;
	case '3':
		syn.push('A');
		syn.push('-');
		syn.push('G');
		syn.push('T');
		syn.push('-');
		break;
	case '4':
		break;
	case '5':
		syn.push('B');
		syn.push('F');
		break;
	case '6':
		syn.push('B');
		syn.push('*');
		syn.push('G');
		syn.push('F');
		syn.push('*');
		break;
	case '7':
		syn.push('B');
		syn.push('/');
		syn.push('G');
		syn.push('F');
		syn.push('/');
		break;
	case '8':
		break;
	case '9':
		syn.push(w);
		break;
	case '0':
		syn.push(')');
		syn.push('E');
		syn.push('(');
		break;
	}
}
int located(char x, char w)
{
	int i = 0,j=0;
	switch (x) {
	case 'E':i = 0;
		break;
	case 'A':i = 1;
		break;
	case 'T':i = 2;
		break;
	case 'B':i = 3;
		break;
	case 'F':i = 4;
		break;
	}
	switch (w)
	{
	case '+':
		j = 1; break;
	case '-':
		j = 2;
		break;
	case '*':
		j = 3;
		break;
	case '/':
		j = 4; break;
	case '(':
		j = 5;
		break;
	case ')':
		j = 6;
		break;
	case '#':
		j = 7;
		break;
	default:j = 0;
	}
	return locate[i][j];
}

int main()
{
	initial();
	syn.push('#');
	syn.push('E');
	cout << "输入表达式并以“#”号结束" << endl;
	r1:w = getchar();
	r2:char x=syn.top();
	syn.pop();
	if (x=='('||w==')') {
		if (x == w) {
			goto r1;
		}
	}
	if (x >= 'a'&&x <= 'z') {
		if (x == w) {
			sem.push(x);
			goto r1;
		}
		else {
			cout << "wrong" << endl;
		}
	}
	else
	{
		if (x == 'E' || x == 'A' || x == 'T' || x == 'B' || x == 'F')
		{
			push(x, w);
			goto r2;
		}
		else
			if (x == '+' || x == '-' || x == '*' || x == '/')
			{
				goto r1;
			}
			else
				if (x == 'G') {
					char p = syn.top();
					syn.pop();
					char a = sem.top();
					sem.pop();
					char b = sem.top();
					sem.pop();
					if (a == 't'||b=='t') {
						char c = sem.top();
						sem.pop();
						if(a == 't')
							cout << "(" << p << "," << c << "," << a << (int)b << ",t" << t << ")" << endl;
						else
							cout << "(" << p <<  "," << b << (int)c <<"," << a << ",t" << t << ")" << endl;
					}
					else {
						cout << "(" << p << "," << b << "," << a << ",t" << t << ")" << endl;
					}


					sem.push((char)t);
					t++;
					sem.push('t');
					goto r2;
				}
				else
				{
					if (x == '#')
					{
						cout << "nice" << endl;
					}
					else
					{
						cout << "wrong" << endl;
					}
				}
	}
	system("pause");
	return 0;
}