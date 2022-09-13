/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/17 16:47:54 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*  Faça um programa que leia as dimensões de uma matriz, e em seguida os seus elementos e a
escreva na tela como no exemplo abaixo (supondo uma matriz 5x4)*/

int main(void)
{
    int     i; int     j;
    int     linhas; int     colunas;

    std::cout << "Linhas: ";
        std::cin >> linhas;
    std::cout << "colunas: ";
        std::cin >> colunas;
    int matriz[linhas][colunas];
    i = 0;
    while (i < linhas)
    {
        j = 0;
        while (j < colunas)
        {
            std::cout << "matriz[" << i + 1 << "][" << j + 1 << "]:";
                std::cin >> matriz[i][j];
            j++;    
        }
        i++;
    }
    i = 0;
    while (i < linhas)
    {
        j = 0;
        std::cout << "| ";
        while (j < colunas)
        {
            std::cout << matriz[i][j] << " ";
            j++;    
        }
        std::cout << "|\n";
        i++;
    }
    return (0);
 }