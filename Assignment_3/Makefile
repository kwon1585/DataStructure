CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c tree.c queue.c
OBJS = $(SRCS:.c=.o)

TARGET = bst.out

all : fclean $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

# ------------- make 또는 make all 실행 시 -----------------
# rm -f main.o tree.o queue.o bst.out
# gcc -Wall -Wextra -Werror -c main.c
# gcc -Wall -Wextra -Werror -c tree.c
# gcc -Wall -Wextra -Werror -c queue.c
# gcc -Wall -Wextra -Werror -o bst.out main.o tree.o queue.o
# rm -f main.o tree.o queue.o

# Source file -> Object file -> 실행 file