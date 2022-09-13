/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:05:33 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/01 22:45:44 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

/* 9) Faça um programa que leia as variáveis y e z. Após, calcule e mostre o valor de x,
dado pela expressão: x = √ y*(y22 + z33)*/

int main(void)
{
    int Y;
    int Z;
    
    std::cout << "INSIRA Y \n";
    std::cin >> Y;
    std::cout << "INSIRA Z \n";
    std::cin >> Z;
    std::cout << "x(y, z) = " << sqrt((Y * (pow(Y, 22) + pow(Z, 33)))) << "\n";
}