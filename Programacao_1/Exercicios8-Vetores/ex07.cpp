/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/16 16:07:38 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/* Faça um programa que verifique se uma palavra digitada pelo usuário é um palíndromo perfeito
(palíndromos perfeitos são palavras que, lidas de trás para frente, são idênticas a si mesmas)*/
 
int main(void)
{
    char    str[20];
    char    palindromo[20];
    int     i;
    int     j = 0;

    std::cout << "Palavra: ";
    std::cin >> str;
    for(i = int(strlen(str) - 1); i >= 0; i--)
    {
        palindromo[j] = str[i];  
        j++;  
    }
    palindromo[j] = '\0';
    j = 0;
    while (palindromo[j])
    {
        if (palindromo[j] != str[j])
        {
            std::cout << "Não é Palindromo!!\n";
            return(0);           
        }
        j++;
    }
    std::cout << "Palindromo!!\n";
    return (0);
 }