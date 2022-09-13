/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex17.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/24 23:17:31 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"
# include <math.h>

/*Modifique o programa anterior para que ele mostre também a diferença entre a primeira e a
segunda lista (os que estão em uma mas não em outra lista)*/
int main(void)
{
    int size1;
    int size2;
    int i;  int j;  int k;
    int intersec[20];


    std::cout << "Tamanho da lista1: ";
    std::cin >> size1;
    std::cout << "Tamanho da lista2: ";
    std::cin >> size2;
    int lista1[size1];
    int lista2[size2];
    for (i = 0; i < size1; i++)
    {
        std::cout << "lista1[" << i  + 1 << "]:";
        std::cin >> lista1[i];
    }
    for (i = 0; i < size2; i++)
    {
        std::cout << "lista2[" << i  + 1 << "]:";
        std::cin >> lista2[i];
    }
        std::cout << "Intersecção: ";
    for (i = 0; i < size1; i++)
    {
        for (j = 0; j < size2; j++)
            if (lista1[i] == lista2[j])
                std::cout <<  lista1[i] << " ";   
    }
        std::cout << "União: ";
    k = 0;
    for (i = 0; i < size1; i++)
    {
        for (j = 0; j < size2; j++)
        {
            if (lista1[i] == lista2[j])
            {
                intersec[k] =  lista1[1];   
                k++;                
            }
        }
    }
    for (j = 0; j < size2; j++)
        for (i = 0; i < k; i++)
            if (lista2[j] != intersec[i])
                std::cout << lista2[j] << " ";
    for (j = 0; j < size1; j++)
        for (i = 0; i < k; i++)
            if (lista1[j] != intersec[i])
                std::cout << lista1[j] << " ";
    std::cout << "Diferença: ";
    k = 1;
    for (i = 0; i < size1; i++)
    {
        for (j = 0; j < size2; j++)
            if (lista1[i] == lista2[j])
                k = 0;
        if (k == 1)
            std:: cout << lista1[i] << " ";
        k = 1;
    }
    k = 1;
    for (i = 0; i < size2; i++)
    {
        for (j = 0; j < size1; j++)
            if (lista2[i] == lista1[j])
                k = 0;
        if (k == 1)
            std:: cout << lista2[i] << " ";
        k = 1;
    }
    return (0);
 }