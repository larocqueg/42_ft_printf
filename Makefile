# The output file
NAME = libft.a

# Compiler
CC = cc

# Compilation flags (moulinette)
CFLAGS = -Wall -Wextra -Werror

# Includes directory (where libft.h is located at)
INCLUDES = .

# Directory of the *.c mandatory functions
SRCS = ft_printf.c ft_printchar.c ft_printstr.c ft_printpointer.c

# Mandatory objects
OBJS = $(SRCS:.c=.o)

# All rule
all: $(NAME)

# Compile the lib
# ar creates/modify libftprintf.a
# r tells ar to  insert OBJS into the libftprinf.a, if it already exists it will replace it
# c tells ar to create the archive if it does not exist
# s creats a index for each function in libftprintf.a
$(NAME): $(OBJS)
		ar rsc $(NAME) $(OBJS)

# Compiles the object files
%.o: %.c
		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

# Removes the object files
clean:
		rm -rf $(OBJS)

# Removes the object files and the libftprintf.a
fclean: clean
		rm -rf $(NAME)

# Removes the objects, libftprintf.a and make it all over again
re: fclean
		make

# Avoid name clashes
.PHONY: all clean fclean re
