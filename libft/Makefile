# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 18:28:39 by nmattera          #+#    #+#              #
#    Updated: 2022/07/07 11:13:48 by nmattera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
SRCS =	ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c \
		ft_strmapi.c ft_memset.c \
		ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c \
		ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c \
		ft_substr.c ft_striteri.c \
		ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c \
		ft_putstr_fd.c ft_putnbr_fd.c \
		ft_putendl_fd.c ft_putchar_fd.c \
		ft_character.c ft_convert.c \
		ft_hexa.c ft_number.c \
		ft_pointer.c ft_printf.c \
		ft_string.c ft_unsigned.c \
		ft_lstadd_back.c ft_lstadd_front.c \
		ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c \
		ft_lstsize.c 

OBJS = ${SRCS:.c=.o}

CC		= gcc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}


all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		
re:		fclean all
