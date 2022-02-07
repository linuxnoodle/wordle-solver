PROJECT:=wordle-solver

CC:=g++
LDFLAGS=-O2 -Wall -Iinclude -Ilib/fmt/include/
UNAME:=$(shell uname)

SRCDIR:=src
OBJDIR:=obj

SRC:=$(wildcard $(SRCDIR)/*.cpp)
OBJ:=$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(PROJECT): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(LDFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: all
all: clean update-wordlist $(PROJECT)

.PHONY: update-wordlist
update-wordlist:
	curl https://raw.githubusercontent.com/tabatkins/wordle-list/main/words > words.txt

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(PROJECT)
