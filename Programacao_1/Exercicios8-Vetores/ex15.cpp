/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex15.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/24 22:44:18 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"
# include <math.h>

/*15. Faça um programa que leia duas listas de números e mostre sua intersecção (os que estão em
ambas as listas*/
int main(void)
{
    int size1;
    int size2;
    int i;  int j;

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
    return (0);
 }