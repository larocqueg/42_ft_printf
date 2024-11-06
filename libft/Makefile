# The name of the lib
NAME = libft.a

# Compiler
CC = cc

# Compiling flags
CFLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = .  # Points to the directory containing libft.h

# Source files
SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strnstr.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_strrchr.c \
ft_substr.c ft_strjoin.c ft_memmove.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
ft_putendl_fd.c ft_striteri.c ft_itoa.c ft_split.c ft_strmapi.c

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# all rule
all: $(NAME)

# Compile the lib
# ar creates/modify libft.a
# r tells ar to  insert OBJS into the libft.a, if it already exists it will replace same name files
# c tells ar to create the archive if it does not exist
# s creats a index for each function in libft.a
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

#compiles the bonus
bonus: $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# Compile the object files
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

# clean rule removes .o from srcs
clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

# fclean rule runs clean then removes libft.a
fclean: clean 
	rm -rf $(NAME)

# re rule runs fclean then runs make again
re: fclean
	make && make bonus

# Avoid name clashes
.PHONY: all clean fclean re bonus

