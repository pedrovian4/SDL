
#OBJS specifies which files to compile as part of the project
OBJS = main.cpp


#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -I -Wall --std=c++11 -lm

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_ttf

HDRS = 	class.hpp functions.hpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(HDRS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
