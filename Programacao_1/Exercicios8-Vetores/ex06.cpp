/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/16 15:24:27 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Faça um programa que inverta as letras de uma palavra (string) digitada pelo usuário. */
 
int main(void)
{
    char    str[20];
    int     i;
    
    std::cout << "Palavra: ";
    std::cin >> str;   
    for(i = int(strlen(str)); i >= 0; i--)
        std::cout << str[i];
    std::cout << "\n";
    return (0);
 }