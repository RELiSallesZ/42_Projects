CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

SRCS_CLIENT = client.c utils.c
SRCS_SERVER = server.c utils.c

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(PRINTF_LIB) $(CLIENT) $(SERVER)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(CLIENT): $(SRCS_CLIENT) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(PRINTF_DIR) -lftprintf

$(SERVER): $(SRCS_SERVER) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(PRINTF_DIR) -lftprintf

clean:
	$(MAKE) clean -C $(PRINTF_DIR)
	rm -f $(CLIENT) $(SERVER)

fclean: clean
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(CLIENT) $(SERVER)

re: fclean all
