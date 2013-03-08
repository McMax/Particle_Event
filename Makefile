CC	= g++
LD	= g++

CCFLAGS = -g -O0 `root-config --cflags` -Wall -I$(INC_DIR)
LDFLAGS = -g -O0 `root-config --libs` -Wall -L$(OBJ_DIR)

TOPDIR = .
SRC_DIR = $(TOPDIR)/src
OBJ_DIR = $(TOPDIR)/lib
INC_DIR = $(TOPDIR)/inc

SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
INCLUDES = inc/Particle.h inc/Event.h inc/ParticleTree.h inc/linkdef.h

all: $(OBJECTS) Dict.o
	mv Dict.h $(INC_DIR)
	mv Dict.cpp $(SRC_DIR)
	mv Dict.o $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp Dict.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CCFLAGS) $< -o $@ 

Dict.o: Dict.cpp
	g++ -c $(CCFLAGS) Dict.cpp -o Dict.o	

Dict.cpp: $(INCLUDES)
	@echo "Generating dictionary..."
	rootcint -f Dict.cpp -c -P -I$(ROOTSYS) -I/usr/local/include $(INCLUDES)

clean:
	@rm -rf $(INC_DIR)/Dict.h $(SRC_DIR)/Dict.cpp $(OBJ_DIR)
