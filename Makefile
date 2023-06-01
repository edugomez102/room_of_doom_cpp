#
# Makefile to generate main game executable and run_test executable
# 
#

###############################################################################
# Variable macros
###############################################################################

APP      := game
TEST_APP := run_tests

CCFLAGS := -std=c++20 
CFLAGS  := $(CCFLAGS)
CC      := g++
C       := gcc
MKDIR   := mkdir -p
SRC     := src
OBJ     := obj
LIBS    := -lX11 
INCLUDE  := -Isrc -Isrc/lib

TEST_SRC    := test
TEST_OBJ    := $(OBJ)/test

ALLCPPS      := $(shell find $(SRC)/ -type f -iname "*.cpp" -not -path "$(TEST_DIR)/*")
ALLCS        := $(shell find $(SRC)/ -type f -iname "*.c")

ALLCSOBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(ALLCS))
ALLCPPSOBJS  := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(ALLCPPS))

TEST_ALLCPPS  := $(shell find $(TEST_SRC)/ -type f -iname "*.cpp")
TEST_OBJS     := $(patsubst $(TEST_SRC)/%.cpp,$(TEST_OBJ)/%.o,$(TEST_ALLCPPS))

TEST_SRC_CPPOBJS   := $(filter-out $(OBJ)/main.o,$(ALLCPPSOBJS))

SUBDIRS      := $(shell find $(SRC)/ -type d)
OBJSUBDIRS   := $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))

###############################################################################
# Config
###############################################################################

ifeq ($(RELEASE),1)
    CCFLAGS += -O2
else
		CCFLAGS += -g -Wall -Wextra -Wpedantic -Wconversion
endif
CFLAGS  := $(CCFLAGS)


###############################################################################

.PHONY: dir


all: $(APP) test

# generate folders for *.o files with same structure of src first
# then, complie main file

$(APP) : $(OBJSUBDIRS) $(ALLCSOBJS) $(ALLCPPSOBJS)
	$(CC) -o $(APP) $(ALLCPPSOBJS) $(ALLCSOBJS) $(LIBS) $(INCLUDE)

test: $(TEST_APP)

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) -o $@ -c $^ $(CFLAGS) $(INCLUDE)

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CC) -o $@ -c $^ $(CCFLAGS) $(INCLUDE)

$(TEST_OBJ)/%.o: $(TEST_SRC)/%.cpp
	$(CC) -o $@ -c $^ $(CCFLAGS) -Isrc -Isrc/lib

$(TEST_APP) : $(OBJSUBDIRS) $(TEST_OBJS)
	$(CC) -o $(TEST_APP) $(TEST_OBJS) $(TEST_SRC_CPPOBJS) $(ALLCSOBJS) $(LIBS)
	./$(TEST_APP)

# build and run the game
gamer: $(APP)
	./$(APP)

# testing variable contents
dir:
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCPPS))
	$(info $(ALLCS))
	$(info $(ALLCSOBJS))

dir_test:
	$(info $(TEST_ALLCPPS))
	$(info $(TEST_OBJS))
	$(info $(TEST_SRC_CPPOBJS))

# TODO: tries to create ALL the dirs even if some exist
$(OBJSUBDIRS): 
	@$(MKDIR) $@
	@$(MKDIR) obj/test

clean:
	rm -rf obj
	rm -f $(APP)
	rm -f $(TEST_APP)

recode: clean $(APP)
