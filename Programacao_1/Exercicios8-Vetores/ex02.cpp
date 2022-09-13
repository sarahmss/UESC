/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/06 09:54:13 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Armazene num vetor de 5 posições o salário de 5 pessoas. Em seguida, verifique os salários
menores q 1000 reais e forneça um aumento de 10%.Ao final, mostre a lista de salários atualizada*/
 
int main(void)
{
    int    salarios[5];
    int    i;
    
    i = 0;
    std::cout << "Salarios:\n";
    while (i < 5)
    {
        std::cout << i + 1 << ". :";
        std::cin >> salarios[i];
        std::cout << "\n";
        if (salarios[i] <  1000) 
            salarios[i] += (salarios[i] * 0.1) ;  
        i++;
    }
    for( i = 0; i <= 4; i++)
        std::cout << i << ". :" << salarios[i] << "\n";
    return (0);
 }