#-- program name, sources and obj --
TARGET=Appli
SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)

#-- compiler/linker settings --
CC=g++
CCFLAGS=-W -Wall -pedantic -g -std=c++14
IFLAGS=-I./include
LDFLAGS=

#-- main target to obtain --
all : $(TARGET)

#-- linker command to produce the executable file --
$(TARGET) : $(OBJ)
		@echo
			@echo Linking $@ ...
				$(CC) $^ -o $@ $(LDFLAGS)

#-- compiler command for every source file --
%.o : %.cpp
		@echo Compiling $< ....
			$(CC) -c $< $(IFLAGS) -o $@ $(CCFLAGS)

.PHONY: clean

#-- system-specific command to remove those files --
clean :
		@echo Cleaning...
			rm -f $(OBJ) $(TARGET) src/*~ include/*~ *~

run :
		optirun ./$(TARGET)

