
SRCDIR = src/

OBJDIR = obj/

SRCS = $(addprefix $(SRCDIR),main.cpp \
	Contacts_helper_functions.cpp \
	PhoneBook.cpp \
	Contacts.cpp \
	strings_f.cpp)

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))
EXE = open_phonebook
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
