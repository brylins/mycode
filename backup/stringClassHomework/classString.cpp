#include "classString.hpp"
//using namespace std;

void String::Swap(String& s)
{
    std::swap(_str, s._str);
    std::swap(_len, s._len);
    std::swap(_capacity, s._capacity);
}

void String::PushBack(char ch)
{
	_str = (char*)realloc(_str, ++_len + 1);
	_capacity++;
    _str[_len] = '\0';
    _str[_len - 1] = ch;
}

void String::append(const char* str)
{
    _len += strlen(str);

    _str = (char*)realloc(_str, _len + 1);
    _capacity += _len;
	strcat(this->getStr(), str);
}

void String::PopBack()
{
    _str[--_len] = '\0';
}

void String::Insert(int pos, char ch)
{
    assert(pos <= _len);

    if (_len == _capacity)
    {
        _str = (char*)realloc(_str, ++_len + 1);
        _capacity = _len;
    }
    //strncat(&(_str[pos+1]), &(_str[pos]));
    int dest = _len;
    while (dest > pos)
    {
        _str[dest] = _str[dest - 1];
        dest--;
    }
    _str[pos] = ch;
}

void String::Insert(int pos, const char* str)
{
    //assert(pos <= _len);
    if (pos > _len)
        return;

    int len = strlen(str);
    _len += len;
    if (_len > _capacity)
    {
        _str = (char*)realloc(_str, _len + 1);
        _capacity = _len;
    }

    int i = 0;
    while (_len - i > pos + len - 1)
    {
        _str[_len - i] = _str[_len - i - len];
        i++;
    }
    int j = 1;
    while (_len - i - j + 2 >= pos + 1)
    {
        _str[_len - i - j + 1] = str[len - j];
        j++;
    }
}

void String::Erase(int pos, int count)
{
    //assert(pos < _len);
    if (pos >= _len)
        return;

    if (pos + count >= _len)
    {
        _str[pos] = '\0';
        _len = pos;
    }
    else
    {
        while (pos + count <= _len)
        {
            _str[pos] = _str[pos + count];
            pos++;
        }
        _len -= count;
    }
}

int String::Find(char ch) const
{
    int ret = 0;
    while (_str[ret] != ch&&_str[ret] != '\0')
        ret++;
    return _str[ret] == '\0' ? -1 : ret;
}

int String::Find(const char* str) const
{
    if (*str == '\0')
        return _len;

    int ret = 0;
    int len = strlen(str);
    while (ret + len <= _len)
    {
        int i = 0;
        while (_str[ret + i] == str[i] && str[i] != '\0')
            i++;
        if (str[i] == '\0')
            return ret;
        ret++;
    }
    return -1;
}

void String::setStr(char* str)
{
	_str = str;
}

char* String::getStr()const
{
    return _str;
}

int String::getCapacity()
{
    return _capacity;
}

void String::setCapacity(int capacity)
{
    _capacity = capacity;
}

int String::getLength()const
{
    return _len;
}

void String::setLength(int len)
{
    _len = len;
}

const String& String::operator=(const String& s)
{
    if (_capacity < s._len)
    {
        _len = s._len;
        _str = (char*)realloc(_str, _len + 1);
        _capacity = _len;
    }
    strcpy(_str, s._str);
	#ifdef PRINT_SWITCH
	std::cout << "assign operator" << std::endl;
	#endif
    return *this;
}

const String& String::operator=(String&& s)
{
    if (_capacity < s._len)
    {
        _len = s._len;
        _str = (char*)realloc(_str, _len + 1);
        _capacity = _len;
    }
    strcpy(_str, s._str);
	s._str = nullptr;
	s._len = 0;
	s._capacity = 0;
	#ifdef PRINT_SWITCH
	std::cout << "move assign operator" << std::endl;
	#endif
    return *this;
}






/*************************************************************************/
// bool String::operator==(const String& s) 
// {
	// std::cout << "========not firend============" << std::endl;
    // if (this->_len == s._len)
    // {
        // int i = 0;
        // while (_str[i] == s._str[i])
        // {
            // if (_str[i] == '\0')
                // return true;
            // i++;
        // }
    // }
	
    // return false;
// }

std::ostream& operator<<(std::ostream& out, const String& s)
{
	if(s._str)
	{
		out << s._str;
	}
	else
	{
		out << "";
	}
	return out;
}

std::istream& operator>>(std::istream& in, const String& s)
{
	in >> s._str;
	return in;
}

bool operator==(const String& str1, const String& str2)
{
	if(str1.getLength() == str2.getLength())
	{
		if(0 == strcmp(str1.getStr(), str2.getStr()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

String& operator+(const String str1, const String str2)
{
	
	static String str{""};	//other methods?
	int newSize = str1.getLength() + str2.getLength();
	
    if (str.getCapacity() < newSize)
    {
        str.setLength(newSize);
        str.setStr((char*)realloc(str.getStr(), newSize + 1));
        str.setCapacity(newSize + 1);
    }
    strcpy(str.getStr(), str1.getStr());
	strcat(str.getStr(), str2.getStr());
	return str;
}


//compare function
/*************************************************************************/
int String::compare(const char* str)
{
	int ret = strcmp((*this)._str, str);
	if(ret > 0)
	{
		return 1;
	}
	else if(ret < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int String::compare(const String &s)
{
	int ret = strcmp((*this)._str, s._str);
	if(ret > 0)
	{
		return 1;
	}
	else if(ret < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
