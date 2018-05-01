CC = gcc
TARGET = test
OBJ = jfj.o test.o
CFLAGS = -Wall -Wextra -Werror

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

.PHONY : clean fclean re

clean :
	/bin/rm $(OBJ)

fclean :
	/bin/rm $(OBJ) $(TARGET)

re : fclean all
