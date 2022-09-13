/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex13.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/24 22:01:36 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"
# include <math.h>

/*Faça um Programa que leia 20 números inteiros e armazene-os num vetor. Em seguida
armazene os números pares no vetor PAR e os números IMPARES no vetor impar. Imprima os três
vetores.*/
int main(void)
{
    int vetor[20];
    int par[20];
    int impar[20];
    int i;  int j; int  k;

    j = 0;
    k = 0;
    for (i = 0; i < 20; i++)
    {
        std::cout << "Vetor[" << i  + 1 << "]:";
        std::cin >> vetor[i];
        if (vetor[i] % 2 == 0)
        {
            par[j] = vetor[i];
            j++;
        }
        else
        {
            impar[k] = vetor[i];
            k++;
        }
    }
    std::cout << "Vetor: ";
    for (i = 0; i < 20; i++)
        std::cout << vetor[i] << " ";
    std::cout << "\nPares: ";
    for (i = 0; i < j; i++)
        std::cout << par[i] << " ";
    std::cout << "\nImpares: ";    
    for (i = 0; i < k; i++)
        std::cout << impar[i] << " ";
    
    return (0);
 }