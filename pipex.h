#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

char	*path_find(char *cmd, char **evnp);
void	execute(char *av, char **envp);
void	ft_error(char *str);
void	child_process(char **av, char **envp, int *fd);
void	main_process(char **av, char **envp, int *fd);

#endif