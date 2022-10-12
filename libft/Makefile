NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_all_in.c \
		ft_calloc.c \
		ft_split.c \
		ft_substr.c \
		ft_atoi.c \
		ft_array.c \
		ft_arrayclear.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c  \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strskip.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_any.c \
		ft_strindex.c \
		ft_intindex.c \
		ft_splitlen.c \
		ft_isspace.c \
		ft_atoi_overflows.c

BONUS = ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstcpy.c \
		ft_lstdelone.c \
		ft_lstremove.c \
		ft_lstsize.c \
		ft_lstfind.c \
		ft_lstlast.c \
		ft_lstiter.c \
		ft_lstiter_arg.c \
		ft_lstreviter.c \
		ft_lstreviter_arg.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstcat.c \
		ft_lstclear.c \
		ft_lstany.c \
		ft_lstany2.c \
		ft_lststep.c \
		ft_lstskip.c \
		ft_lstadd_back_content.c \
		ft_lstdup_back.c \
		ft_lstdupint_back.c \
		ft_lststrjoin.c \
		ft_lstindex.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

bonus: $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $^

%.o: %.c libft.h
	$(CC) -c $< $(CFLAGS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
