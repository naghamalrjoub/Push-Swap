# ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_ops
{
	int	p;
	int	s;
	int	ss;
	int	rot;
	int	revrot;
	int	rot_both;
	int	revrot_both;
}					t_ops;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	t_ops			op;
	size_t			size;
}					t_stack;

typedef enum e_strategy{
    simple = 1,
    medium = 2,
    complex = 3,
	adaptive = 4,
	NONE = -1
} t_strategy;

typedef struct s_parsing
{
	t_strategy	str;
	int			*data;
	int			size;
	int			error;
	int			is_bench;
}	parsing;

void		del_node(t_stack *s);
t_node		*add_new_node(t_stack *s, int content);
t_stack		*init_stack(void);
void		push(t_stack *s1, t_stack *s2);
void		swap(t_stack *s1);
void		rot(t_stack *s1);
void		revrot(t_stack *s1);
void		ra(t_stack *sa, int bench);
void		pa(t_stack *sa, t_stack *sb, int bench);
void		sa(t_stack *sa, int bench);
void		sb(t_stack *sb, int bench);
void		pb(t_stack *sb, t_stack *sa, int bench);
void		rb(t_stack *sb, int bench);
void		rra(t_stack *sa, int bench);
void		rrb(t_stack *sb, int bench);
void		ss(t_stack *sa, t_stack *sb, int bench);
void		rr(t_stack *sa, t_stack *sb, int bench);
void		rrr(t_stack *sa, t_stack *sb, int bench);
// parsing_fun
parsing	parsing_input(char **s, int size);
int checking(char **s,int size);
t_strategy	set_str(char *s);
int	is_number(char *s);
int	is_bench(char *s);
int	isflage(char *s);
int checking(char **s,int size);
t_strategy add_str(char **s,int *start);
int *add_data(char **s,int start,int size);
int isdup(int *data,int size);

#endif
