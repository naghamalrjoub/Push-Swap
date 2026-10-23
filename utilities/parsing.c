#include "../header_files/pushswap.h"
#include "../header_files/libft.h"

int	isflage(char *s)
{
	if (!s)
		return (0);
	return (set_str(s) != NONE);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_strategy	set_str(char *s)
{
	if (ft_strcmp(s, "--simple") == 0)
		return (simple);
	if (ft_strcmp(s, "--medium") == 0)
		return (medium);
	if (ft_strcmp(s, "--complex") == 0)
		return (complex);
    if (ft_strcmp(s, "--adaptive") == 0)
		return (adaptive);
    if (ft_strcmp(s, "--bench") == 0)
        return (bench);
	return (NONE);
}

parsing init_r()
{
    parsing ret;
    ret.data = NULL;
    ret.error = 0;
    ret.size = 0;
    ret.str = NONE;
    return ret;
}

int checking(char **s,int size)
{
    int counter = 1;
    int num_flags = 0;
    while (counter < size && isflage(s[counter]))
    {
        num_flags++;
        counter++;
    }
    
    if (num_flags > 2 || counter >= size)
        return 0;

    while (counter < size)
    {
        if(!is_number(s[counter]))
            return 0;
        counter++;
    }
    return 1;
}

parsing	parsing_input(char **s, int size)
{
    parsing return_value = init_r();
    if (!checking(s,size))
    {
        return_value.error = 1;
        return(return_value);
    }
    return return_value;
}
