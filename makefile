COURSE = cs240
SEMESTER = spring2022

# Update the CP_NUMBER if you adapt this makefile for future assignments
CP_NUMBER = 2

# Change the following to your own information
LASTNAME = bozan
GITUSERID = nilsubozan

# The name of the executable
EXE = Play

# Name files according to CS240 naming conventions
REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

# Store executables in a subdirectory
all: $(BIN)/$(EXE)

# Reflects how the files may have been named in CP0
$(BIN)/$(EXE): $(OBJ)/Player.o $(OBJ)/Team.o $(OBJ)/Play.o
	$(CC) $(FLAGS) $(OBJ)/Player.o $(OBJ)/Team.o $(OBJ)/Play.o -o $@

$(OBJ)/Play.o: Parser.cpp Parser.h Player.h Team.h
	$(CC) $(FLAGS) -c Parser.cpp -o $@

# Update to add targets for your other .o files, following the Play.o sample
$(OBJ)/Player.o: Player.cpp Player.h 
	$(CC) $(FLAGS) -c Player.cpp -o $@

$(OBJ)/Team.o: Team.cpp Team.h Player.h
	$(CC) $(FLAGS) -c Team.cpp -o $@
# Run make tar to build a .tar.gz file appropriate for uploading to Brightspace
tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
