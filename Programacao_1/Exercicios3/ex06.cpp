/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/15 11:02:17 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Elabore um algoritmo que, dada a idade de um nadador, classifique-o em uma das seguintes
categorias:
• Infantil A: 5 a 7 anos;
• Infantil B: 8 a 10
• anos;
• Juvenil A: 11 a 13 anos;
• Juvenil B: 14 a 17 anos;
• Sênior: maiores de 18 anos*/
 
int main(void)
{
    int idade;
    
    std::cout << "idade: \n";
    std::cin >> idade;
    if  ((idade >= 5) && (idade <= 7))
        std::cout << "O nadador de " << idade << " anos, é infantil A. \n";
    if  ((idade >= 8) && (idade <= 10))
        std::cout << "O nadador de " << idade << " anos, é infantil B. \n";
    if  ((idade >= 11) && (idade <= 13))
        std::cout << "O nadador de " << idade << " anos, é juvenil A. \n";
    if  ((idade >= 14) && (idade <= 17))
        std::cout << "O nadador de " << idade << " anos, é juvenil B. \n";
    if  (idade >= 18)
        std::cout << "O nadador de " << idade << " anos, é sênior. \n";    
    return (0);
 }