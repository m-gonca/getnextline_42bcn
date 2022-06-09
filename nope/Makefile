NAME = getnextline.a

HEADER = get_next_line.h

SRCS = 	get_next_line.c \
		get_next_line_utils.c
		
OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

#BUFFER = -D BUFFER_SIZE=42

RM = rm -f

#%.o:%.c: $(HEADER)
#		$(CC) $(CFLAGS) $(BUFFER) $ -o $@ $<
#		@ECHO "Compiling ...$^"

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
		 $(CC) $(CFLAGS) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

test: all
	./a.out

.PHONY: all clean fclean re