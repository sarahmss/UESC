/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/26 21:53:17 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Faça um programa que calcule e escreva o valor de S:*/
 
int main(void)
{
    int x;
    int y;
    float soma;
    
    x = 1;
    y = 1;
    soma = 0;
    while ((x <= 99 ) && (y <= 50))
    {
        soma += x / y;
        x += 2;
        y++;
    }
    std::cout << soma << "\n";
    return (0);
 }