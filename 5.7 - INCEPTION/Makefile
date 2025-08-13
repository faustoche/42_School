export DOCKER_BUILDKIT=1

WP_DATA = /home/fcrocq/data/wordpress
DB_DATA = /home/fcrocq/data/mariadb

all: up

up:	build
	@mkdir -p $(WP_DATA)
	@mkdir -p $(DB_DATA)
	docker-compose -f ./srcs/docker-compose.yml up -d

down:
	docker-compose -f ./srcs/docker-compose.yml down

stop:
	docker-compose -f ./srcs/docker-compose.yml stop

start:
	docker-compose -f ./srcs/docker-compose.yml start

build:
	docker-compose -f ./srcs/docker-compose.yml build

clean:
	@echo "Cleaning up Docker resources"
	-@docker stop $$(docker ps -aq) 2>/dev/null || true
	-@docker rm $$(docker ps -aq) 2>/dev/null || true
	-@docker rmi -f $$(docker images -aq) 2>/dev/null || true
	-@docker volume rm $$(docker volume ls -q) 2>/dev/null || true
	-@docker network rm $$(docker network ls -q --filter type=custom) 2>/dev/null || true
	@echo "Docker cleanup completed!"

re: clean up

prune:	clean
	@docker system prune -a --volumes -f

# Bonus targets
logs-redis:
	docker logs redis

logs-ftp:
	docker logs ftp

logs-static:
	docker logs static-site

logs-adminer:
	docker logs adminer

test-ftp:
	@echo "Test FTP connection:"
	@echo "ftp://ftpuser:ftppass@localhost:21"

test-adminer:
	@echo "Adminer URL: https://adminer.fcrocq.42.fr"

test-static:
	@echo "Static site URL: https://static.fcrocq.42.fr"

status:
	@echo "=== INCEPTION PROJECT STATUS ==="
	@docker ps --format "table {{.Names}}\t{{.Status}}\t{{.Ports}}"
