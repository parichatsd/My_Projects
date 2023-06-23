/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaolim <pkaolim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:39:04 by pkaolim           #+#    #+#             */
/*   Updated: 2023/06/17 01:00:30 by pkaolim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}

//===================================================================

int	check_argv(char *arr)
{
	int i;

	i = 0;
	while(arr[i] != '\0')
	{
		if (!(*arr >= 1 && *arr <= 4))
			return (0);
		i++;
	}
	return (1);
}

int ft_strlen(char *arr)
{
    int len;
    int j;
    char    plain[50];

    j = 0;
    len = 0;
    while (arr[len] != '\0')
    {
        if (arr[len] != ' ')
        {
            plain[j] = arr[len];
            j++;
        }
        len++;
    }
    if (arr[len - 1] == ' ')
        return (0);
    return (j);
}

void spr_input(int (*row)[4] , int (*col)[4], char *input)
{
    int i;
    int j;

    i = -1;
    j = 0;
    while(++i < 8){
        if (i < 4)
            col[0][i%4] = ft_atoi(&input[j]);
        else
            col[1][i%4] = ft_atoi(&input[j]);
        j += 2;
    }

    i = -1;
    while (++i < 8)
    {
        if (i < 4)
            row[0][i%4] = ft_atoi(&input[j]);
        else
            row[1][i%4] = ft_atoi(&input[j]);
        j += 2;
    }
}

int main(int argc, char **argv)
{
    int len;
    // int i;
    // int j;
    int row[2][4];
    int col[2][4];

    len = (ft_strlen(argv[1]));
    printf("%d", len);
    // if (argc != 2 || (len != 16)|| check_argv(argv[1]))
    // {
    //     write(1, "error", 5);
    //     write(1, "\n", 1);
    //     return 1;
    // }
    // else
    // {
    //     spr_input(row, col, argv[1]);
    //     // for(int i = 0; i <4; i++)
    //     // {
    //     //     printf("%d",row[1][i]);
    //     // }
    // }
}
