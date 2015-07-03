CC=g++
CX=g++
RM=rm -f
CPPFLAGS= -std=c++11
LDLIBS=-lGL -lglfw -lGLEW

SRCS=main.cpp MainGame.cpp Sprite.cpp GLSLprogram.cpp errors.cpp

all: main

main : $(SRCS)
	$(CXX) $(SRCS) -o main $(CPPFLAGS) $(LDLIBS)

dist-clean: clean
	$(RM) main
