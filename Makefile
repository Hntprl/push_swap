NAME = push_swap
NAME_BONUS = checker
RM = rm -f
CFLAGS = -Wextra -Wall -Werror
CC = cc

SRC = Mandatory/ft_split.c Mandatory/libft_funcs.c Mandatory/check_inp.c Mandatory/lincked_list.c \
	Mandatory/lincked_list2.c Mandatory/min_max.c Mandatory/opirations.c Mandatory/push_swap.c \
	Mandatory/sorting.c

BSRC = Bonus/checker_bonus.c Bonus/check_inp.c Bonus/get_next_line.c Bonus/ft_split.c \
	Bonus/libft_funcs.c Bonus/libft_funcs2.c Bonus/lincked_list2.c Bonus/lincked_list.c Bonus/list_fill.c \
	Bonus/opirations.c

OSRC = $(SRC:.c=.o)
OBSRC = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)
	$(CC) $(CFLAGS) $(OSRC) -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBSRC)
	$(CC) $(CFLAGS) $(OBSRC) -o $@

clean:
	$(RM) $(OSRC) $(OBSRC)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all bonus
