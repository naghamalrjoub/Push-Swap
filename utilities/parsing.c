#include "../header_files/pushswap.h"
#include "../header_files/libft.h"

int	is_bench(char *s)
{
	return (ft_strcmp(s, "--bench") == 0);
}

int	isflage(char *s)
{
	if (!s)
		return (0);
	return (set_str(s) != NONE || is_bench(s));
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
	return (NONE);
}

parsing init_r()
{
    parsing ret;
    ret.data = NULL;
    ret.error = 0;
    ret.size = 0;
    ret.str = adaptive;
    ret.is_bench = 0;
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
    
    if ( (num_flags > 2 || counter >= size ) || (2 < size && is_bench(s[2])) )
        return 0;

    while (counter < size)
    {
        if(!is_number(s[counter]))
            return 0;
        counter++;
    }
    return 1;
}

t_strategy add_str(char **s,int *start)
{
    int counter = *start;
    int num_flags = 0;
    t_strategy ret = adaptive;

    while (isflage(s[counter]))
    {
        ret = set_str(s[counter]);
        counter++;
    }
    *start =  counter;
    return ret;
}

int *add_data(char **s,int start,int size)
{
    int *ret = malloc(sizeof(int) * size);
    if (!ret)
        return NULL;
    int counter = 0;
    while (counter < size)
    {
        ret[counter] = ft_atoi(s[start + counter]);
        counter++;
    }
    return (ret);
}

int isdup(int *data,int size)
{ 
    //                              ||    (*_*)    || <-- guess who           
    //ma ba3araf gheer hay al algho ||  /(     )\  || <-- the first letter is sanad
    //                              ||     - -     ||
    int i = 0;
    int j = 0;
    while (i < size)
    {
        j = i + 1;
        while ( j < size)
        {
            if (data[i] == data[j])
                return 1;
           j++; 
        }
        i++;
    }
    return 0;
}

parsing	parsing_input(char **s, int size)
{

    parsing return_value = init_r();
    if (!checking(s,size))
    {
        return_value.error = 1;
        return(return_value);
    }
    int i = 1;
    if (is_bench(s[i]))
    {
        return_value.is_bench = 1;
        i++;
    }
    return_value.str = add_str(s,&i);
    return_value.size = size - i;
    return_value.data = add_data(s,i,return_value.size);
    return_value.error = isdup(return_value.data,return_value.size);
    return return_value;
}
