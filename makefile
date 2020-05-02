SOURCE  := $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))       #在OBJS中 把.cpp和.c的文件变成.o的后缀
 
TARGET  := test_of_clog
CC      := g++
LIBS    := -lpthread
INCLUDE := -I./
CFLAGS  := -std=c++11 -g -Wall -O3 $(INCLUDE)
CXXFLAGS:= $(CFLAGS)
 
.PHONY : objs clean veryclean rebuild all
all : $(TARGET)
objs : $(OBJS)
rebuild: veryclean all
clean :
	rm -fr *.o
veryclean : clean
	rm -rf $(TARGET)
 
$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(INCLUDE) $(LIBS)
