#include<iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include<map>
#include<string>
#include<list>
#include<array>

void map()
{
    //map就是两种不同的数据类型产生一一对应关系
    std::cout << "*****map*****" << std::endl;
    std::map<int, std::string> Id_Name = 
    {
        { 2015, "Jim" },
        { 2016, "Tom" },
        { 2017, "Bob" }
    };
    
    for(std::map<int, std::string>::iterator it = Id_Name.begin(); it != Id_Name.end(); ++it)
    {
        std::cout << (*it).first << "\t" << it->second << std::endl;
    }
}
 
void vector()
{
    //vector是不定长数组，可以一直扩展
    std::cout << "*****vecotr*****" << std::endl;
    std::vector<int> v = {7, 5, 16, 8};
 
    v.push_back(25);
    v.push_back(13);
 
    for(int n : v)  //元素：数组名
    {
        std::cout << n << std::endl;
    }
}

void list()
{
    //双向链表实现的list，也是不定长的
    std::cout << "*****list*****" << std::endl;
    std::list<int> l = { 7, 5, 16, 8 };
  
    l.push_front(25);   //前面插入
    l.push_back(13);    //后面插入
 
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end()) 
    {
        l.insert(it, 42);
    }
 
    // 迭代并打印 list 的值
    for (int n : l) //元素：数组名
    {
        std::cout << n << std::endl;
    }
}

void array()
{
    //array就是定长数组,需要指定长度
    std::cout << "*****array*****" << std::endl;
    std::array<int, 3> a1{ {1, 2, 3} }; //C++11中要求双花括号,C++14中不要求,此时没有等于号
    std::array<int, 3> a2 = {1, 2, 3};  //决不要求在=后, 此时有等于号
    std::array<std::string, 2> a3 = { std::string("a"), "b" };
 
    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, "-"));    //数组逆序，并且以-为间隔输出到std::cout中
 
    std::cout << std::endl;
 
    for(const auto& s: a3)  //直接使用auto关键字自动推断类型引用：数组名
    {
        std::cout << s << ' ';
    }   
}


int main()
{
    vector();
    map();
    list();
    array();
}

