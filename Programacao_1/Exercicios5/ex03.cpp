/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/26 22:03:42 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*
    Faça um programa que solicite ao usuário 10 números inteiros e, ao final, informe a quantidade
de números ímpares e pares lidos. Calcule também a soma dos números pares e a média dos
números ímpares.
*/
 
int main(void)
{
    int num = 0;
    int i = 0;
    int j = 0;
    int odd = 0;
    int even = 0;
    
    while ((i + j) < 10)
    {    
        std::cout << "Número: ";
        std::cin >> num;
        if (num % 2 == 0)
        {
            even += num; 
            i++;  
        }
        else
        {
            odd += num;   
            j++;
        }
    }
    std::cout << i << " números pares foram lidos e a sua soma é = " << even << "\n";
    std::cout << j << " números impares foram lidos e a sua media é = " << odd / j << "\n";
    return (0);
 }