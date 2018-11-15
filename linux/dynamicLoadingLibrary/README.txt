project introduce:
	1、了解动态装在库。
	2、会使用dlopen、dlsym、dlerror及dlclose四个函数。
	3、了解加载的过程，是在程序运行之后采取加载动态库的。
	
	
usage：
	产生两个动态库libadd.so、libminus.so
		gcc -fPIC -shared -o libadd.so add.c
		gcc -fPIC -shared -o libminus.so minus.c
	
	编译demo
		gcc -o demo demo.c -ldl; 
		./demo
	输出：
		5 add 2 is 7
		5 minus 2 is 3
	
	
	将动态库libadd.so删除，运行demo，程序出错。
	将动态库libadd.so重新生成，运行demo，程序正常。
	
	这说明该方法是运行时采取加载动态库的，这种方式可以用于编写插件。
	
