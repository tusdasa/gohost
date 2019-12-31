CC := gcc
TRAGE := /bin/gethost
CCFLAG := -Wall
SRC := gethost.c
LIB= -lreadline

default:
	$(CC) $(CCFLAG) -o $(shell pwd)$(TRAGE) $(SRC) $(LIB)

.PHONY:clean
clean:
	rm -rf $(shell pwd)$(TRAGE)
.PHONY:test
test:
	.$(TRAGE)