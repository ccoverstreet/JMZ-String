libjmzstring.a: objects/jmz_string.o
	ar -rc libjmzstring.a objects/jmz_string.o

objects/jmz_string.o: src/jmz_string.c
	gcc -c src/jmz_string.c -o objects/jmz_string.o

driver: libjmzstring.a tests/driver.c
	gcc tests/driver.c -L. -ljmzstring -o driver

memcheck: driver
	valgrind --tool=memcheck ./driver
