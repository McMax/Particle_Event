CC	= g++
LD	= g++

TOPDIR = .
SRC_DIR = $(TOPDIR)
OBJ_DIR = $(TOPDIR)

CCFLAGS = -g `root-config --cflags` -Wall -I$(PEV_INC)
LDFLAGS = -g `root-config --libs` -Wall -L$(OBJ_DIR) -I$(PEV_LIB)

PEV_DIR = /data/analizy/Programy/Particle_Event_ClusPos
PEV_LIB = $(PEV_DIR)/lib
PEV_SRC = $(PEV_DIR)/src
PEV_INC = $(PEV_DIR)/inc

PROGRAM = example

SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
PEV_OBJECTS = $(PEV_LIB)/Particle.o $(PEV_LIB)/Event.o $(PEV_LIB)/ParticleTree.o $(PEV_LIB)/Dict.o

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS) $(PEV_OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CCFLAGS) $< -o $@ 

$(PEV_OBJECTS):
	@echo "No base libs. Create them"

clean:
	@rm -rf $(PROGRAM) *.o
