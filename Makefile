NAME = so_long
NAMEB = so_long_bonus
SRC = mandatory/so_long.c mandatory/parser.c mandatory/utils.c mandatory/utils_2.c
SRCB = bonus/so_long_bonus.c bonus/parser_bonus.c bonus/utils_bonus.c bonus/utils_bonus_2.c

flags =-Wall -Wextra -Werror
mlx =-lmlx -framework OpenGL -framework AppKit
OBJ = ${SRC:.c=.o}
OBJB = ${SRCB:.c=.o}

%.o:%.c
	@cc ${flags} -c $< -o $@

all : ${NAME}

bonus : ${NAMEB}

${NAME} : ${OBJ} mandatory/so_long.h
	@make -C libft
	@cc ${flags} ${mlx} ${OBJ} libft/libft.a -o ${NAME}
	@echo "GameCreated"

${NAMEB} : ${OBJB} bonus/so_long_bonus.h
	@make -C libft
	@cc ${flags} ${mlx} ${OBJB} libft/libft.a -o ${NAMEB}
	@echo "GameCreated"

clean :
	@make -C libft clean
	@rm -rf ${OBJ} ${OBJB}
	@echo "Cleaned"
fclean : clean
	@rm -rf ${NAME} ${NAMEB}
	@echo "FullyCleaned"
re : fclean ${NAME}
main : ./test/main.c
	@cc ${flags} ${mlx} -Wall -Wextra -Werror -o main $<