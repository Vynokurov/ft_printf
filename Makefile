NAME = libftprintf.a
SRC = ft_printf.c func_letter.c struct_making.c s_func.c d_func.c u_func.c x_func.c c_func.c C_func.c
OBJ = $(SRC:.c=.o)
HEAD = ft_printf.h
FLAGS =
//LIB = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar -cru $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)
	@echo libftprintf.a has been made

%.o: %.c
		gcc $(FLAGS) -c -o $@ $<	


cleanlib:
	make clean -C ./libft

fcleanlib:
	make fclean -C ./libft

clean: cleanlib
	rm -f $(OBJ)
	@echo *.o have been cleaned.

fclean: clean fcleanlib
	rm -f $(NAME)
	@echo *.a and *.o have been cleaned.

re: fclean all
	
