CC = g++
CFLAGS = -Wall -Wextra -O2
BUILDDIR = ./build
SRCDIRS = $(shell find . -type d)
SRCS = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))
OBJDIR = $(BUILDDIR)/obj
OBJS   = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
TARGET = main

ALL: $(OBJS)
	-mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -o $(BUILDDIR)/$(TARGET) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	-mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-rm -rf $(BUILDDIR)
