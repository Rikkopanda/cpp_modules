SRCDIR = src/

OBJDIR = obj/

CC = c++

SRCS = $(addprefix $(SRCDIR), \
		main.cpp \
		Fixed.cpp \
		bsp.cpp \
		Point.cpp)

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))
EXE = numbers
FLAGS = -I ./include \
	-Wall -Werror -Wextra

.PHONY: all clean fclean re bonus

all: $(OBJDIR) $(EXE)

$(OBJDIR):
	@if test -d $(OBJDIR); then echo $(OBJDIR) exists; \
	else mkdir $(OBJDIR); \
	fi

$(EXE) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(EXE)

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm $(EXE)
	rm -r $(OBJDIR)

re:	clean all
