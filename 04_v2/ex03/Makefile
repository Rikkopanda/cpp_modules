EXE = animals

SRCDIR = src/

OBJDIR = obj/

CC = g++

SRCS = $(addprefix $(SRCDIR), \
		main.cpp \
		AMateria.cpp \
		ICharacter.cpp \
		Character.cpp \
		MateriaSource.cpp \
		IMateriaSource.cpp \
		Cure.cpp \
		Ice.cpp)

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))

PRINT_VAL = 0

FLAGS = -I ./include \
	 -g -Wall -Werror -Wextra \
	 -DPRINT_ALL=$(PRINT_VAL)


.PHONY: all clean fclean re bonus

all: $(OBJDIR) $(EXE)

$(OBJDIR):
	mkdir $(OBJDIR)

$(EXE) : $(OBJS)
	$(CC) $(FLAGS)  $(OBJS) -o $(EXE)

	@echo print bool = $(PRINT_VAL)


$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.cpp
		$(CC) -c -g $(FLAGS) -MMD -MP $< -o $@

-include $(SRCS:.cpp=.d)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm $(EXE)
	rm -r $(OBJDIR)

re:	clean all
