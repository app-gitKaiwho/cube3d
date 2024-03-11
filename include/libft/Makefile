# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 16:51:48 by lvon-war          #+#    #+#              #
#    Updated: 2024/03/11 10:10:40 by lvon-war         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
BLUE=\033[0;34m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m
CLEAR=\033[2K

define spinner
    while :; do for s in ◡ ⊙ ◠; do printf "\r${CLEAR}${BLUE}%s${NC} %s %s %s %s" "$$s" "$1"; sleep 0.1; done; done
endef

define end_spinner
	printf "\r${CLEAR}${GREEN}✓${NC}%s %s %s\n" "$1"
endef

# Executable Name 
NAME	=	lib.a
CFLAGS	=	-Wall -Werror -Wextra -I. -c
AR		=	ar -rsc
FILES	=	ft_printf.c ft_basicprint.c ft_printu.c ft_printx.c
FILES	+=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcpy.c \
			ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_toupper.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c ft_is_whitespace.c ft_power.c ft_swap.c ft_abs.c ft_listmanip.c\
			ft_rev_int_tab.c ft_strstartw.c
FILES	+=	get_next_line.c

all : $(NAME)

# Path for .c , .h and .o Files 
SRC_PATH := ./LIBFT_SRCS/
PFSRC_PATH := ./PF_SRCS/
GNLSRC_PATH := ./GNL_SRCS/
OBJ_PATH := ./OBJ/
INC_PATH := -I ./include

ifeq ($(shell uname),Darwin)
	ECHOFLAG :=
else
	ECHOFLAG := -e
endif

# Files to compile
OBJ1 := $(FILES:.c=.o)
OBJ := $(patsubst %,$(OBJ_PATH)%,$(OBJ1))

$(NAME): update_obj

update_obj:
	@$(MAKE) -s create_obj
	@$(MAKE) -s buid_arch

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

# Build .o first
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH) && printf "[${@}]"
	@sleep 0.1

$(OBJ_PATH)%.o: $(GNLSRC_PATH)%.c
	@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH) && printf "[${@}]"
	@sleep 0.1

$(OBJ_PATH)%.o: $(PFSRC_PATH)%.c
	@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH) && printf "[${@}]"
	@sleep 0.1

# Clean all the object files and the binary
clean:   
	@echo $(ECHOFLAG) "[${GREEN}Cleaning${NC}]"
	@$(RM) -rfv $(OBJ_PATH)* | while read -r line; do echo $(ECHOFLAG) "${RED}-  ${NC}$$line"; done

fclean: clean
		@$(RM) -rfv $(NAME) | echo $(ECHOFLAG) "${RED}- ${NC} ${NAME}";
		@$(RM) -rfv test.out |  echo $(ECHOFLAG) "${RED}- ${NC} test.out";

re: fclean all

test: all
	gcc main.c $(NAME) $(C_FLAGS) -o test.out
	./test.out

.PHONY : clean fclean re normi
