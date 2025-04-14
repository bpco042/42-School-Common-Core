# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 12:10:03 by fcorvaro          #+#    #+#              #
#    Updated: 2025/04/14 12:59:44 by fcorvaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Library name
NAME = libft.a

#Compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Create or update a static library
#r - replace existing files / c - creates libft.a if doesn't exist / s - create an index to the lib
AR = ar rcs

#Remove files
#rm - remove / f - forced
RM = rm -f

#Sources required
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_tolower.c ft_toupper.c

#Bonus sources
SRCS_B = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

#Mandatory objects and bonuses
#turns .c files to object files
OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}

#Standard rule to compile .c files to .o not linking (-c) the files
#$< - that part will be replaced by the file name (ex. ft_atoi.c) / ${<:.c=.o} - that one is the transformation of .c to .o
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#Creation of static lib with the mandatory objects
${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

#Standard compiling
all: ${NAME}

#Compiling with bonus
bonus: ${NAME} ${OBJS_B}
	${AR} ${NAME} ${OBJS_B}

#Clean objects
clean:
	${RM} ${OBJS} ${OBJS_B}

#Clean objects and lib
fclean: clean
	${RM} ${NAME}

#Reconstruct lib
re: fclean all

#used to create "false targets", avoiding errors
#declares that the following targets are NEVER a file, so it always find it directives inside the actual file
.PHONY: all clean fclean re bonus
