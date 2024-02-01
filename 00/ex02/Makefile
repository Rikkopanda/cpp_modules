
SRCDIR = src/

OBJDIR = obj/

SRCS = $(addprefix $(SRCDIR), \
	Account.cpp \
	tests.cpp)

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))
EXE = out
FLAGS = -Wall -Werror -Wextra \
	#-std=c++98

.PHONY: all clean fclean re bonus

all: $(OBJDIR) $(EXE)

$(OBJDIR):
	mkdir $(OBJDIR)

$(EXE) : $(OBJS)
	g++ $(FLAGS) $(OBJS) -o $(EXE)

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.cpp
		g++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -r $(OBJDIR)
	rm $(EXE)

re:	clean all
