CC=g++
FLAGS=-W -Wall
TARGET1=test_static
TARGET2=test_dll
SOURCE1=test_static.cpp
SOURCE2=test_dll2.cpp

static  : $(TARGET1)
dll : $(TARGET2)

$(TARGET1) : $(SOURCE1)
	$(CC) -static $(FLAGS) -o $@ $^ ./libmap.a

$(TARGET2) : $(SOURCE2)
	$(CC) -o $@ $^ -ldl ./libmap.so 

clean:
	rm -rf $(TARGET2)
	rm -rf $(TARGET1)