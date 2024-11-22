NAME = gnl.a 
CSOURCE = get_next_line.c \
	  get_next_line_utils.c \
	  main.c

HSOURCE = get_next_line.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(CSOURCE:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	echo 'compiling library'
	ar rcs $@ $^

.c.o:
	echo 'create OBJECTS'
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	echo 'removing ft files'
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re 
