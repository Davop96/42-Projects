COMPOSE_FILE = srcs/docker-compose.yml	# Define path of file docker-compose.yml

# COLOURS
BLUE			= \033[94m
CYAN			= \033[36m
YELLOW			= \033[33m
RESET			= \033[0m

up: $(COMPOSE_FILE)	# Building docks
	@ printf "${YELLOW}Uploading inception.${RESET}\n"
	@ docker-compose -f $(COMPOSE_FILE) up --build -d
	@ printf "${CYAN}Inception succesfully uploaded!${RESET}\n"
	@ $(MAKE) --no-print-directory Banner

down:	# Stop and delete docks
	@ printf "${YELLOW}Stopping inception.${RESET}\n"
	@ docker-compose -f $(COMPOSE_FILE) down
	@ printf "${CYAN}Inception succesfully stopped!${RESET}\n"

.SILENT: all clean fclean re up Banner

all: up

clean:
	@printf "${YELLOW}Cleaning inception.${RESET}\n"
	@ docker-compose -f $(COMPOSE_FILE) down -v --remove-orphans
	@ docker system prune -f --volumes
	@printf "${CYAN}Inception cleaned.${RESET}\n"
	
fclean: clean
	@printf "${YELLOW}Removing inception.${RESET}\n"
	-@docker-compose -f $(COMPOSE_FILE) stop $$(docker ps -qa) 2>/dev/null || true
	-@docker rm $$(docker ps -qa) 2>/dev/null || true
	-@docker rmi -f $$(docker images -qa) 2>/dev/null || true
	-@docker volume rm $$(docker volume ls -q) 2>/dev/null || true
	-@docker network rm $$(docker network ls -q) 2>/dev/null || true
	@printf "${CYAN}Inception removed.${RESET}\n"
	
re: fclean all

Banner:
	@printf "${BLUE}\n-------------------------------------------------------------\n${RESET}\n"
	@printf "${YELLOW}\n\t\t Project created by: ${RESET}\n"
	@printf "\n"
	@printf "▓█████▄  ▄▄▄▄    ▒█████   ██░ ██  ▒█████ ▓██   ██▓ ▒█████  \n"
	@printf "▒██▀ ██▌▓█████▄ ▒██▒  ██▒▓██░ ██▒▒██▒  ██▒▒██  ██▒▒██▒  ██▒\n"
	@printf "░██   █▌▒██▒ ▄██▒██░  ██▒▒██▀▀██░▒██░  ██▒▒██ ██░▒██░  ██▒\n"
	@printf "░▓█▄   ▌▒██░█▀  ▒██   ██░░▓█ ░██ ▒██   ██░░▐██▓░▒██   ██░\n"
	@printf "░▒████▓ ░▓█  ▀█▓░ ████▓▒░░▓█▒░██▓░ ████▓▒░░██▒▓░░ ████▓▒░\n"
	@printf "▒▒▓  ▒ ░▒▓███▀▒░ ▒░▒░▒░  ▒ ░░▒░▒░ ▒░▒░▒░   ██▒▒▒ ░ ▒░▒░▒░\n"
	@printf "░ ▒  ▒ ▒░▒   ░   ░ ▒ ▒░  ▒ ░▒░ ░  ░ ▒ ▒░ ▓██ ░▒░   ░ ▒ ▒░\n"
	@printf "░ ░  ░  ░    ░ ░ ░ ░ ▒   ░  ░░ ░░ ░ ░ ▒  ▒ ▒ ░░  ░ ░ ░ ▒  \n"
	@printf "░     ░          ░ ░   ░  ░  ░    ░ ░  ░ ░         ░ ░  \n"
	@printf "░            ░                           ░ ░              \n\n"
	@printf "${BLUE}\n-------------------------------------------------------------\n${RESET}\n"

.PHONY: all down clean fclean re Banner
