# Copyright (C) 2019. All rights reserved.
# File name     ：Makefile
# Version       ：v1.0
# Author        ：zhengqijun
# Date          ：2019-12-25
# Description   ：automatically compile script

CC     := gcc
CFLAGS := -Wall
Target := a.out
Source := $(wildcard *.c)
Objs   := $(patsubst %.c, %.o, $(Source))

.PHONY : all clean

all : $(Target)

$(Target) : $(Objs)
	$(CC) $(CFLAGS) $(Source) -o $(Target)
	rm -f $(Objs)
	@echo make done!

clean :
	rm -f $(Target)
	@echo make clean!

# EOF

