file1=./RELEASE/moda/libmoda.so
file2=./RELEASE/modb/libmodb.so
stuk=./RELEASE/stukey
stuf=./RELEASE/stufile
rmfile=$(stuk) $(stuf)
all:$(stuk) $(stuf)  
$(stuk):stuKeyboard.c
	gcc -o $@  $< $(file1)
$(stuf):stuFile.c
	gcc -o $@  $< $(file2)
.PHONY:clean k.out  f.out
clean:
	rm $(rmfile)
k.out:
	./RELEASE/./stukey
f.out:
	./RELEASE/./stufile
