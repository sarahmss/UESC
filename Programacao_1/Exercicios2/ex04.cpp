/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:05:33 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/05 13:57:02 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <math.h>

/* 4) Faça um programa que leia dois valores inteiros (X e Y) e calcule X na potência Y.
Observação: utilizar a função matemática.*/

int main(void)
{
    int X;
    int Y;
    
    std::cout << "INSIRA X \n";
    std::cin >> X;
    std::cout << "INSIRA Y \n";
    std::cin >> Y;
    std::cout << "X^(Y) = " << pow(X,Y) << "\n";
}