#Make

sources = list_main.c list_point_1.c list_point_2.c
target = list
ccflags = -Wall -g -fsanitize=address
CC = gcc

all:
	$(CC) $(sources) $(ccflags) -o $(target)