# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 16:45:30 by rsalles-          #+#    #+#              #
#    Updated: 2024/05/04 17:05:14 by rsalles-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
SRCDIR = .
OBJDIR = obj
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(TARGET)
