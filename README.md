# Simple Shell Project
This repo contains the simple shell project.
It is a simple implementation of the Thompson-shell that gets invoked when you enter the command 'sh' in your terminal.

## Interactive and non-interactive mode
Like the Thompson shell, the simple_shell features both the interactive and non-interactive mode.

## How do I test the simple shell
Make sure you have gcc compiler installed in your machine.
1. Clone the simple-shell repo in your terminal.
2. Compile the project using the command
	 
	 
	 
	    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
3. After successful compilation, call the interactive mode using the command
        
		./hsh
4. Also you can test the non-interactive mode using the syntax,
    
	  
	  
	    echo "Enter your command here" | ./hsh

# Limitations
The simple-shell's ability to handle file inputs and exit status functionality has not been implemented. Regardless the simple-shell features a large facet of the Thompson-shell's functionality.

Project done and compiled by,

Holland Nyadimo, < naftaliholland01@gmai.com >,

Churchil Okech < churchilokechoduor@gmail.com >
