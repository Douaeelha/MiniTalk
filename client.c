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
 // #include "minitalk.h"

// void send_char(int pid, unsigned char c)
// {
//     int bi = 7; // Start from the most significant bit

//     while (bi >= 0)
//     {
//         // Extract the bit at position `bi`
//         if ((c >> bi) & 1)
//             kill(pid, SIGUSR1); // Send SIGUSR1 for '1'
//         else
//             kill(pid, SIGUSR2); // Send SIGUSR2 for '0'

//         usleep(100); // Small delay to avoid signal loss
//         bi--;
//     }
// }

// int main(int ac, char **av)
// {
//     if (ac != 3)
//     {
//         write(1, "Not enough arguments, try again with <PID> <MESSAGE>\n", 53);
//         return 1;
//     }

//     int pid = ft_atoi(av[1]); // Convert PID from string to int
//     int i = 0;

//     // Loop through each character in the message
//     while (av[2][i])
//     {
//         send_char(pid, av[2][i]); // Send character bit by bit
//         i++;
//     }

//     return 0;
// }
  