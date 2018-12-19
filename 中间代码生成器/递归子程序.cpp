//#include <iostream>
//#include <string>
//#include "stack.h"
//
//using namespace std;
//
//static stack syn;
//
//char E(char w);
//char F(char w);
//char T(char w);
//void S();
//int t = 1;
//bool AllisNum(string str)
//{
//	for (int i = 0; i < str.size(); i++)
//	{
//		int tmp = (int)str[i];
//		if (tmp >= 48 && tmp <= 57)
//		{
//			continue;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	return true;
//}
//char F(char w) 
//{
//	string word;
//	if (w >= 'a'&&w <= 'z' || w >= 'A'&&w <= 'Z'||w>='0'&&w<='9') {
//		word = w;
//		syn.push(word);
//	}
//	else
//		if (w == '(') {	
//			cin >> w;
//			w = E(w);
//		}
//	cin >> w;
//	return w;
//}
//
//char E(char w) 
//{
//	string operate, a, b, c;
//	w = T(w);
//	while (w == '+' || w == '-') {			//是加或减符号
//		operate = w;
//		char op = w;
//		cin >> w;//读取下一个字符
//		w = T(w);
//		b = syn.pop();
//		a = syn.pop();
//		if (AllisNum(a)&& AllisNum(b))
//		{
//			if (op == '+') {
//				cout << "(" << operate << "," << a << "," << b << "," << atoi(a.c_str()) + atoi(b.c_str()) << ")" << endl;
//				syn.push(to_string(atoi(a.c_str()) + atoi(b.c_str())));
//			}
//			else {
//				cout << "(" << operate << "," << a << "," << b << "," << atoi(a.c_str()) - atoi(b.c_str()) << ")" << endl;
//				syn.push(to_string(atoi(a.c_str()) - atoi(b.c_str())));
//			}
//		
//		}
//		else {
//			cout << "(" << operate << "," << a << "," << b << ",t" << t << ")" << endl;
//			c = "t" + to_string(t);//t加尾标
//			syn.push(c);//将四元式结果压栈作为下一个四元式的变量
//		}
//	
//		t++;
//	}
//	return w;
//}
//
//char T(char w) 
//{
//	string operate, a, b, c;
//	w = F(w);
//	while (w == '*' || w == '/') {
//		char op = w;
//		operate = w;
//		cin >> w;
//		w = F(w);
//		b = syn.pop();
//		a = syn.pop();
//		if (AllisNum(a) && AllisNum(b)) 
//		{
//			if (op == '*')
//			{
//				cout << "(" << operate << "," << a << "," << b << ","<< atoi(a.c_str()) * atoi(b.c_str()) << ")" << endl;
//				syn.push(to_string(atoi(a.c_str()) * atoi(b.c_str())));
//			}
//			else {
//				cout << "(" << operate << "," << a << "," << b << "," << atoi(a.c_str()) / atoi(b.c_str()) << ")" << endl;
//				syn.push(to_string(atoi(a.c_str()) / atoi(b.c_str())));
//			}
//		}
//		else {
//			cout << "(" << operate << "," << a << "," << b << ",t" << t << ")" << endl;
//			c = "t" + to_string(t);
//			syn.push(c);
//		}
//		t++;
//	}
//	return w;
//}
//
//void S() 
//{
//	char w;
//	cin >> w;
//	w = E(w);
//	if (w == '#') {		                
//		cout << "nice" << endl;
//	}
//}
//
//void main()
//{
//	cout << "输入表达式并以“#”号结束" << endl;
//	S();
//	system("pause");
//}
