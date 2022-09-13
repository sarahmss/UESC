/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/23 17:51:20 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/* Faça um programa que leia o tamanho de uma matriz quadrada e seus elementos, e em seguida
mostre os elementos que compõem sua diagonal principal e sua diagonal secundária*/
int **create_matrix(int linhas, int colunas)
{
    int **matriz;
    int i;

    i = 0;
    matriz = (int **)malloc(sizeof(int *) * linhas);
    if (!matriz)
        return (NULL);
    while (i < colunas)
    {
        matriz[i] = (int *)malloc(sizeof(int) * colunas);
        if (!matriz[i])
            return (NULL);
        i++;
    }
    return (matriz); 
}

void    fill_matrix(int **matriz, int linhas, int colunas)
{
    int i;
    int j;
    
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
}

void    eval_diag(int **matriz, int linhas, int colunas)
{
    int i;
    int j;
    
    i = 0;
    if (colunas == 2)
        std::cout << "a12=" << matriz[0][1] << " e " "a21=" << matriz[1][0] << " são elementos da diagonal secundária\n";
      if (colunas == 3)
        std::cout << "a13=" << matriz[0][2]  << ", " "a22=" << matriz[1][1] << " e " "a31=" << matriz[2][0] << " são elementos da diagonal secundária\n";
    while (i < linhas)
    {
        j = 0;
        while (j < colunas)
        {
            if (i == j)
                std::cout << "a" << i + 1 << j + 1 << "=" << matriz[i][j] << " é um elemento da diagonal principal\n";
            if (i + j == colunas + 1 && (colunas != 2) && (colunas != 3))
                std::cout << "a" << i + 1 << j + 1 << "=" << matriz[i][j] << " é um elemento da diagonal secundária\n";
            j++;
        }
        i++;
    }
}

void	free_matrix(int **matrix, int linhas)
{
	int	i;

	i = 0;
	while (i < linhas)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int main(void)
{
    int linhas;
    int colunas;
    int **matriz;
   
    std::cout << "Linhas: ";
        std::cin >> linhas;
    std::cout << "colunas: ";
        std::cin >> colunas;
    if (linhas != colunas)
    {
        std::cout << "Insira uma matriz quadrada!!";
        return (0);
    }
    matriz = create_matrix(linhas, colunas);
    fill_matrix(matriz, linhas, colunas);
    eval_diag(matriz, linhas, colunas);
    free_matrix(matriz, linhas);
    return (0);
 }