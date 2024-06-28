SRCDIR = src/

OBJDIR = obj/

CC = c++

SRCS = $(addprefix $(SRCDIR), \
		main.cpp \
		Data.cpp \
		Serializer.cpp)

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))
EXE = yes
# FLAGS = -Wall -Werror -Wextra \
	-std=c++11

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
