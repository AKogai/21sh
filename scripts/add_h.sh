#!/usr/bin/env bash


sed -i '1s/^/# **************************************************************************** #\n/' Makefile
sed -i '2s/^/#                                                                              #\n/' Makefile
sed -i '3s/^/#                                                         :::      ::::::::    #\n/' Makefile
sed -i '4s/^/#    Makefile                                           :+:      :+:    :+:    #\n/' Makefile
sed -i '5s/^/#                                                     +:+ +:+         +:+      #\n/' Makefile
sed -i '6s/^/#    By: cchieko <marvin@42.fr>                     +#+  +:+       +#+         #\n/' Makefile
sed -i '7s/^/#                                                 +#+#+#+#+#+   +#+            #\n/' Makefile
sed -i '8s/^/#    Created: 2020\/06\/06 20:35:56 by cchieko           #+#    #+#              #\n/' Makefile
sed -i '9s/^/#    Updated: 2020\/06\/07 15:51:29 by cchieko          ###   ########.fr        #\n/' Makefile
sed -i '10s/^/#                                                                              #\n/' Makefile
sed -i '11s/^/# **************************************************************************** #\n/' Makefile

sed -i 's/FLAGS = -Wall -Wextra -Werror -g/FLAGS = -Wall -Wextra -Werror/' Makefile

exit 0
