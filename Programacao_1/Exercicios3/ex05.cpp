/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/19 13:47:06 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*Tendo como dados de entrada a altura e o sexo de uma pessoa. construa um algoritmo para
calcular seu peso ideal. utilizando as seguintes fórmulas:
- para homens: 72.7 * altura – 58;
- para mulheres: 62.1 * altura – 44.7*/
 
int main(void)
{
    int altura;
    int sexo;
    
    std::cout << "Sexo:(F / M) ";
    std::cin >> sexo;
    std::cout << "Altura: ";
    std::cin >> altura;
    if  (sexo == 'F' || sexo == 'f')
        std::cout << "Seu peso ideal é " << ((62.1 * altura) - 44.7);
    else if (sexo == 'M' || sexo == 'm')
        std::cout << "Seu peso ideal é " << ((72.7 * altura) - 58);
    return (0);
}