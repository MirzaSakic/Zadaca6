
CC=g++
OPTIMIZE=-O0

INCPATH = include

CFLAGS= -std=c++11 $(OPTIMIZE) -fdiagnostics-color=always -I$(INCPATH) -Wall

HDRS= include/*.h
SRCS= main.cpp src/*.cpp

OBJS:=${SRCS:.cpp=.o}

zadaca6: $(HDRS) $(SRCS)
	$(CC) -o zadaca6 $(CFLAGS) $(SRCS)

