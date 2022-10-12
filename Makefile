SRCS = $(wildcard src/*.c)
HEADERS = $(wildcard include/*.hpp)
OBJS = $(SRCS:src/%.c=obj/%.o)
NAME = ft_ping
CFLAGS = -Iinclude -Ilibft -Llibft -lft -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(HEADERS)
$(NAME): $(OBJS)
	@cd libft/ && $(MAKE)
	g++ -o $@ $(OBJS) $(CFLAGS)

obj/:
	mkdir obj/
$(OBJS): $(HEADERS) | obj/
obj/%.o: src/%.c
	gcc -c -o $@ $< $(CFLAGS)

clean:
	rm -rf obj/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
