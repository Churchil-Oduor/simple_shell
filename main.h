#ifndef MAIN_H
#define MAIN_H

char *prepend(char *command);
void interactive_mode(char *file_name, char *const env_vars[]);
void non_interactive_mode(char *file_name, char *const env_vars[]);
char **generator(char *command);
int execute(char **args, char *const env_vars[]);

int total_array_length(char *str);
int _strlen(char *str);
int does_path_exist(char *str);
void free_args(char **args);

#endif
