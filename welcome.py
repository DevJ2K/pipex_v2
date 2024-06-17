# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    welcome.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 09:44:24 by tajavon           #+#    #+#              #
#    Updated: 2024/06/17 09:55:17 by tajavon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import subprocess
from my_signature.display_signature import display_signature

BHGREEN = "\033[1;32m"
BHYELLOW = "\033[1;33m"
BHWHITE = "\033[1;37m"
BHBLUE = "\033[1;34m"
BHCYAN = "\033[1;36m"
BHPINK = "\033[1;35m"
UNDERLINE = "\033[4;1;37m"
RESET = "\033[0m"

def main():
	# subprocess.run("clear", shell=True)
	display_signature()
	toggle = False
	with open("display_text/how_to_use", "r") as f:
		for line in f:
			for char in line:
				if (char == "5"):
					toggle = True
					print(f"{BHCYAN} ", end="")
				elif (char == "6"):
					toggle = True
					print(f" {UNDERLINE}", end="")
				elif (char == "7"):
					toggle = True
					print(f"{BHGREEN} ", end="")
				elif (char == "8"):
					toggle = True
					print(f"{BHBLUE} ", end="")
				elif (char == "9"):
					toggle = True
					print(f"{BHPINK} ", end="")
				elif (char == "0"):
					toggle = False
					print(f" {RESET}{BHWHITE}", end="")
				else:
					if toggle == False:
						print(f"{BHWHITE}{char}{RESET}", end="")
					else:
						print(f"{char}", end="")

if __name__ == "__main__":
	main()
