SRCDIR = src/

OBJDIR = obj/

CC = c++

SRCS = $(addprefix $(SRCDIR), \
		main.cpp)

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))
EXE = easyfind
FLAGS = -Wall -Werror -Wextra \
	-std=c++11 -MMD

DEPS = $(OBJS:.o=.d)

.PHONY: all clean fclean re bonus

all: $(OBJDIR) $(EXE)

print: FLAGS += -DPRINT_MORE_INFO
print: clean $(OBJDIR) $(EXE)
print:
	@echo compiled with print messages

$(OBJDIR):
	mkdir $(OBJDIR)

$(EXE) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(EXE)

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.cpp
		$(CC) $(FLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm $(EXE)
	rm -r $(OBJDIR)

re:	clean all
