/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/23 17:56:06 by smodesto         ###   ########.fr       */
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

void    eval_form(int **matriz, int linhas, int colunas)
{
    int i = 0;
    int j;
    int triang_inf = 1;
    int triang_sup = 1;
    
    while (i < linhas)
    {
        j = 0;
        while (j < colunas)
        {
            if ((i > j) && (matriz[i][j] != 0))
                triang_sup = 0; 
            if ((i < j) && (matriz[i][j] != 0))
                triang_inf = 0; 
            j++;
        }
        i++;
    }
    if (triang_inf == 1 && triang_sup == 1)
        std::cout << "Matriz Diagonal";
    else if (triang_inf == 1)
        std::cout << "Triangular inferior";
    else if (triang_sup == 1)
        std::cout << "Matriz Diagonal";
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
    eval_form(matriz, linhas, colunas);
    free_matrix(matriz, linhas);
    return (0);
 }