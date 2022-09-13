/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/15 11:52:32 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*A Secretaria de Meio Ambiente, que controla o índice de poluição, mantém 3 grupos de indústrias
que são altamente poluentes do meio ambiente. O índice de poluição aceitável varia de 0,05 até 0,29.
Se o índice sobe para 0,3 as indústrias do 1º grupo são intimadas a suspenderem suas atividades, se o
índice crescer para 0,4 as industrias do 1º e 2º grupo são intimadas a suspenderem suas atividades, se
o índice atingir 0,5 todos os grupos devem ser notificados a paralisarem suas atividades. Faça um
programa que leia o índice de poluição*/
 
int main(void)
{
    float Poluicao;
    
    std::cout << "Índice de poluição: ";
    std::cin >> Poluicao;
    if ((Poluicao >= 0.05) && (Poluicao <= 0.29))
        std::cout << "Índice de poluição aceitavel. \n";
    else if ((Poluicao >= 0.3) && (Poluicao < 0.4))
        std::cout << "Industrias do 1º grupo devem suspender atividades. \n";
    else if ((Poluicao >= 0.4) && (Poluicao < 0.5))
        std::cout << "Industrias do 1º e 2º grupo devem suspender atividades. \n";
    else if (Poluicao >= 0.5)
        std::cout << "Todos os grupos devem suspender atividades. \n";
    return (0);
 }