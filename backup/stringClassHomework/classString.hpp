#pragma once
#include <iostream>
#include <string.h>
#include <assert.h>

//using namespace std;
//#define PRINT_SWITCH 

class String
{	
public:
	
	String() = delete;
	
    String(const char* str = ""):_len(strlen(str)), _capacity(_len + 1)
    {
        _str = (char*)malloc(_len + 1);
        strcpy(_str, str);
		
		#ifdef PRINT_SWITCH
		std::cout << "initialize constructor" << std::endl;
		#endif
    }
	
    String(const String& s):_len(s._len), _capacity(s._capacity)
    {
        _str = (char*)malloc(s._capacity + 1);
        strcpy(_str, s._str);
		
		#ifdef PRINT_SWITCH
		std::cout << "copy constructor" << std::endl;		
		#endif
    }
	
	String( String&& s):_len(s._len), _capacity(s._capacity)
    {
		this->_str = s._str;
		s._str = nullptr;
		s._len = 0;
		s._capacity = 0;
		#ifdef PRINT_SWITCH
        std::cout << "move constructor" << std::endl;
		#endif
    }
	
	const String& operator = (const String& s);
	const String& operator = (String&& s);
	
	~String()
    {
        free(_str);
		#ifdef PRINT_SWITCH
		std::cout << "destructor" << std::endl;
		#endif
    }

	void setStr(char* str);
    char* getStr()const;
    int getLength()const;
	void setLength(int len);
    int getCapacity();
	void setCapacity(int capacity);

	int compare(const char* str);
	int compare(const String& s);
	
	void Swap(String& s);
    void PushBack(char ch);
    void append(const char* str);
    void PopBack();
	int Find(char ch) const;
    int Find(const char* str) const;
	
    void Insert(int pos, char ch);
    void Insert(int pos, const char* str);
    void Erase(int pos, int count);
	
	//bool operator==(const String& s);		//成员函数重载和友元函数重载有什么不同？
	
private:
    char* _str;
    int _len;
    int _capacity;
	
	friend std::ostream& operator<<(std::ostream& out, const String& s);
	friend std::istream& operator>>(std::istream& in, const String& s);
	friend String& operator+(const String str1, const String str2);
	friend bool operator==(const String& str1, const String& str2);

};
