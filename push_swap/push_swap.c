/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:04:40 by sopperma          #+#    #+#             */
/*   Updated: 2024/05/13 10:04:41 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft/libft.h"
void print_list(int *a, int len)
{
    int c;

    c = 0;
    while (c < len)
        ft_putnbr_fd(a[c++], 1);
}
void sx(int *a, int len)
{
    int c;

    if (len < 2)
        return ;
    c = a[0];
    a[0] = a[1];
    a[1] = c;
}
void ss(int *a, int *b)
{
    sx(a);
    sx(b);
}
void pa(int *a, int *b)
{
    
}
void pb(int *a, int *b)
{
    
}
void rx(int *a)
{
    
}
void rr(int *a, int *b)
{
   rx (a);
   rx (b);
}
void rrx(int *a)
{
    
}
void rrr(int *a, int *b)
{
    rrx(a);
    rrx(b);
}


int main (int ac, char **av)
{
    int *a;
    int *b;
    int c;

    a = malloc((ac - 1)*sizeof(int));
    b = malloc((ac - 1)*sizeof(int));
    if (!a || !b)
        return (0);
    c = 1;
    while (c < ac)
    {
        a[c-1] = ft_atoi(av[c]);
        c++;
    } 
    print_list(a, ac -1);
    return (0);
}