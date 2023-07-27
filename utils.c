#include "pipex.h"

char	*path_find(char *cmd, char **evnp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*part_path;

	i = 0;
	while (ft_strnstr(evnp[i], "PATH", 4) == 0)
		i++;
	path = ft_substr(evnp[i], 5, ft_strlen(evnp[i]));
	paths = ft_split(path, ':');
	free (path);
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free (paths);
	return (0);
}

void	execute(char *av, char **envp)
{
	int		i;
	char	*path;
	char	**cmd;

	i = 0;
	cmd = ft_split(av, ' ');
	path = path_find(cmd[0], envp);
	if (!path)
	{
		while (cmd[i])
		{
			free (cmd[i]);
			i++;
		}
		free(cmd);
		ft_error("Error Path");
	}
	if (execve(path, cmd, envp) == -1)
		ft_error("Error to execute execve");
}

// cmd = comando a executar;

// [11] Vamos procurar o Path no ENVP;

// [13] A string "path" vai ser o PATH inteiro a partir do "PATH=";

// [14] Vamos dividir o path para o (PATHS) sempre que encontrarmos ":";
// E vamos retirar os ":" porque e o que divide os ficheiros;

// [17 - 21] Vamos voltar a juntar o PATH, e no lugar dos ":" vamos meter uma "/";
// E vamos juntar o (cmd) ao final do PATH;

// [22] Vamos verificar se o (path) existe;
// Se existir vamos retornar o (path);

// Se nao existir passamos para o proximo path e verificamos outra vez ate encontrar;
// Se nao encontrar nada vamos dar free a tudo e vamos dar erro;

// F_OK e uma FLAG que verifica se o ficheiro existe;
// access() e uma funcao que verifica se o ficheiro existe;
// F_OK pertence a funcao access();



// [41] = Vai entrar aqui sempre, e vai dar split ao (av) em caso de "ls -l";



/*
path = /home/tmiguel-/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:
/usr/bin:/sbin:/bin:/usr/games:/usr/local/

paths	= paths[0] = /home/tmiguel-/.local/bin

		= paths[1] = /usr/local/sbin

		= paths[2] = /usr/local/bin

		= paths[3] = /usr/sbin

		= paths[4] = /usr/bin
*/