UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
LIBS=-framework OpenGL -framework GLUT
else
LIBS=-lglut
endif

CFLAGS=-O -Wall -Werror -Wextra -pedantic -std=c99 $(LIBS)

all: main
