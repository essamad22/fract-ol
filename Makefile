# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 18:48:58 by aakhtab           #+#    #+#              #
#    Updated: 2023/07/08 01:13:39 by aakhtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=====COLORS=====#
RESET	= \033[0m
GRAY		= \033[0;90m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
PURPLE		= \033[0;35m
S1			= "=================================================================================="

CC			=	cc

SRCS			=	src/main.c

OBJS			=	$(SRCS:.c=.o)

CFLAGS			=	-Wall -Wextra -Werror -I./lib/libft -I./minilibx
#-g -fsanitize=address

NAME			=	fractol

LIBFT		= lib/libft.a

MINILIB = -Lmlx -lmlx -framework OpenGL -framework AppKit

all:	${NAME}


${NAME}:	$(LIBFT) ${OBJS} header
			@make -C minilibx
			@$(CC) $(CFLAGS) $(SRCS) $(MINILIB) lib/libft.a -o $(NAME)


$(LIBFT)	:
	@make -C lib

##---- need to modier----------
%.o	: %.c
	@${CC} ${CFLAGS} -c $< -o $@
##-----------------------------

header:
	@printf "\r$(PURPLE)$(S1)\n"
	@printf "	███████╗██████╗  █████╗  ██████╗████████╗    ██████╗ ██╗      \n"
	@printf "	██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝   ██╔═══██╗██║      \n"
	@printf "	█████╗  ██████╔╝███████║██║        ██║█████╗██║   ██║██║      \n"
	@printf	"	██╔══╝  ██╔══██╗██╔══██║██║        ██║╚════╝██║   ██║██║      \n"
	@printf	"	██║     ██║  ██║██║  ██║╚██████╗   ██║      ╚██████╔╝███████╗ \n"
	@printf "	╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝       ╚═════╝ ╚══════╝ \n"
	@printf "$(S1)\n$(RESET)"
clean:	
			@make clean -C lib
			@make clean -C minilibx
			@rm -f $(OBJS)
			@printf "$(YELLOW)\r    [OBJECTS CLEANED 🗑️$(RESET)"

fclean:	clean
			@make fclean -C lib
			@make clean -C minilibx
			@rm -f ${NAME}
			@printf "\r												"
			@printf "$(RED)\r     [EVERYTHING CLEANED 👌]    \n$(RESET)"
			
re:	fclean all