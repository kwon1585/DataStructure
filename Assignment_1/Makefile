CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c operation.c polynomial.c
OBJS = $(SRCS:.c=.o)

TARGET = polynomial.out

all : fclean $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $^