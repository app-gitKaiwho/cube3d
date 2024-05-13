# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 16:52:50 by lvon-war          #+#    #+#              #
#    Updated: 2024/05/13 11:06:19 by lvon-war         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
BLUE=\033[0;34m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m
CLEAR=\033[2K
NAPDURATION=0.1

define spinner
    while :; do for s in ◡ ⊙ ◠; do printf "\r${CLEAR}${BLUE}%s${NC} %s %s %s %s" "$$s" "$1"; sleep 0.1; done; done
endef

define end_spinner
	printf "\r${CLEAR}${GREEN}✓${NC}%s %s %s\n" "$1"
endef

# Executable Name
ENAME	=	cub3d
NAME	=	cub3d.a
CFLAGS	=	-Wall -Werror -Wextra
AR		=	ar -rsc
FILES	=	main.c utils.c init.c display.c minimap.c control.c raycast.c player.c renderer.c mouse.c parsing.c

# Path for .c , .h and .o Files 
LIBFT	=	./include/libft/lib.a
SRC_PATH := ./SRC/
OBJ_PATH := ./OBJ/

# Compliation under Mac OS
ifeq ($(shell uname),Darwin)
INC_PATH := -I ./include/libft/include -I ./include/minilibx_macos  -I ./include
LINKER := -L ./include/minilibx_macos -lmlx -lm
FRAMEWORK := -framework Appkit -framework OpenGl
MLX_PATH := ./include/minilibx_macos
MLX := ./include/minilibx_macos/libmlx.a
ECHOFLAG := 

# Compliation under anything else (but only work under linux)
else
INC_PATH := -I ./include/libft/include -I ./include/minilibx-linux -I ./include
LINKER := -L ./include/minilibx-linux -lmlx -lX11 -lXext -lm -I ./include/minilibx_macos
FRAMEWORK :=
MLX_PATH := ./include/minilibx-linux
MLX := ./include/minilibx-linux/libmlx.a
ECHOFLAG := -e
endif

all :
	@$(MAKE) -s $(MLX) $(LIBFT) $(NAME)

$(MLX) :
	@echo $(ECHOFLAG) "[${GREEN}MLX${NC}]"
	@$(call spinner, "Waiting on mlx...") & SPIN_PID=$$! ; \
	make -s -C $(MLX_PATH) > /dev/null & COMP_PID=$$! ; \
	wait $$COMP_PID ; kill $$SPIN_PID ; $(call end_spinner, "Libft is ready!")

$(LIBFT) :
	@echo $(ECHOFLAG) "[${GREEN}LIBFT${NC}]"
	@$(call spinner, "Waiting on libft...") & SPIN_PID=$$! ; \
	make -s -C ./include/libft > /dev/null & COMP_PID=$$! ; \
	wait $$COMP_PID ; kill $$SPIN_PID ; $(call end_spinner, "Libft is ready!")

# Files to compile
OBJ1 := $(FILES:.c=.o)
OBJ := $(patsubst %,$(OBJ_PATH)%,$(OBJ1))

$(NAME): update_obj

update_obj:
	$(MAKE) -s create_obj
	$(MAKE) -s buid_arch
	$(MAKE) -s create_exece

create_obj:
	@echo $(ECHOFLAG) "[${GREEN}Compliling${NC}]"
	@$(call spinner, "Creating .o files...") & SPIN_PID=$$! ; \
	$(MAKE) -s $(OBJ) & COMP_PID=$$! ; \
	wait $$COMP_PID ; kill $$SPIN_PID ; \
	$(call end_spinner, "Object Made Successfully!")
	
buid_arch:
	@$(call spinner, "Building Archive...") & SPIN_PID=$$! ; \
	$(AR) $(NAME) $(OBJ) $(LINKFLAGS) & COMP_PID=$$! ; \
	wait $$COMP_PID ; kill $$SPIN_PID; \
	$(call end_spinner, "Archive Built Successfully!")

create_exece:
	@$(call spinner, "Creating Executable...") & SPIN_PID=$$! ; \
	$(CC) $(CFLAGS) $(NAME) $(LIBFT) $(MLX) $(INC_PATH) $(FRAMEWORK) $(LINKER) -o $(ENAME) & COMP_PID=$$! ; \
	wait $$COMP_PID ; kill $$SPIN_PID; \
	$(call end_spinner, "Executable Created Successfully!");

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC_PATH) && printf "[${@}]"
	@sleep ${NAPDURATION}

clean:   
	@echo $(ECHOFLAG) "[${GREEN}Cleaning${NC}]"
	@$(RM) -rfv $(OBJ_PATH)* | while read -r line; do echo $(ECHOFLAG) "${RED}-  ${NC}$$line"; done

fclean: clean
	@$(RM) -rfv $(NAME) | echo $(ECHOFLAG) "${RED}- ${NC} ${NAME}";
	@$(RM) -rfv $(ENAME) |  echo $(ECHOFLAG) "${RED}- ${NC} ${ENAME}";
	
deepclean : fclean
	@make -s fclean -C ./include/libft

mlxclean :
	@make -s clean -C $(MLX_PATH)

re: fclean all

san: all
	@$(CC) $(CFLAGS) $(NAME) $(LIBFT) $(MLX) $(INC_PATH) $(FRAMEWORK) $(LINKER) -fsanitize=address -o $(ENAME)
	@echo ${ECHOFLAG} "[${YELLOW}INFO${NC}] Sanitizer is ON"

test: all
	./$(ENAME)

.PHONY : clean fclean deepclean re test all