NAME=		abstractVM

CXX=		g++

CC=		$(CXX)

OBJ=		core/main.o \
		src/Memory.o \
		src/Io.o \
		src/busMem.o \
		src/Bios.o \
		src/Chipset.o \
		src/MotherBoard.o \
		src/Operand.o \
		src/ChipsetCpu.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
