# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 12:10:03 by bruperei          #+#    #+#              #
#    Updated: 2025/05/02 12:59:44 by bruperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME = libftprintf.a

# ------------  FILEPATHS  --------------------------------------------------- #
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
#Rules to identify the location of libft.

FT_PRINTF = ./ft_printf
#Rule to identify the location of ft_printf sources.

# ------------  SOURCE FILES  ------------------------------------------------ #
SRCS_FT_PRINTF = ft_hexadecimal.c ft_pointer.c ft_printf.c ft_unsigned.c \
					ft_utils.c

OBJS_FT_PRINTF = $(SRCS_FT_PRINTF:.c=.o)
#() are used to group commands together.
#{} are used to define variables.

# ------------  FLAGS  ------------------------------------------------------- #
AR = ar rcs
#ar is GNU command wich is used to create and manage archives.
#r tells ar to replace any existing members of the archive with the specified
#object files.
#c tells ar to create the archive if it doesn't exist.
#s tells ar to create an index of the archive members.

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

CP = cp
#copy.

# ------------  RULES  ------------------------------------------------------- #
.PHONY : all clean fclean re 
#.PHONY is used to identify false targets

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_FT_PRINTF)

		$(CP) $(LIBFT) $(NAME)
		@$(AR) $(NAME) $(OBJS_FT_PRINTF)
#This rule is saying that to create the target file, make should use
#theLIBFTlinker to link together the object files in OBJS_FT_PRINTF.

$(LIBFT): $(LIBFT_PATH)
		@$(MAKE) -C $(LIBFT_PATH)
#The -C flag is used to specify the directory in which the make
#command should be executed.

%.o: 		$(FT_PRINTF)/%.c
				@$(CC) $(CFLAGS) -c $< -o $@
#It matches any file name that ends in .o.
#prerequisite pattern file c into the folder.
#-c flag tells the compiler to not to link the object file
#with any other object files or libraries.
#-o is a flag for the name of .o files.

clean:
			@$(MAKE) clean -C $(LIBFT_PATH)
			@$(RM) $(OBJS_FT_PRINTF)
#Clean is used to remove .o files of libft and ft_printf.

fclean:		clean
				@$(MAKE) fclean -C $(LIBFT_PATH)
				@$(RM) $(NAME)
#fclean will do the same of clean, but remove the .a files.

re : fclean all
#re rule do fclean and compile again.

#used to create "false targets", avoiding errors
#declares that the following targets are NEVER a file, so it always find it directives inside the actual file
.PHONY: all clean fclean re
