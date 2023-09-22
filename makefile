PROJ_NAME=gerenciador
 
# .c files
C_SOURCE=$(wildcard *.c)
 
# .h files
H_SOURCE=$(wildcard *.h)
 
# Object files
OBJ=$(C_SOURCE:.c=.o)
 
# Compiler
CC=gcc
 
# Flags for compiler
CC_FLAGS=-c         \
         -Wall      \

#
# Compilation and linking
#
all: $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
		$(CC) -o $@ $^
 
%.o: %.c %.h
		$(CC) -o $@ $< $(CC_FLAGS) -lm
 
main.o: main.c $(H_SOURCE)
		$(CC) -o $@ $< $(CC_FLAGS)
 
clean:
		@echo "Limpando sujeira ..."
		@rm -f *~ *.bak

purge:  clean
		@echo "Limpando tudo ..."
		@rm -f $(PROG) *.o core a.out gerenciador
		
.PHONY: all