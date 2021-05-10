TAR ?= test
SRC_EXT ?= cpp

ifeq ($(SRC_EXT),cpp)
	CPL ?= g++
else
ifeq ($(SRC_EXT),c)
	CPL ?= gcc
endif
endif

ifeq ($(SRC_EXT),cpp)
	STD ?= -std=c++14
else
ifeq ($(SRC_EXT),c)
	STD ?= -std=c11
endif
endif

OLV ?= 2
DBG ?= n
ifeq ($(DBG),y)
	CFLG ?= -g $(STD)
	CLN ?= n
else
ifeq ($(DBG),n)
	CFLG ?= $(STD) -O$(OLV)
	CLN ?= y
endif
endif

SRC := $(TAR).$(SRC_EXT)

.PHONY:clean all fclean exec

all: fclean $(TAR) exec clean

fclean:
	rm -f $(TAR)

$(TAR): $(SRC)
	$(CPL) $(CFLG) $(SRC) -lm -o $(TAR)

exec:
ifeq ($(DBG),y)
	gdb $(TAR)
else
ifeq ($(DBG),n)
	./$(TAR)
endif
endif

clean:
ifeq ($(CLN),y)
	rm -f $(TAR)
endif
