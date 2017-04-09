COMP            = g++ 
FLAGS           = -g -Wall
LIBS            =  
OBJ2_LIST       = i8051.o syn.o
TARGET2_NAME    = 8051syn

all: $(TARGET2_NAME)

$(TARGET2_NAME): $(OBJ2_LIST)
	$(COMP) $(FLAGS) -o $(TARGET2_NAME) $(OBJ2_LIST) $(LIBS)

%.o: %.cc %.h
	$(COMP) $(FLAGS) -c $<

clean:
	rm -f *.o *~ core $(TARGET1_NAME)
