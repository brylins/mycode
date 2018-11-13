#include<cstring>
#include<string>
#include<iostream>

class Explicit
{
    private:

    public:
        explicit Explicit(int size)
        {
            std::cout << " the size is " << size << std::endl;
        }
        explicit  Explicit(const char* str)
        {
            std::string _str = str;
            std::cout << " the str is " << _str << std::endl;
        }

        Explicit(const Explicit& ins)
        {
            std::cout << " The Explicit is ins" << std::endl;
        }

        Explicit(int a,int b)
        {
            std::cout << " the a is " << a  << " the b is " << b << std::endl;
        }
};

int main()
{
    Explicit test0(15);
    Explicit test1 = 10;	// 隐式调用Explicit(int size),加上explicit之后就不能隐式调用了

    Explicit test2("RIGHTRIGHT");
    Explicit test3 = "BUGBUGBUG";	// 隐式调用Explicit(const char* str)，加上explicit之后就不能隐式调用了

    Explicit test4(1, 10);
    Explicit test5 = test1;
}
