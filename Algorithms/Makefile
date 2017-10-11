###compile toolchains####
CC=gcc
LD=ld

###file dir###
ROOT_DIR=$(shell pwd)
SRC_DIR=$(ROOT_DIR)
OBJ_DIR=$(ROOT_DIR)/obj
#SUB_DIR:=sub1 sub2 sub3
#SUB_DIR=$(filter-out $(OBJ_DIR),$(basename $(patsubst ./%,%,$(shell find . -maxdepth 4 -type d))))
SUB_DIR=$(filter-out $(OBJ_DIR),$(shell find . -type d))
#INC_DIR=$(foreach dir,$(SUB_DIR),$(shell ls $(dir)/*.h))

###compile flag###
INC_DIR=$(patsubst %,-I%,$(SUB_DIR))
CFLAGS=$(INC_DIR) -Wall
LIBS :=
LD_FLAG :=


###src file###
SRC_FILE=$(foreach dir,$(SUB_DIR),$(shell ls $(dir)/*.c))
SRC_NAME=$(notdir $(SRC_FILE))

TARGET=$(OBJ_DIR)/test_makefile
OBJS=$(patsubst %.c,%.o,$(SRC_NAME))
.PHONY:all clean

all:$(TARGET)
#	@for dir in $(SUB_DIR);	\
#	do	\
#	$(SRC_FILE)+=$(wildcard *.c);	\
#	done	\

	echo $(SUB_DIR)
	echo $(SRC_FILE)	
	echo $(SRC_NAME)	
	echo $(OBJS)	

$(TARGET):$(OBJS)
	$(CC) -o $@ $(patsubst %.o,$(OBJ_DIR)/%.o,$^)
$(OBJS):
#	mkdir $(OBJ_DIR)	
#	echo $(SUB_DIR)
#	echo $(SRC_FILE)	
#	echo $(SRC_NAME)	
#	echo $(INC_DIR)	
#	echo $(INC_DIR)	
	
	if [ ! -d $(OBJ_DIR) ] ; then	\
		mkdir $(OBJ_DIR);	\
	fi
		
#	echo $@
	@$(CC) $(CFLAGS) -c $(shell find ./ -name $(patsubst %.o,%.c,$@)) -o $(OBJ_DIR)/$@	\
	
clean:
	rm -rf $(OBJ_DIR)	



