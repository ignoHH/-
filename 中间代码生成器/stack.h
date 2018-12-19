//#include <iostream>
//#include <string>
//using namespace std;
//
//#define DEFAULT_SIZE 100
//
//class stack						//栈类定义
//{
//private:
//	int top;
//	string *stacka;
//	int maxsize;
//public:
//	stack(int size = DEFAULT_SIZE);
//	~stack() { delete[] stacka; }
//	void push(const string &item);
//	string pop(void);
//	string gettop(void) const;
//	bool empty(void) const { return (top == -1); }
//	bool full(void) const { return (top == maxsize - 1); }
//	void clear(void) { top = -1; }
//};
//
//stack::stack(int size)		     //栈类的构造函数
//{
//	top = -1;
//	maxsize = size;
//	stacka = new string[maxsize];
//	if (!stacka)
//	{
//		cerr << "allocate memory failed." << endl;
//		exit(1);
//	}
//};
//
//void stack::push(const string &item)        //压栈操作
//{
//	if (full())
//	{
//		cerr << "stack full, cannot push." << endl;
//		return;
//	}
//	top++;
//	stacka[top] = item;
//};
//
//string stack::pop(void)				        //出栈操作
//{
//	if (empty())
//	{
//		cerr << "stack empty, cannot pop." << endl;
//		exit(1);
//	}
//	string item = stacka[top];
//	top--;
//	return item;
//};
//
//string stack::gettop(void) const	         //取栈顶操作
//{
//	if (empty())
//	{
//		cerr << "stack empty, cannot gettop." << endl;
//		exit(1);
//	}
//	return stacka[top];
//};
//
