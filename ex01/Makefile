

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
EXE = out
FLAGS = #-Wall -Werror -Wextra \
	-std=c++98

.PHONY: all clean fclean re bonus

all: $(EXE)

$(EXE) : $(OBJS)
	g++ $(FLAGS) $(OBJS) -o $(EXE)

$(OBJS): %.o: %.cpp
		g++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm (EXE)

re:	clean all
