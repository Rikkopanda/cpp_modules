
SRCDIR = src/

OBJDIR = obj/

SRCS = $(addprefix $(SRCDIR),main.cpp \
	helper_functions.cpp \
	contacts_helper_functions.cpp \
	phone_book.cpp \
	contacts.cpp)

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))
EXE = phone_book
FLAGS = -Wall -Werror -Wextra \
	-std=c++98

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
	rm $(EXE)
	rm -r $(OBJDIR)

re:	clean all
