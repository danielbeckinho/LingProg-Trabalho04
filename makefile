CC = g++
CPPFLAGS = -Wall 

OBJECTS = mainProgram.o binaryTree.o cadastro.o customExceptions.o mainProgram.o menu.o patient.o pediatricPatient.o seniorPatient.o 

PROGRAM = mainProgram

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o: 
	$(CC) $(CPPFLAGS) -c $<

clean: 
	rm -vf mainProgram *.o
