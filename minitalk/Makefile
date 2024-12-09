# Nome do executável
NAME_SERVER = server
NAME_CLIENT = client

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

# Diretório da Libft
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Arquivos fonte e objeto
SRCS_SERVER = server.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT = client.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Regra principal
all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

# Compilação da biblioteca Libft
$(LIBFT):
	@echo "Compilando a Libft..."
	@$(MAKE) -C $(LIBFT_DIR)

# Compilação do servidor
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	@echo "Compilando $(NAME_SERVER)..."
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

# Compilação do cliente
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	@echo "Compilando $(NAME_CLIENT)..."
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

# Limpeza dos arquivos objeto e binários
clean:
	@echo "Removendo arquivos objeto..."
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Limpeza completa
fclean: clean
	@echo "Removendo binários..."
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Recompilar do zero
re: fclean all

# Indica que as regras abaixo não são arquivos
.PHONY: all clean fclean re
