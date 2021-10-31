
target 	:= main 
objs 	:=  ./build/main.o ./build/solSisLineares.o ./build/Matriz.o ./build/aproxFuncoes.o ./build/solEdos.o
CC 		:= g++
CFLAGS 	:= -g -Wall -lm -pthread

all: $(target)
run: $(target)
	./$(target)
deps := $(patsubst %.o, %.d, $(objs))
# -include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

main: $(objs)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: ./src/%.cpp	
	$(CC) $(CFLAGS) -c  $<  -o $@ $(DEPFLAGS)

clean:
	rm -f $(target) $(objs) $(deps)