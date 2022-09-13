/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:05:33 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/01 22:36:35 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

/* 
7) Faça um programa que leia o número do funcionário, o número de horas
trabalhadas mensais, o valor que recebe por hora e o número de filhos com idade
menor de 14 anos. Calcular e escrever o salário deste funcionário, sendo que cada
filho menor de 14 anos acrescenta 10% do salário.*/

int main(void)
{
    int funcionario;
    int horas;
    int men_14;
    int salario_hora;
    
    std::cout << "funcionario: \n";
    std::cin >> funcionario;
    std::cout << "horas: \n";
    std::cin >> horas;
    std::cout << "filhos com menos de 14 anos: \n";
    std::cin >> men_14;
    std::cout << "salario por hora: \n";
    std::cin >> salario_hora;
    salario_hora *= horas; 
    if (men_14 > 0)
        salario_hora += (men_14 * 0.1 * salario_hora);
    std::cout << "O funcionário " << funcionario << "tem salário igual a: " << salario_hora <<"\n";
    
}