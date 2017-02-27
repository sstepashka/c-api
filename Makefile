PROG = main
SRCS = 	main.c \
		object/ai_object.c \
		object/ai_object_internal.c \
		vector/ai_vector.c \
		any_object/ai_any_object.c

INCLUDES =

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -std=c99 -I./
LDFLAGS =

OBJS   = $(SRCS:.c=.o)
DEPS   = $(SRCS:.c=.d)

.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

.PHONY: clean cleaner
clean:
	rm -f $(OBJS) $(DEPS)

cleaner: clean
	rm -rf $(PROG)
