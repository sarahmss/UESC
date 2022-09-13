/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/16 15:15:58 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*. Faca um algoritmo q leia e armazene 5 valores inteiros em um vetor Vet1. Leia outros 5 valores
inteiros e armazene num vetor Vet2. A partir destes valores lidos, mostre na tela:
- a soma dos elementos de cada vetor, nas respectivas posições
- a diferença dos elementos de cada vetor, nas respectivas posições
- o produto dos elementos de cada vetor, nas respectivas posições
- a divisão entre os elementos de cada vetor, nas respectivas posições */
 
int main(void)
{
    int    vet1[4];
    int     vet2[4];
    int     i;
    
    for(i = 0; i < 4; i++)
    {
        std::cout << "valor " << i << ". " << "para vet1: ";
        std::cin >> vet1[i];
        std::cout << "valor " << i << ". " << "para vet2: ";
        std::cin >> vet2[i]; 
    }
    for(i = 0; i < 4; i++)
    {    
        std::cout << "soma: " << vet1[i] + vet2[i];
        std::cout << "diferença: " << (vet1[i] > vet2[i] ? vet1[i] - vet2[i] : vet2[i] - vet1[i]);
        std::cout << "produto: " << vet1[i] * vet2[i];
        std::cout << "quociente: " << (vet1[i] > vet2[i] ? vet1[i] / vet2[i] : vet2[i] / vet1[i]);
    }
    return (0);
 }