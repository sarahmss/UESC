/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/12 19:32:28 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Desenvolva um algoritmo que efetue a leitura de três valores para os lados de um triângulo,
considerando lados como: A, B e C. O algoritmo deverá verificar se os lados fornecidos forma
realmente um triângulo (cada lado é menor que a soma dos outros dois lados). Se for esta condição
verdadeira, deverá ser indicado qual tipo de triângulo foi formado: isósceles (dois lados iguais e um
diferente), escaleno (todos os lados diferentes) ou eqüilátero (todos os lados são iguais).*/
 
int main(void)
{
    int A;
    int B;
    int C;
    char senha[8];
    
    std::cout << "senha: ";
    std::cin >> senha;
    if (strcmp(senha, "secreta"))
        return (0);
    std::cout << "lado 1: ";
    std::cin >> A;
    std::cout << "lado 2: ";
    std::cin >> B;
    std::cout << "lado 3: ";
    std::cin >> C;
    if ((A + B > C) && (A + C > B) && (B + C > A))
    {
        if ((A == B) && (A == C))
            std::cout << "Triângulo Equilátero. \n";
        else if (((A == B) && (A != C)) || ((C == B) && (A != C)))
            std::cout << "Triângulo Isósceles. \n";
        else if ((A != B) && (B != C) && (A != C))
            std::cout << "Triângulo Escaleno. \n";
    }
    return (0);
 }