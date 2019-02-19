#include <iostream>

void function0() 
{
	//传值捕获的是lambda表达式"定义"之前的变量的值
	//引用捕获的是lambda表达式"执行"之前的变量的值

	int a = 1;
	int b = 1;
	int c = 1;

	a = 2;
	b = 2;
	c = 2;
	
	auto func0 = [a, &b, &c]{std::cout << "a=" << a << " b="<< b << " c=" << c << std::endl;};
	
	a = 3;
	b = 3;
	c = 3;

	func0();
	//打印结果：a=2 b=3 c=3
}

void function1()
{
	//语法定义
	int m = 0;
	int n = 0;

	auto func0 = [&]{std::cout << "no argument" << std::endl;};
	auto func1 = [&](int x){std::cout << x << std::endl;};
	auto func2 = [=](int x)->int{return m * n * x;}; 
	auto func3 = [=]()mutable->int{ m = 1; n =1;};
	auto func4 = [=]()constexpr->int{ int tmp = 3; return tmp;};
	auto func5 = [=]()throw()->int{ int tmp = 3; return tmp;};

}

void function2()
{
	//mutable关键字
	//可以修改按值传递的变量，但是只在lambda表达式内部有效
	int m = 0;
	int n = 0;

	[m, n](){std::cout << "lambda 1:" << m << n << std::endl;}();
	//[m, n](){ m = 1; n =1;std::cout << "lambda internal:" << m << n << std::endl;}();		//编译报错，试图修改按值传递的变量
	[m, n]()mutable{ m = 1; n = 1; std::cout << "lambda 2:" << m << n << std::endl;}();
	
	std::cout << "function2:" << m << n << std::endl;
	//终端输出：
	//lambda 1:00
	//lambda 2:11
	//function2:00	

}

void function3()
{
	//constexpr关键字
	//普通变量可以接受constexpr变量或者普通变量的赋值
	//constexpr变量只可以接受constexpr变量的赋值
	//参数必须都是constexpr变量才能保证lambda表达式返回的是constexpr值

	int a = 10;
	constexpr int b = 10;
	constexpr int c = 10;
	auto lambda0 = [](int m, int n) {return m + n;};
    auto lambda1 = [](int m, int n) constexpr {return m + n;};	

              int ret0 = lambda0(1, 2);		
	constexpr int ret1 = lambda0(1, 2);		

	          int ret2 = lambda0(a, b);
	//constexpr int ret3 = lambda0(a, b);	//a不是constexpr变量，导致lambda0的返回值不是constexpr类型，所以不能赋值给constexpr变量ret3
	constexpr int ret4 = lambda0(b, c);
}

int main()
{
	function0();
	function1();
	function2();
	function3();
};

