/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/16 14:33:08 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Faca um programa q leia n valores reais. Armazene estes valores num vetor. Ao final, imprima a
média aritmética destes valores*/
 
int main(void)
{
    int n;
    int i;
    int media;
    
    media = 0;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "\n Valores: \n";
    int valores[n];
   for (i = 0; i < n; i++)
    {
        std::cout << i + 1 << ". :";
        std::cin >> valores[i];
        media += valores[i];
        std::cout << "\n";
    }
    std::cout << "media: " << media / n << "\n";
    return (0);
 }