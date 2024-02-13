CSFlags += -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all:
	gcc $(shell find src/*.c) $(shell find csfml/*.c) \
		-iquote./csfml -Wall -Wextra -std=gnu17 -g \
		$(CSFlags) -o bruh


.Phony:
	all
