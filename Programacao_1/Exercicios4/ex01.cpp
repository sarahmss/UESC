/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/15 11:26:20 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Leia 3 valores inteiros (X, Y, Z), determina e escreve o menor delesr*/
 
int main(void)
{
    int x;
    int y;
    int z;
    
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    std::cout << "z: ";
    std::cin >> z;
    if ((x < y) && (x < z))
        std::cout << "o menor numero inserido foi " << x << "\n";
    else if ((z < x) && (z < y))
        std::cout << "o menor numero inserido foi " << z << "\n";
    else if  ((y < x) && (y < z))
        std::cout << "o menor numero inserido foi " << y << "\n";
    return (0);
 }