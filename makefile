PROJ_NAME=gerenciador
 
# .c files
C_SOURCE=$(wildcard ./src/*.c)
 
# .h files
H_SOURCE=$(wildcard ./src/*.h)
 
# Object files
OBJ=$(subst .c,.o,$(subst src,objects,$(C_SOURCE)))
 
# Compiler
CC=gcc
 
# Flags for compiler
CC_FLAGS=-c         \
         -Wall      \

#
# Compilation and linking
#

RM = rm -rf


all: objFolder $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
		$(CC) -o $@ $^
 
./objects/%.o: ./src/%.c ./src/%.h
		$(CC) -o $@ $< $(CC_FLAGS) -lm
 
./objects/main.o: ./src/main.c $(H_SOURCE)
		$(CC) -o $@ $< $(CC_FLAGS)
 
objFolder:
		@ mkdir -p objects

clean:
		@echo "Limpando sujeira ..."
		@rm -f *~ *.bak

purge:  
		@ $(RM) ./objects/*.o $(PROJ_NAME) *~
		@ rmdir objects
		
.PHONY: all purge