/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:05:33 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/01 22:27:31 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

/* 6) Faça um programa que leia a idade de uma pessoa expressa em dias e mostre-a
expressa em anos, meses e dias.*/

int main(void)
{
    int anos;
    int meses;
    int dias;
    
    std::cout << "Dias: \n";
    std::cin >> dias;
    anos = (dias / 365);
    dias -= (365 * anos);
    meses = (dias / 30);
    dias -= (30 * dias);
    std::cout << "você viveu aproximadamente " << anos << " anos " << meses << " messes "<< dias << " e dias" << "\n";   
    
}