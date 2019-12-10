# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mconti <mconti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/02 14:00:49 by mconti            #+#    #+#              #
#    Updated: 2018/06/29 13:09:21 by mconti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN	= \x1b[32m

WHITE	= \x1b[0m


all: colleen grace sully

fclean: colleenClean graceClean sullyClean

re: fclean all


# Colleen
colleenComp:
	@echo "${GREEN}Compile: ${WHITE}Colleen"
	cd Colleen; clang -Wall -Wextra -Werror -o Colleen Colleen.c

colleenTest:
	@echo "${GREEN}Test: ${WHITE}Colleen"
	cd Colleen; ./Colleen > tmp_Colleen; diff tmp_Colleen Colleen.c
	@echo ""

colleen: colleenComp colleenTest

colleenClean:
	rm Colleen/Colleen Colleen/tmp_Colleen


# Grace
graceComp:
	@echo "${GREEN}Compile: ${WHITE}Grace"
	cd Grace; clang -Wall -Wextra -Werror -o Grace Grace.c

graceTest:
	@echo "${GREEN}Test: ${WHITE}Grace"
	cd Grace; ./Grace; diff Grace.c Grace_kid.c
	@echo ""

grace: graceComp graceTest

graceClean:
	rm Grace/Grace Grace/Grace_kid.c

# Sully
sullyComp:
	@echo "${GREEN}Compile: ${WHITE}Sully"
	@cd Sully; mkdir -p children
	cd Sully/children; clang -Wall -Wextra -Werror ../Sully.c -o Sully

sullyTest:
	@echo "${GREEN}Test: ${WHITE}Sully"
	cd Sully/children; ./Sully
	cd Sully/children; ls -al | grep Sully | wc -l
	cd Sully/children; diff ../Sully.c Sully_0.c; diff Sully_3.c Sully_2.c || true
	@echo ""


sully: sullyComp sullyTest

sullyClean:
	rm -rf Sully/children

