/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/15 12:16:44 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Um vendedor necessita de um programa que calcule o preço total devido por um cliente. O programa
deve receber o código de um produto e a quantidade comprada e calcular o preço total, usando a
tabela abaixo. Mostrar uma mensagem no caso de código inválido*/
 
int main(void)
{
    int codigo;
    int quantidade;
    
    std::cout << "Codigo do produto: ";
    std::cin >> codigo;
    std::cout << "Quantidade comprada: ";
    std::cin >> quantidade;
    if (codigo == 1001)
        std::cout << "Preço total:  " << 5.32 * quantidade << "R$ \n";
    else if (codigo == 1324)
        std::cout << "Preço total:  " << 6.45 * quantidade << "R$ \n";
    else if (codigo == 6548)
        std::cout << "Preço total:  " << 2.37 * quantidade << "R$ \n";
    else if (codigo == 987)
        std::cout << "Preço total:  " << 5.32 * quantidade << "R$ \n";
    else if (codigo == 7623)
        std::cout << "Preço total:  " << 6.45 * quantidade << "R$ \n";
    else
        std::cout << "Codigo de produto invalido. \n";
        
    return (0);
 }