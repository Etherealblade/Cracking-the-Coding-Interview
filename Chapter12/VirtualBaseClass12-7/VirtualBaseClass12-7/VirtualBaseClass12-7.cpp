
#include <iostream>
using namespace std;

class Foo
{
public:
	virtual void f();		// including "virtual" or not
};

class Bar :public Foo
{
public:
	void f();
};

void Foo::f()
{
	cout << "f of Foo is called" << endl;
}

void Bar::f()
{
	cout << "f of Bar is called" << endl;
}

int main()
{
	Foo *p = new Bar();	// 写出这种代码的人应该拿去枪毙
						// 代码自动补全只给出"new Foo"
						// 用子类实例化父类是万恶之源
	p->f();

	return 0;
}
