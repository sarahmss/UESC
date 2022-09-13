/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/26 21:56:47 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*
    Faça um programa que solicite ao usuário para digitar valores numéricos inteiros positivos.
    Encerre a entrada de dados quando for digitado um número negativo ou zero. Calcule a média
    dos números positivos digitados.
*/
 
int main(void)
{
    int A = 0;
    int sum = 0;
    int total = 0;
    
    while (A >= 0 )
    {
        std::cout << "número: ";
        std::cin >> A;
        sum += A;
        total++;
    }
    std::cout << "média: " << (sum / total);
    return (0);
 }