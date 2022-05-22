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

# ------------- make 또는 make all 실행 시 -----------------
# rm -f main.o operation.o polynomial.o polynomial.out
# gcc -Wall -Wextra -Werror -c main.c
# gcc -Wall -Wextra -Werror -c operation.c
# gcc -Wall -Wextra -Werror -c polynomial.c
# gcc -Wall -Wextra -Werror -o polynomial.out main.o operation.o polynomial.o
# rm -f main.o operation.o polynomial.o

# Source file -> Object file -> 실행 file