# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 12:10:03 by bruperei          #+#    #+#              #
#    Updated: 2025/04/14 12:59:44 by bruperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Library name
NAME = libget_next_line.a

#Compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Create or update a static library
#r - replace existing files / c - creates libft.a if doesn't exist / s - create an index to the lib
AR = ar rcs

#Remove files
#rm - remove / f - forced
RM = rm -f

#Sources required (Main sources)
SRCS = get_next_line.c get_next_line_utils.c

#Bonus sources (Only included if `make bonus` is run)
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

#Mandatory objects (Main objects)
OBJS = ${SRCS:.c=.o}

#Bonus objects (Only included if `make bonus` is run)
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

#Standard rule to compile .c files to .o not linking (-c) the files
#$< - that part will be replaced by the file name (ex. ft_atoi.c) / ${<:.c=.o} - that one is the transformation of .c to .o
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#Creation of static lib with the mandatory objects
${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

#Compile bonus (Only when `make bonus` is run)
bonus: ${OBJS} ${BONUS_OBJS}
	${AR} ${NAME} ${OBJS} ${BONUS_OBJS}

#Standard compiling (Default target)
all: ${NAME}

#Clean objects (Including bonus objects)
clean:
	${RM} ${OBJS} ${BONUS_OBJS}

#Clean objects and lib (Including bonus objects)
fclean: clean
	${RM} ${NAME}

#Reconstruct lib (Including bonus objects)
re: fclean all

#used to create "false targets", avoiding errors
#declares that the following targets are NEVER a file, so it always find it directives inside the actual file
.PHONY: all clean fclean re bonus
