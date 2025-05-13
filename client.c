/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:33:03 by delhajou          #+#    #+#             */
/*   Updated: 2025/03/27 19:38:22 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int bi;
int main(int ac, char **av)
{
    int i;
    
    i = 0;
   if (ac != 3)
    write(1,"Not enough arguments, try again with <PID> <MESSAGE>\n",53);
    int id = ft_atoi(av[1]);
    while (av[2][i])
    {
        bi = 7;
        while(bi >= 0)
        {
            int sig = (av[2][i] >> bi) && 1;
            if(sig ==  1)
                kill(id, SIGUSR1);
            else
                kill(id, SIGUSR2);
            usleep(100);
            bi--;
        }
        i++;
    }
} 
