# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 01:06:00 by tajavon           #+#    #+#              #
#    Updated: 2024/06/16 02:15:36 by tajavon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from my_signature.display_signature import display_signature
import subprocess

BHGREEN = "\033[7;32m"
BHYELLOW = "\033[1;33m"
BHWHITE = "\033[1;37m"
BHBLUE = "\033[1;34m"
BHCYAN = "\033[7;36m"
BHPINK = "\033[1;35m"
UNDERLINE = "\033[4;1;37m"
RESET = "\033[0m"

def ctrl_exit():
	print("Signal catch, exit !")
	exit()
	pass

def main():
	with open("display_text/guide_using") as f:
		for line in f:
			print(line, end="")

	try:
		infile = input("Write input file => ")
		if (len(infile) == 0):
			raise SyntaxError()
		outfile = input("Write output file => ")
		if (len(outfile) == 0):
			raise SyntaxError()
	except (KeyboardInterrupt, EOFError):
		ctrl_exit()
	except SyntaxError:
		print(f"{BHPINK}Empty input detected !{RESET}")
		exit()

	all_cmds = [
		"cat -e",
		"ls -l"
	]
	i = 1
	print("You need to write 2 commands minimum. Then make a signal to stop or run.")
	try:
		while(True):
			cmd = input(f"Command n°{i} => ")
			all_cmds.append(cmd)
			i += 1
	except (KeyboardInterrupt, EOFError):
		if (len(all_cmds) < 2):
			print("Invalid number of commands.")
			exit()

	for cmd in all_cmds:
		cmd = f"'{cmd}'"

	commands = " ".join(all_cmds)
	running_command = f"./pipex_bonus {infile} {commands} {outfile}"
	subprocess.run(running_command, shell=True)
	# print(running_command)

if __name__ == "__main__":
	subprocess.run("make bonus", shell=True)
	display_signature()
	main()
