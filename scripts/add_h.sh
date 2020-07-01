#!/usr/bin/env bash


sed -i '' -E $'1s/^/# **************************************************************************** #\\\n/' Makefile
sed -i '' -E $'2s/^/#                                                                              #\\\n/' Makefile
sed -i '' -E $'3s/^/#                                                         :::      ::::::::    #\\\n/' Makefile
sed -i '' -E $'4s/^/#    Makefile                                           :+:      :+:    :+:    #\\\n/' Makefile
sed -i '' -E $'5s/^/#                                                     +:+ +:+         +:+      #\\\n/' Makefile
sed -i '' -E $'6s/^/#    By: cchieko <marvin@42.fr>                     +#+  +:+       +#+         #\\\n/' Makefile
sed -i '' -E $'7s/^/#                                                 +#+#+#+#+#+   +#+            #\\\n/' Makefile
sed -i '' -E $'8s/^/#    Created: 2020\/06\/06 20:35:56 by cchieko           #+#    #+#              #\\\n/' Makefile
sed -i '' -E $'9s/^/#    Updated: 2020\/06\/07 15:51:29 by cchieko          ###   ########.fr        #\\\n/' Makefile
sed -i '' -E $'10s/^/#                                                                              #\\\n/' Makefile
sed -i '' -E $'11s/^/# **************************************************************************** #\\\n/' Makefile

sed -i '' -E 's/FLAGS = -Wall -Wextra -Werror -g/FLAGS = -Wall -Wextra -Werror/' Makefile

exit 0
