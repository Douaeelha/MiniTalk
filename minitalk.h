#ifndef MINITALK_H
#define MINITALK_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <limits.h>

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void ft_putchar(char c);
void handler(int sig, siginfo_t infos, void *ptr );
void binary_to_decimal(unsigned char *s);
int	ft_atoi(char *str);
#endif  




























