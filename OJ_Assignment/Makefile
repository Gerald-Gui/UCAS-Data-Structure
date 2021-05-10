TAR ?= test
EXT ?= cpp
EXEC ?= y

ifeq ($(EXT),cpp)
	CPL ?= g++
else
ifeq ($(EXT),c)
	CPL ?= gcc
endif
endif

ifeq ($(EXT),cpp)
	STD ?= c++14
else
ifeq ($(EXT),c)
	STD ?= c11
endif
endif

OLV ?= 2
DBG ?= n
ifeq ($(DBG),y)
	CFLG ?= -g -std=$(STD)
	CLN ?= n
else
ifeq ($(DBG),n)
	CFLG ?= -std=$(STD) -O$(OLV)
	CLN ?= y
endif
endif

ifeq ($(EXEC),n)
	CLN = n
endif

SRC := $(TAR).$(EXT)

.PHONY:clean all fclean exec

all: fclean $(TAR) exec clean

fclean:
	rm -f $(TAR)

$(TAR): $(SRC)
	$(CPL) $(CFLG) $(SRC) -lm -o $(TAR)

exec:
ifeq ($(EXEC),y)
ifeq ($(DBG),y)
	gdb $(TAR)
else
ifeq ($(DBG),n)
	./$(TAR)
endif
endif
endif

clean:
ifeq ($(CLN),y)
	rm -f $(TAR)
endif
