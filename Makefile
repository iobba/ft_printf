SRCS			= ft_putchar.c ft_putnbr.c ft_putnbr_u.c ft_putnbr_hex.c ft_putnbr_p.c ft_putstr.c ft_printf.c

NAME			= libftprintf.a

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

AR				= ar rc 

OBJS			= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
