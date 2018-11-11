#include<iostream>

using namespace std;

class Animal
{  
public:  
    virtual void eat()  
    {  
        cout<<"i eat like animals."<<endl;  
    }

	virtual void drink() = 0;
};  

class Dog:public Animal  
{  
public:  
    // void eat()  
    // {  
        // cout<<"i eat like a dog."<<endl;  
    // } 

	void drink()
	{
		cout<<"water."<<endl;  
	}
};

  
int main(void)  
{  
    Animal *a = new Dog();  
    a->eat(); 
    return 0;  
}
