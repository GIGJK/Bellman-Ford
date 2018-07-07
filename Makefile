all: compile

compile: BellFord.c
	@gcc BellFord.c -o Bellman-Ford
	@echo "\033[1;33mCompile\033[0;0m - \033[0;32msuccess.\033[0;0m"
