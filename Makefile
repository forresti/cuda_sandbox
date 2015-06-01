
OBJS = main.o  helpers.o

EXENAME = main
CCOPTS = -c  -g   
LINK = nvcc
LINKOPTS =
 
all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LINK) -o $(EXENAME) $(OBJS) $(LINKOPTS)

main.o : main.cpp helpers.h
	$(CC) $(CCOPTS) main.cpp

helpers.o : helpers.cpp helpers.h
	$(CC) $(CCOPTS) helpers.cpp

clean : 
	rm -f *.o $(EXENAME) 2>/dev/null

