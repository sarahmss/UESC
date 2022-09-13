/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/05 13:40:12 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

//Lê um número e mostra a terça parte deste número.
int main(void)
{
    float a;
    
    std::cout << "Escolha um número\n";
    std::cout << "n1: ";
    std::cin >> a;
    std::cout << "TERÇA PARTE = " << (a / 3) << "\n";
    return (0);
}
