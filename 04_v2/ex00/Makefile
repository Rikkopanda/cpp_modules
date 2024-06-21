SRCDIR = src/

OBJDIR = obj/

CC = g++

SRCS = $(addprefix $(SRCDIR), \
		main.cpp \
		Animal.cpp)

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))
EXE = animals
FLAGS = -Wall -Werror -Wextra \
	-I ./include

.PHONY: all clean fclean re bonus

all: $(OBJDIR) $(EXE)

$(OBJDIR):
	mkdir $(OBJDIR)

$(EXE) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(EXE)

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.cpp
		$(CC) -c -g $(FLAGS) -MMD -MP $< -o $@

-include $(SRCS:.cpp=.d)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm $(EXE)
	rm -r $(OBJDIR)

re:	clean all
