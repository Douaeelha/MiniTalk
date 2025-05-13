/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:27:46 by delhajou          #+#    #+#             */
/*   Updated: 2025/03/27 19:38:56 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minitalk.h"

{
    static int i = 0;
    (void)ptr;
    static unsigned char buff[8] = {0};
    if(signal_information ->si_pid)
    {
        
        if (signal == SIGUSR1)
            buff[i] = 1;
        else if (signal == SIGUSR2)
            buff[i] = 0;
        i++;
    }
    if(i == 8)
    {
        binary_to_decimal(buff);
        i = 0;
    }
}

int main(void)
{
    pid_t id = getpid(); // this is basically an int 
    write(1,"Process id:",11);
    ft_putnbr(id);
    write(1,"\n",1);
    struct sigaction sig;
    sig.sa_sigaction = handler;
    sig.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1,&sig, NULL );
    sigaction(SIGUSR2,&sig, NULL );
    while (1)
        pause();

    
    return EXIT_SUCCESS;
}

