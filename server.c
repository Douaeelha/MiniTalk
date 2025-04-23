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

//  char c = 0;

// void handler(int sig, siginfo_t *signal_information, void *ptr)
// {
//     (void)ptr;
//     pid_t pid = infos->si_pid;
//     int bit = 0;
//  c = c << 1;
//   if (sig == SIGUSR1)
//     c = c || 1;
//   else if(sig == SIGUSR2)
//     c = c  || 0;
//   c++;
//   bit ++;
//   if(bit == 8)
//   {
//     ft_putchar(c);
//     bit = 0;
//     c = 0;
//   }
// }

// int main(void)
// {
//     pid_t id = getpid(); // this is basically an int 
//     write(1,"Process id:",11);
//     ft_putnbr(id);
//     write(1,"\n",1);
//     struct sigaction signal;
//     signal.sa_sigaction = handler;
//     signal.sa_flags = SA_SIGINFO;
    
//     sigaction(SIGUSR1, &signal, NULL);
//     sigaction(SIGUSR2, &signal, NULL);
//     while (1)
//         pause();
//     return EXIT_SUCCESS;
// }
void handler(int signal, siginfo_t *signal_information, void *ptr)
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

// void binary_to_decimal(unsigned char *s)
// {
//     char c;
//     int i = 0;
//     while (s[i])
//     {
//         bi = 7;
//         while (bi >= 0)
//         {
//             if (s[i] == 1)
//             {
//                 c = s[i] * 2;
//                 bi--;
//             }
//         }
//         ft_putchar(c);
//         i++;

//     }
// }
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

// #include "minitalk.h"

// void convert_and_print(int *bits)
// {
// 		int i = 7;
// 		char c = 0;
// 		int power = 1; // 2^0 initially

// 		while (i >= 0)
// 		{
// 				if (bits[i] == 1)
// 						c += power; // Add the power of 2 if bit is 1

// 				power *= 2; // Move to next power of 2
// 				i--;
// 		}

// 		ft_putchar(c); // Print the character
// }

// void handler(int sig, siginfo_t *sig_infos, void *ptr)
// {
// 		(void)ptr; // Unused parameter
// 		static int bits[8]; // Store the 8 bits
// 		static int i = 0; // Track bit position
// 		static int last_client; // Track client PID

// 		pid_t pid = sig_infos->si_pid;

// 		if (pid != last_client)
// 		{
// 				last_client = pid;
// 				i = 0;
// 		}

// 		if (sig == SIGUSR1)
// 				bits[i] = 1; // Store 1 if SIGUSR1 received
// 		else if (sig == SIGUSR2)
// 				bits[i] = 0; // Store 0 if SIGUSR2 received

// 		i++;

// 		if (i == 8) // When 8 bits are received, convert and print
// 		{
// 				convert_and_print(bits);
// 				i = 0;
// 		}
// }

// int main(void)
// {
// 		pid_t id = getpid(); // Get server PID
// 		write(1, "Process ID: ", 12);
// 		ft_putnbr(id);
// 		write(1, "\n", 1);

// 		struct sigaction signal;
// 		signal.sa_sigaction = handler;
// 		signal.sa_flags = SA_SIGINFO;

// 		sigaction(SIGUSR1, &signal, NULL);
// 		sigaction(SIGUSR2, &signal, NULL);

// 		while (1)
// 				pause(); // Wait for signals

// 		return 0;
// }
