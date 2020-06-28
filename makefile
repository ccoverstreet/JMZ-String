libjmzstring.so: objects objects/jmz_string_array.o objects/jmz_string_util.o
	gcc -shared objects/* -o libjmzstring.so

objects:
	mkdir objects

objects/jmz_string_array.o: src/jmz_string_array.c
	gcc -fPIC -c src/jmz_string_array.c -o objects/jmz_string_array.o

objects/jmz_string_util.o: src/jmz_string_util.c
	gcc -fPIC -c src/jmz_string_util.c -o objects/jmz_string_util.o

test_driver: libjmzstring.so test/driver.c
	gcc test/driver.c -L. -ljmzstring -o test_driver

memcheck: test_driver
	LD_LIBRARY_PATH=. valgrind --tool=memcheck -s ./test_driver
		
run: test_driver
	LD_LIBRARY_PATH=. ./test_driver
