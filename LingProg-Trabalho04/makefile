CC = g++
CPPFLAGS = -Wall 

OBJECTS = mainProgram.o cadastro.o menu.o patient.o pediatricPatient.o seniorPatient.o 

PROGRAM = mainProgram

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o: 
	$(CC) $(CPPFLAGS) -c $<

clean: 
	rm -vf mainProgram *.o
