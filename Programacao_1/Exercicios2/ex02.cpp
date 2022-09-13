/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:05:33 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/28 14:22:35 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

/* 2) Faça um programa que leia dois valores nas variáveis A e B respectivamente,
troque o valor contido na variável A pelo valor em B, e o valor em B pelo valor em A,
isto é, imprimiremos A e B com os valores trocados.*/

int main(void)
{
    int A;
    int B;
    int temp;
    
    std::cout << "INSIRA A \n";
    std::cin >> A;
    std::cout << "INSIRA B \n";
    std::cin >> B;
    std::cout << "Antes: A = " << A << " B = " << B << "\n";
    temp = A;
    A = B;
    B = temp;
    std::cout << "Depois: A = " << A << " B = " << B << "\n";
    
}