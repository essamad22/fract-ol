# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 18:48:58 by aakhtab           #+#    #+#              #
#    Updated: 2023/12/11 15:47:06 by aakhtab          ###   ########.fr        #
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

SRCS			=	src/fractol.c src/draw.c src/colors.c \
					src/mandelbrot.c src/julia.c src/burningship.c src/events.c src/utils.c \
					
OBJS			=	$(SRCS:.c=.o)

CFLAGS			=	-Wall -Wextra -Werror 
#-fsanitize=address -g3
#-g -fsanitize=address

NAME			=	fractol

LIBFT		= lib/libft.a


MLX = -lmlx -framework OpenGL -framework AppKit

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

all:	${NAME}


${NAME}:	$(LIBFT) ${OBJS} header
			@$(CC) $(CFLAGS) $(SRCS) $(MLX) lib/libft.a -o $(NAME)


$(LIBFT)	:
	@make -s -C lib

##---- need to modier----------
%.o	: %.c
	@${CC} ${CFLAGS} -Imlx -c $< -o $@
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
			@make -s clean -C lib
			@rm -f $(OBJS)
			@printf "$(YELLOW)\r    [OBJECTS CLEANED 🗑️$(RESET)"

fclean:	clean
			@make -s fclean -C lib
			@rm -f ${NAME}
			@printf "\r												"
			@printf "$(RED)\r     [EVERYTHING CLEANED 👌]    \n$(RESET)"
			
re:	fclean all
