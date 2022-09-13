/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/17 17:06:18 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*  Modifique o programa anterior para que ele imprima, também, a matriz transposta*/

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
    std::cout << "matriz(" << linhas << "X" << colunas << "):\n";
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
    int transposta[colunas][linhas];
    std::cout << "transposta(" << colunas << "X" << linhas << "):\n";
    for (i = 0; i < linhas; i = i + 1)
        for (j = 0; j < colunas; j = j + 1)
            transposta[j][i] = matriz[i][j];
    i = 0;
    while (i < colunas)
    {
        j = 0;
        std::cout << "| ";
        while (j < linhas)
        {
            std::cout << transposta[i][j] << " ";
            j++;    
        }
        std::cout << "|\n";
        i++;
    }
    return (0);
 }