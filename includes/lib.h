/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:27:58 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 17:22:18 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIB_H
#define LIB_H

//kütüphaneler
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>
# include <string.h>

#define CHILD 0
#define DOUBLE_QUOTE 2
#define SINGLE_QUOTE 1

//struct parselamak için
typedef struct	s_parse{
    char			*content;
    struct			s_parse	*next;
}				t_parse;

//genel verilerin tutulması için
typedef struct s_data{
    int		argc;
    char	**argv;
    char    **path;
    char	**envp;
    char    **export;
    char	*line;
    int     **fd;
    int     pipe_count;
    int		input_file;
    int		output_file;
    int		heredoc_cnt;
    int		syntax_flag;
    int     return_value;
    int		dbl;
    int		sng;
    t_parse	*parse;
}		t_data;

//fonksiyonlar
void	signal_function(void);
t_parse	*lstnew(char *content);
void	parser();
t_parse	*lstlast(t_parse *lst);
void	add_back(t_parse **lst, t_parse *new);
int		ft_strlen(const char *s);
char	*strjoin(char *s1, char *s2);
char	*substr(char *s, int start, int len);
void	ft_split(int n, int i);
void	reading_line();
void	addlist_substr(int i, int *n);
void	syntax_check(t_parse *parse);
int		multiple_pipes(t_parse *temp);
void	pre_trim(char *find);
int		syntax_redirection(char *str, char symbol);
int		strchar(char *s, int c);
int		strmatch(const char *s1, const char *s2);
void	clear_lst(t_parse **lst);
char	*str_dup(const char *s1);
char	**nav_redirection(char *content);
void	heredoc_list(t_parse *parse);
void	heredoc_str(char *str);
int		search(char *detect, char *found);
int		heredoc_file(char *str, int i);
int		ft_strcmp(char *s1, char *s2);
int	    equal_sign_index(char *str);
void	ft_putstr_fd(char *s, int fd);
void	change_data_input(int file);
void	ft_putendl_fd(char *s, int fd);
int		input_redirection(char *str, int i);
int		strrchar(char *s, int c);
int		append_redirection(char *str, int i);
void	change_data_output(int file, int append_flag);
int		output_redirection(char *str, int i);
char	*remove_redirection(char *str, char *new);
void	*ft_calloc(size_t count, size_t size);
char	*s2_strjoin(char *s1, char *s2);
char	*v2_substr(char *s, int start, int len);
char	*trim_quote(char *str, int i);
void	duplication(int fd_in, int fd_out);
char	*ft_strjoin(char *s1, char *s2);
char	**libft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	reset_struct(void);
int	    new_atoi(const char *s);
int	    ft_isalpha(int c);
void	free_command_db(char **command);
int     export_change_data(char* var_name, int equals_index);
int     change_data_env(char* var_name);
int	    chardb_len(char **db);
char	*ft_strdup(const char *s1);
void	re_free(void);


//Execute Fonksiyonları
void    nav_execute();
void	create_pipe_fd(void);
void	free_fd(void);
void    pipe_counter(t_parse *lst);
void    multi_command_execute(t_parse *lst);
void    one_command_execute();
void    nav_builtin(char **command);
int     builtin_check(char *command);
char    *find_path(char *command);
char    **get_path();
void    delete_quote(char **command);
void	close_pipe_fd(void);

//Builtins

int     builtin_check(char *command);
void    ft_pwd();
void    ft_echo(char **command);
void    ft_exit(char **command);
void    ft_cd(char **command);
char    *ft_getenv(char* var_name, int flag);

//Environment
void    create_envp(char **envp);
int     is_env_eq(char *var_name, char *env_content);
int     is_export_eq(char *var_name, char *env_content);
void    sort_export();
void	create_export();
void    ft_export(char **export_cmd);
void    write_export();
void	update_export(char *add_export);
void    ft_env();
void	add_env(char *env_cmd);
#endif
