SRCDIR = src/

OBJDIR = obj/

INCLUDE = -Iinclude

CC = c++

SRCS = $(addprefix $(SRCDIR), \
		Bureaucrat.cpp \
		AForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		main.cpp)

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))
EXE = Bureaucrat_with_forms
FLAGS = -Wall -Werror -Wextra \
	-std=c++11
FLAGS += $(INCLUDE)

.PHONY: all clean fclean re bonus

all: $(OBJDIR) $(EXE)

$(OBJDIR):
	mkdir $(OBJDIR)

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
