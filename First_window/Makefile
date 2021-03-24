

# set the compiler
CC := g++

# set the compiler flags
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c++11 -Wall -lSDL2_image -lm

# add header files here
HDRS :=

# add source files here
SRCS := 

# generate names of object files
OBJS := $(SRCS:.cpp=.o)

# name of executable
EXEC := main

# default recipe
all: $(EXEC)


$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)


clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
