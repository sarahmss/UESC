/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/06 09:54:40 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

/*Faça um algoritmo que leia 10 salários. Depois de lidos e armazenados, mostre o maior valor.
Utilize vetores*/
 
int main(void)
{
    int    salarios[9];
    int    i;
    int    maior;
    
    i = 0;
    std::cout << "Salarios:\n";
    while (i <= 9)
    {
        std::cout << i + 1 << ". :";
        std::cin >> salarios[i];
        std::cout << "\n";
        if (i == 0)
            maior = salarios[0];
        else if (maior < salarios[i]) 
            maior = salarios[i];  
        i++;
    }
    std::cout << "o maior salário:" << maior << "R$ \n";
    return (0);
 }