
APP     := game
CCFLAGS := -g -Wall -Wextra -pedantic -std=c++20 
CFLAGS  := $(CCFLAGS)
CC      := g++
C       := gcc
MKDIR   := mkdir -p
SRC     := src
OBJ     := obj
LIBS    := -lX11 


ALLCPPS      := $(shell find $(SRC)/ -type f -iname "*.cpp")
ALLCS        := $(shell find $(SRC)/ -type f -iname "*.c")

ALLCSOBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(ALLCS))
ALLCPPSOBJS  := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(ALLCPPS))

SUBDIRS      := $(shell find $(SRC)/ -type d)
OBJSUBDIRS   := $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))


.PHONY: test

# generate folders for *.o files with same structure of src first
# then, complie main file

$(APP) : $(OBJSUBDIRS) $(ALLCSOBJS) $(ALLCPPSOBJS)
	$(CC) -o $(APP) $(ALLCPPSOBJS) $(ALLCSOBJS) $(LIBS)

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) -o $@ -c $^ $(CFLAGS)

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CC) -o $@ -c $^ $(CCFLAGS)

test:
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCPPS))
	$(info $(ALLCS))
	$(info $(ALLCSOBJS))

# TODO: tries to create ALL the dirs even if some exist
$(OBJSUBDIRS): 
	$(MKDIR) $@

clean:
	rm -rf obj

recode: clean $(APP)
