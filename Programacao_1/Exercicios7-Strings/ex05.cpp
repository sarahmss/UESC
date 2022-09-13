/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/16 13:22:33 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Faça um programa que leia o nome de três pessoas e os escreva em ordem alfabética*/
 
int main(void)
{
    char    nome1[20];
    char    nome2[20];
    char    nome3[20];

    std::cout << "nome1: ";
    std::cin >> nome1;
    std::cout << "nome2: ";
    std::cin >> nome2;
    std::cout << "nome3: ";
    std::cin >> nome3;
    
    if ((strcmp(nome1, nome2) < 0) && (strcmp(nome2, nome3) < 0))
        std::cout << nome1 << " " << nome2 << " " << nome3 << "\n";
    else if ((strcmp(nome1, nome3) < 0) && (strcmp(nome3, nome2) < 0))
        std::cout << nome1 << " " << nome3 << " " << nome2 <<"\n";
    else if ((strcmp(nome2, nome1) < 0) && (strcmp(nome1, nome3) < 0))
        std::cout << nome2 << " " << nome1 << " " << nome3 <<"\n";
    else if ((strcmp(nome2, nome3) < 0) && (strcmp(nome3, nome1) < 0))
        std::cout << nome2 << " " << nome3 << " " << nome1 <<"\n";
    else if ((strcmp(nome3, nome2) < 0) && (strcmp(nome2, nome1) < 0))
        std::cout << nome3 << " " << nome2 << " " << nome1 <<"\n";
    else if ((strcmp(nome3, nome1) < 0) && (strcmp(nome1, nome2) < 0))
        std::cout << nome3 << " " << nome1 << " " << nome2 <<"\n"; 
    return (0);
 }