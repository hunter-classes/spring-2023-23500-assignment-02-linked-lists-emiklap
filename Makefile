OBJECTS=OList.o List.o main.o Node.o
CXXFLAGS=-g

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)

tests: tests.o OList.o Node.o
	g++ -o tests tests.o OList.o Node.o


OList.o: OList.cpp Node.h OList.h

List.o: List.cpp Node.h List.h

main.o: main.cpp OList.h List.o Node.h

tests.o: tests.cpp OList.h Node.h

Node.o: Node.cpp Node.h


clean:
	rm -f $(OBJECTS) tests.o
