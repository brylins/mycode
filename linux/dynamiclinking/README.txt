project introduce:
	1、了解动态库的原理
	2、会使用gcc编译生成动态库
	3、使用gcc将动态库编译进新的代码
	
	
usage：
	gcc -fPIC -shared -o Lib.so Lib.c	//当前目录下产生Lib.so动态库
	export LD_LIBRARY_PATH=./   		//临时方法加载当前目录的动态库
	gcc -o p1 program1.c ./Lib.so		//命令中的./Lib.so指的是当前路径下的动态库
	gcc -o p2 program2.c ./Lib.so
	
	./p1
	./p2