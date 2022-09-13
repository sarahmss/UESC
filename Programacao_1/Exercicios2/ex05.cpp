/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:05:33 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/05 14:02:12 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

/* 5) Faça um programa que leia A, B e C e calcule a seguinte fórmula: (7*C+5*B) /
(2*A*3), armazenando-a na variável Result..*/

int main(void)
{
    int A;
    int B;
    int C;
    int Result;
    
    std::cout << "INSIRA A \n";
    std::cin >> A;
    std::cout << "INSIRA B \n";
    std::cin >> B;
    std::cout << "INSIRA C \n";
    std::cin >> C;
    Result = ((7 * C) + (5 * B)) / (2 * A * 3);
    std::cout << "(7 * C + 5 * B) / (2 * A * 3) = " << Result << "\n";
    return (0);
}