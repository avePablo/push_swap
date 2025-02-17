NAME = push_swap

CC = gcc

# CFLAGS = -Wall -Werror -Wextra

# Directorios de las librerías
LIBDIR1 = ./Libft
LIBDIR2 = ./ft_printf
LIB = $(LIBDIR2)/libprintf.a $(LIBDIR1)/libft.a  
# Flags para las librerías
#LIBS = -L$(LIBDIR1) -lpinga -L$(LIBDIR2) -lprintf

SRC =	./mandatory/src/utils.c \
		./mandatory/src/main.c



OBJ = $(SRC:.c=.o)

# Objetivo principal
all: $(NAME)

# Compilar el ejecutable principal y vincular las librerías
$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

# Asegurarse de que la primera librería esté compilada
$(LIB):
	make -C $(LIBDIR1) all 	
	make -C $(LIBDIR2) all 

# Limpiar los archivos objeto
clean:
	rm -f $(OBJ)
	make -C $(LIBDIR1) clean
	make -C $(LIBDIR2) clean

# Limpiar todo (archivos objeto y ejecutable)
fclean: clean
	rm -rf $(NAME)
	make -C $(LIBDIR1) fclean
	make -C $(LIBDIR2) fclean

# Reconstruir todo
re: fclean all

.PHONY: all clean fclean re