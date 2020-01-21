src := $(shell ls *.cpp)
objs:= $(patsubst %.cpp,%.o,$(src)) 
 
analog : $(objs)
	g++ -o $@ $^ 
 
%.o : %.cpp
	g++ -c -o $@ $< 
 
clean :
	rm -f analog *.o 

