/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex14.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/24 22:19:40 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"
# include <math.h>

/*Foram anotadas as idades e alturas de 30 alunos. Faça um Programa que determine quantos
alunos com mais de 13 anos possuem altura inferior à média de altura desses alunos.*/
int main(void)
{
    double aluno[2][30];
    int j;
    int media;
    int result;

    result = 0;    
    media = 0;
    for (j = 0; j < 30; j++)
    {
            std::cout << "idade do aluno [" << j  + 1 << "]:";
            std::cin >> aluno[0][j];
    }        
    for (j = 0; j < 30; j++) 
    {
        std::cout << "altura do do aluno [" << j  + 1 << "]:";
        std::cin >> aluno[1][j];
        media += aluno[1][j];                   
    }
    for (j = 0; j < 30; j++) 
        if (aluno[0][j] > 13 && aluno[1][j] < media)
            result++;
    stdd::cout << result << "alunos maiores que 13 anos tem altura interior a média.";
    return (0);
 }