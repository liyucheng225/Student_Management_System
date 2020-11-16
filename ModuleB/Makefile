cou=../RELEASE/modb/cou.o
stu=../RELEASE/modb/stu.o
home=../RELEASE/modb/homefile.o
stu-c=../RELEASE/modb/stu-cou.o
libmodb=../RELEASE/modb/libmodb.so 
rmfile=$(cou) $(stu) $(home) $(stu-c) $(libmodb)
all:$(cou) $(stu) $(home) $(stu-c) $(libmodb)
$(cou):cou.c 
	gcc -c $< -o $@ -fPIC  
$(stu):stu.c 
	gcc -c $< -o $@ -fPIC
$(home):homefile.c 
	gcc -c $< -o $@ -fPIC
$(stu-c):stu-cou.c 
	gcc -c $< -o $@ -fPIC
$(libmodb):$(cou) $(home) $(stu) $(stu-c)
	gcc  -shared -o $@  $^ 
.PHONY:clean
clean:
	rm $(rmfile) 

