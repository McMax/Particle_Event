CC	= g++
LD	= g++

CCFLAGS = -g -O0 `root-config --cflags` -Wall -I./inc
LDFLAGS = -g -O0 `root-config --libs` -Wall -L./lib

TOPDIR = .
SRC_DIR = $(TOPDIR)/src
OBJ_DIR = $(TOPDIR)/lib
INC_DIR = $(TOPDIR)/inc

SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
#INCLUDES := $(shell find $(INC_DIR) -type f -name "*.h" | grep -v "linkdef.h" | grep -v "Prefifi.h")
#INCLUDES += $(INC_DIR)/linkdef.h
INCLUDES = inc/Particle.h inc/Event.h inc/linkdef.h

all: Dict.o

Dict.o: Dict.cpp
	g++ -c $(CCFLAGS) Dict.cpp -o Dict.o	

Dict.cpp: $(INCLUDES)
	@echo "Generating dictionary..."
	rootcint -f Dict.cpp -c -P -I$(ROOTSYS) -I/usr/local/include $(INCLUDES)

clean: realclean

realclean:
	@rm -rf Dict.*
