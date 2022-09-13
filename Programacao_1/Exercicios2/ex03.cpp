/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:05:33 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/01 22:09:22 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

/* 3) Faça um programa que leia cinco números inteiros, calcule e escreva a soma, o
produto e a média dos números lidos.*/

int main(void)
{
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    
    std::cout << "INSIRA n1 \n";
    std::cin >> n1;
    std::cout << "INSIRA n2 \n";
    std::cin >> n2;
    std::cout << "INSIRA n3 \n";
    std::cin >> n3;
    std::cout << "INSIRA n4 \n";
    std::cin >> n4;
    std::cout << "INSIRA n5 \n";
    std::cin >> n5;
    std::cout << " A SOMA " <<n1<<" + "<<n2<<" + "<<n3<<" + "<<n4<<" + "<<n5<<" = "<<(n1+n2+n3+n4+n5);
    std::cout << " O PRODUTO " <<n1<<" * "<<n2<<" * "<<n3<<" * "<<n4<<" * "<<n5<<" = "<<(n1*n2*n3*n4*n5);
    std::cout << " A MÉDIA " <<n1<<" + "<<n2<<" + "<<n3<<" + "<<n4<<" + "<<n5<<" = "<<(n1+n2+n3+n4+n5)/5;
    
}