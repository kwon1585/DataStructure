CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = .
SRCS = main.c operation.c polynomial.c
OBJS = $(SRCS:.c=.o)

TARGET = polynomial.out

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

$(SRC_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $^

