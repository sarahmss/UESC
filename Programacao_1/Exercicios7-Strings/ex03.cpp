/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/12 19:36:33 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Faça um programa que escreva as letras da palavra "Universidade Estadual de Santa Cruz"
uma em cada linha*/
 
int main(void)
{
    char    frase[36];
    int     i;

    i = 0;
    strcpy(frase, "Universidade Estadual de Santa Cruz");
    while (i < (int)strlen(frase))
    {
        std::cout << frase[i] << "\n";
        i++;
    }
    return (0);
 }