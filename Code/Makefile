###compile toolchains####
CC=g++

###file dir###
ROOT_DIR=$(shell pwd)
SRC_DIR=$(ROOT_DIR)
OBJ_DIR=$(ROOT_DIR)/obj
SUB_DIR=$(filter-out $(OBJ_DIR),$(shell find . -type d))

###compile flag###
INC_DIR=$(patsubst %,-I%,$(SUB_DIR))
CFLAGS=$(INC_DIR) -Wall -std=c++11
LIBS :=
LD_FLAG :=


###src file###
SRC_FILE=$(foreach dir,$(SUB_DIR),$(shell ls $(dir)/*.cpp 2>/dev/null))
SRC_NAME=$(notdir $(SRC_FILE))

TARGET=$(ROOT_DIR)/algorithms_test
OBJS=$(patsubst %.cpp,%.o,$(SRC_NAME))

.PHONY:all clean

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $(patsubst %.o,$(OBJ_DIR)/%.o,$^)

$(OBJS):
	@if [ ! -d $(OBJ_DIR) ] ; then	\
		mkdir $(OBJ_DIR);	\
	fi
	$(CC) $(CFLAGS) -c $(shell find ./ -name $(patsubst %.o,%.cpp,$@)) -o $(OBJ_DIR)/$@	
	
clean:
	rm -rf $(OBJ_DIR) $(ROOT_DIR)/algorithms_test



