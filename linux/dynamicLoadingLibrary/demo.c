

// cmd: gcc -fPIC -shared -o libadd.so add.c
// 编译生成动态库文件

// file : demo.c
#include <stdio.h>  
#include <stdlib.h>   	//EXIT_FAILURE
#include <dlfcn.h>    	//dlopen, dlerror, dlsym, dlclose

typedef int(*fun)(int, int); 	//定义函数指针类型的别名

const char* dlladdPath = "./libadd.so";
const char* dllminusPath = "./libminus.so";

int main()
{
    void* handle0 = dlopen(dlladdPath, RTLD_LAZY);
	void* handle1 = dlopen(dllminusPath, RTLD_LAZY);

    if(!handle0)
    {
		fprintf( stderr, "[%s](%d) dlopen get error: %s\n", __FILE__, __LINE__, dlerror());
		exit(EXIT_FAILURE);
    }
	
	if(!handle1)
    {
		fprintf( stderr, "[%s](%d) dlopen get error: %s\n", __FILE__, __LINE__, dlerror());
		exit(EXIT_FAILURE);
    }
	
    fun add_func = (fun)dlsym(handle0, "add");
    printf( "5 add 2 is %d \n", add_func(5, 2));
	
	fun minus_func = (fun)dlsym(handle1, "minus");
    printf( "5 minus 2 is %d \n", minus_func(5, 2));

    dlclose(handle0);
	dlclose(handle1);
}
