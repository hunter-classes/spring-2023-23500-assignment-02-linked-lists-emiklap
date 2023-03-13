OBJECTS=OList.o main.o Node.o
CXXFLAGS=-g

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)

OList.o: OList.cpp Node.h OList.h

List.o: List.cpp Node.h List.h

main.o: main.cpp List.h Node.h

Node.o: Node.cpp Node.h


clean:
	rm -f $(OBJECTS)
