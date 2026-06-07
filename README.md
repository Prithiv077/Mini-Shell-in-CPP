# Mini-Shell-in-CPP
A Unix shell implementation written in C, built from scratch. Supports core shell features including built-in commands, process execution, I/O redirection, pipes, background processes, and the source command.

Features
Built-in Commands
Executed directly in the shell process without forking:
CommandDescriptioncd [dir]Change current directorypwdPrint working directoryexitExit the shellechoPrint arguments to stdoutsource <file>Execute script in current shell context

cd and source must be builtins — they modify the shell's own state and cannot run in a child process.

Process Execution
External commands are run using fork() + exec():

fork() creates a child process
execvp() replaces the child with the target program
Parent waits with waitpid() for foreground processes

I/O Redirection
Redirect input and output using standard operators:
bashcommand > output.txt       # Redirect stdout to file
command < input.txt        # Redirect stdin from file
command >> output.txt      # Append stdout to file
Implemented using open(), dup2(), and close() on file descriptors.
Pipes
Connect processes so the output of one becomes the input of the next:
bashls | grep foo
cat file.txt | wc -l
Implemented using pipe() and dup2() to wire stdout → stdin across processes.
Background Processes
Run commands without blocking the shell:
bashcommand &
The shell forks the child and continues without calling waitpid(), allowing the next command to be entered immediately.
Source Command
Run a shell script in the current shell environment:
bashsource script.sh
Unlike normal execution, source does not fork — commands in the script run in the current process, so variable changes and cd calls affect the active shell session.

Build & Run
bash# Compile
gcc -o myshell shell.c

# Run
./myshell

System Calls Used
System CallPurposefork()Create child processexecvp()Execute external commandwaitpid()Wait for child to finishpipe()Create pipe between processesdup2()Redirect file descriptorsopen() / close()File operations for redirectionchdir()Underlying call for cdgetcwd()Underlying call for pwd
