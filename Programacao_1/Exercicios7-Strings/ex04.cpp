/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/14 21:30:47 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Faça um programa que leia uma string digitada pelo usuário (máximo 20 caracteres) e
imprima na tela o número de vogais existente nesta string.*/
 
int main(void)
{
    char    str[21];
    int     i;
    int     vog;

    vog = 0;
    i = 0;
    std::cout << "String: ";
    std::cin >> str;
    while (i < (int)strlen(str))
    {
        if (str[i] == 'a' || str[i]  == 'e' || str[i]  == 'o' || str[i]  == 'u')
            vog++;
        i++;
    }
    std::cout << vog << "\n";
    return (0);
 }