#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(1);
}

void	child_process(char **av, char **envp, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		ft_error("Error opening file in fork function\n");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execute(av[2], envp);
}

void	main_process(char **av, char **envp, int *fd)
{
	int	infile;

	infile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile == -1)
		ft_error("Error opening/creating file in main function\n");
	dup2(fd[0], STDIN_FILENO);
	dup2(infile, STDOUT_FILENO);
	close(fd[1]);
	execute(av[3], envp);
}

int main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	id;

	if(ac == 5)
	{
		if (pipe(fd) == -1)
			ft_error("Error creating pipe!\n");
		id = fork();
		if (id == -1)
			ft_error("Error creating Fork process!\n");
		if (id == 0)
			child_process(av, envp, fd);
		waitpid(id, NULL, 0);
		main_process(av, envp, fd);
	}
	else
		ft_error("Error, Invalid Arguments!\n");
	return(0);
}

//fd[0] = read();
//fd[1] = write();

// [13] Vai ler o (in-file) Ex: Makefile;

// [26] Vai criar o (out-file) Ex: a.out;

// STDOUT_FILENO = Estou a dizer ao dup2 para escrever a partir do fim do fd[1];
// STDIN_FILENO = Estou a dizer ao dup2 para ler desde o inicio do fd[0];

// 0644 = Permissoes de leitura e escrita;

// O_TRUNC = Limpa o ficheiro (out);
// O_CREAT = Cria o ficheiro;
// O_WRONLY = Para escrever no ficheiro;

// O_WRONLY Vai fazer sempre;

//Ex:
//av[0] = ./pipex
//av[1] = Makefile
//av[2] = cat
//av[3] = "wc -l"
//av[4] = out

// Ex: ./pipex file1 cmd1 cmd2 file2;