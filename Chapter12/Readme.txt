12-9, line152, 作用域的全新理解,还有就是运算符重载
代码风格堪称教科书级别

下面这两行代码不是很懂
Counter(const Counter&) = delete;
Counter& operator=(const Counter&) = delete;


=============================Partition===============================

而其余的项目中,都是在讨论virtual,其中所有错误的根源在下面这句代码:
Base *p = new Derived();	// 用子类实例化父类指针


