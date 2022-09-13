/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/15 11:12:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Faça um algoritmo que leia duas notas obtidas por um aluno na disciplina de Cálculo, o
número de aulas ministradas e o número de aulas assistidas por este aluno nesta disciplina.
Calcule e mostre a média final deste aluno e diga se ele foi aprovado ou reprovado.
Considere que para um aluno ser aprovado ele deve obter média final igual ou maior a 6 e
ter no mínimo 75% de freqüência.*/
 
int main(void)
{
    int nota1;
    int nota2;
    int aula_total;
    int aula_assistida;
    
    std::cout << "nota 1: \n";
    std::cin >> nota1;
    std::cout << "nota 2: \n";
    std::cin >> nota2;
    std::cout << "Aulas assistidas: \n";
    std::cin >> aula_assistida;
    std::cout << "Aulas ministradas : \n";
    std::cin >> aula_total;
    if  ((aula_assistida >= 0.75 * aula_total) && ((nota1 + nota1 ) / 2 >= 6))
        std::cout << "Aluno aprovado. \n";
    else
        std::cout << "Aluno reprovado. \n";
    return (0);
 }