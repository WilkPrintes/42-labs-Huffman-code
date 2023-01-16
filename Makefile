NAME_EN			:= encoder

NAME_DE			:= decoder

CC				:= gcc

CCFLAGS			:= -Wall -Wextra -Werror

HEADER_DIR		:= ./header/

INCLUDE			:=	$(foreach directory, $(HEADER_DIR), -I $(directory))

SRC_ENCODER		:= ./src/encoder/

SRC_DECODER		:= ./src/decoder/

ENCODER_FILE	:=	encoder.c code.c dictionary.c list.c table.c tree.c compress.c \
				encoder_utils.c

DECODER_FILE	:= decoder.c

ENCODER			:= $(wildcard $(addprefix $(SRC_ENCODER), $(ENCODER_FILE)))

DECODER			:= $(wildcard $(addprefix $(SRC_DECODER), $(DECODER_FILE)))

all: $(NAME_EN) $(NAME_DE)

$(NAME_EN): $(ENCODER)
	@$(CC) -g $(CCFLAGS) $(ENCODER) -o $@ $(INCLUDE)
	@echo "\033[0;32mLabs (>‿◠)\033[0m"

$(NAME_DE): $(DECODER)
	@$(CC) -g $(CCFLAGS) $(DECODER) -o $@ $(INCLUDE)
	@echo "\033[0;32mLabs (>‿◠)\033[0m"

fclean: clean
	@rm -rf $(NAME_EN)
	@rm -rf $(NAME_DE)
	@rm -rf *.42
	@echo "\033[0;31mLabs deleted (ㆆ_ㆆ)\033[0m"

clean:
	@rm -rf *.o

re: fclean all

$(OBJ_DIR):
	@mkdir -p $@

norma:
	@norminette ./

.PHONY: all fclean re