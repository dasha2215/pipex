# Pipex

## Description
Pipex is a project that mimics the behavior of the shell pipeline (`|`). It allows you to connect the output of one program to the input of another, enabling powerful and flexible data processing directly from the command line. This project is written in C and is designed to provide a deeper understanding of UNIX mechanisms, particularly pipes and process management.

## Features
- Execute shell commands in sequence with piped input/output.
- Handle multiple commands as input.
- Support for various standard library functions including `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`.
- Custom error handling to ensure the program does not quit unexpectedly.
- Memory management to prevent leaks.

## Usage
To use pipex, compile the project using the provided Makefile and then run the executable with the following syntax:

```sh
./pipex file1 cmd1 cmd2 file2
```

- `file1`: Input file.
- `cmd1`: First command to execute.
- `cmd2`: Second command to execute.
- `file2`: Output file.

The program will behave like the following shell command:

```sh
< file1 cmd1 | cmd2 > file2
```

### Examples
Here are some examples of how to use pipex:

```sh
./pipex infile "ls -l" "wc -l" outfile
```
This should behave like:
```sh
< infile ls -l | wc -l > outfile
```

```sh
./pipex infile "grep a1" "wc -w" outfile
```
This should behave like:
```sh
< infile grep a1 | wc -w > outfile
```

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

Thank you for checking out pipex! Happy piping!
