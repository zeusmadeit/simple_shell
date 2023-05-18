#ifndef MAIN_H
#define MAIN_H

/** header include section*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

/* Structures and global variables */
extern char **environ;

/* Definitions and Function Prototypes*/
#define LIMIT 256
#define MAXLINE 1024
int	_putchar(char c);
void print_number(int n);
int	_print_str(char *str);
void	welcomeScreen();
int changeDirectory(char* arg);
unsigned int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *concat(const char *str1, const char *str2);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(char *s, char c);
void print_env(void);
int check_built_ins(char *buffer, char *token);
void free_all(char *buffer, char **commands, char *heap_token);
char **input_tokens(char *token, char *buffer);

/* Main Driving Functions Definitions */
char *find_inPath(char **token);
char **store_paths(void);
int	runCmd(char **tokens);
int inter_shell(void);
int non_inter_shell(int argc, char *argv[]);
int non_inter_piped(char *argv);
int process_line(char **buffer, size_t *line_size, int *count);
void child_exe(char **cmnds, char *argv, int count);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
