CC=g++
FLAGS=-W -Wall
TARGET1=test_static
TARGET2=test_dll
SOURCE1=kvs.h test_static.cpp
SOURCE2=test_dll.cpp

_static  : $(TARGET1)
_dll : $(TARGET2)

$(TARGET1) : $(SOURCE1)
	$(CC) -static $(FLAGS) -o $@ $^ ./libmap.a

$(TARGET2) : $(SOURCE2)
	$(CC) -o $@ -fpic $^ -ldl 

clean:
	rm -rf $(TARGET2)
	rm -rf $(TARGET1)