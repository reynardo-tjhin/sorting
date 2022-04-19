#!/bin/bash

printf "+----------------------------------------------+\n"
printf "| Generating data and Starting the Analysis... |\n"

gcc -Wall -Werror -fsanitize=address,leak sort_positive_integers.c -o sort_positive_integers -lm

printf "| Finish Compiling...                          |\n"

./sort_positive_integers
