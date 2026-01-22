*This project has been created as part
of the 42 curriculum by jemonthi.*

# Description

Pipex is a 42 project that expect you to **create a pipe**. 

You will have **5 arguments** : 

- argv[0] = your executable "pipex".
- argv[1] = **file1** which is the infile.
- argv[2] = **cmd1** which is the first command to execute.
- argv[3] = **cmd2** which is the second command to execute.
- argv[4] = **file2** which is the outfile.

cmd1 and cmd2 are **shell commands** with their parameters.

For example : "ls -l" or "wc -l"


The goal is to read on file1, execute cmd1 from file1, create a pipe and fill it with the result of cmd1, cmd2 will read on the pipe the result of cmd1, and then execute the cmd2 from the pipe to output the result inside file2.

**file1 must EXIST**, otherwise an error system will be shown on the terminal.

If file2 doesn't exist, he will be created.

If cmd1 or cmd2 doesn't exist, an error system will be shown on the terminal.

# Instructions

To compile all the files just run **make** at the root of the repository.

> make

It will create the executable "pipex", to test it just type like the example below :

> ./pipex file1 cmd1 cmd2 file2

It must behave exactly like the following shell command :

> $> < file1 cmd1 | cmd2 > file2

Here are some example you can try :

>  ./pipex infile "ls -l" "wc -l" outfile

> ./pipex infile "grep a1" "wc -w" outfile


# Ressources

Here are some documentations i have read/watched during the project :

- http://manpagesfr.free.fr/man/man2/dup.2.html
- https://www.rozmichelle.com/pipes-forks-dups/
- https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY