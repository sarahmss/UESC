/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:05:33 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/01 22:24:22 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

/* 1) Faça um programa que leia a idade de uma pessoa expressa em anos, meses e
dias e mostre-a expressa apenas em dias*/

int main(void)
{
    int anos;
    int meses;
    int dias;
    
    std::cout << "Anos: \n";
    std::cin >> anos;
    std::cout << "Meses: \n";
    std::cin >> meses;
    std::cout << "Dias: \n";
    std::cin >> dias;
    dias += (365 * anos) + (31 * meses);
    std::cout << "você viveu aproximadamente " << dias << "dias ";   
}