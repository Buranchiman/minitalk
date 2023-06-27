#####################################MINITALK#####################################

SERVNAME = server
CLIENTNAME = client

#####################################SRCS########################################

PATH_SRCS	=	srcs/

SERVS	+=	server.c

CLIENT	+= client.c

vpath	%.c	$(PATH_SRCS)

PATH_SRCS_BONUS	=	srcs_bonus/

SRCS_BONUS	+=	main_bonus.c

vpath	%.c	$(PATH_SRCS_BONUS)

###################################OBJS#########################################

PATH_OBJS	=	objs
OBJSSERV	=	$(patsubst	%.c,	$(PATH_OBJS)/%.o,	$(SERVS))
OBJSCLIENT	=	$(patsubst	%.c,	$(PATH_OBJS)/%.o,	$(CLIENT))
MAIN	=	$(patsubst	%.c,	$(PATH_OBJS)/%.o,	main.c)

PATH_OBJS_BONUS	=	objs_bonus
OBJS_BONUS	=	$(patsubst	%.c,	$(PATH_OBJS_BONUS)/%.o,	$(SRCS_BONUS))

################################COMPILATION####################################

INCLUDE	=	-Ilibft/includes	-Iinclude -g

LIBFT	=	libft/libft.a

CFLAGS	=	-Wall	-Wextra	-Werror

##################################RULES#######################################

all:		$(CLIENTNAME) $(SERVNAME)


$(SERVNAME): $(LIBFT)	$(OBJSSERV)
	$(CC)	$(CFLAGS) $(OBJSSERV) -o	$(SERVNAME)	$(INCLUDE)	$(LIBFT)

$(CLIENTNAME): $(LIBFT)	$(OBJSCLIENT)
	$(CC)	$(CFLAGS) $(OBJSCLIENT) -o	$(CLIENTNAME)	$(INCLUDE)	$(LIBFT)

$(LIBFT):
	${MAKE}	-sC	libft

$(OBJSCLIENT):	$(PATH_OBJS)/%.o:%.c Makefile
	mkdir	-p	$(PATH_OBJS)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@	$(INCLUDE)

$(OBJSSERV):	$(PATH_OBJS)/%.o:%.c Makefile
	mkdir	-p	$(PATH_OBJS)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@	$(INCLUDE)

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(OBJS)	$(OBJS_BONUS)
	$(CC)	$(CFLAGS)	$(OBJS)	$(OBJS_BONUS) -o	$(NAME_BONUS) $(INCLUDE)	$(LIBFT)

$(OBJS_BONUS):	$(PATH_OBJS_BONUS)/%.o:%.c Makefile
	mkdir	-p	$(PATH_OBJS_BONUS)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@	$(INCLUDE)

clean:
	rm	-rf	$(PATH_OBJS)
	rm	-rf	$(PATH_OBJS_BONUS)

fclean:	clean
	rm	-rf	$(NAME)
	rm	-rf	$(NAME_BONUS)
	${MAKE}	fclean -sC	libft

re:	fclean
	${MAKE}

malloc_test: $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} libft/libft.a -L. -lmallocator

.PHONY:	all	libft	clean	fclean	re