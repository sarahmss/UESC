/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/15 12:55:10 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Ler um número inteiro, e verificar se o número corresponde a um mês válido no calendário e
escrever o nome do mês, senão escrever uma mensagem ‘Mês Inválido’*/

int main(void)
{
    int n1;
 
    std::cout << "Insira um número: ";
    std::cin >> n1;
    if (n1 <= 12 && n1 >= 1)
    {
        if (n1 == 1)
            std::cout << "janeiro. \n";        
        if (n1 == 2)
            std::cout << "fevereiro. \n";
        if (n1 == 3)
            std::cout << "março. \n";
        if (n1 == 4)
            std::cout << "abril. \n";
        if (n1 == 5)
            std::cout << "maio. \n";        
        if (n1 == 6)
            std::cout << "junho. \n";
        if (n1 == 7)
            std::cout << "julho. \n";
        if (n1 == 8)
            std::cout << "agosto. \n";
        if (n1 == 9)
            std::cout << "setembro. \n";        
        if (n1 == 10)
            std::cout << "outubro. \n";
        if (n1 == 11)
            std::cout << "novembro. \n";
        if (n1 == 12)
            std::cout << "dezembro. \n";   
    }
    else
        std::cout << "Mês invalido. \n. \n";
    return (0);
 }