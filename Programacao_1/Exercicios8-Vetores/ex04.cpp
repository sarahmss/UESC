/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/16 14:57:44 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Faca um programa que pergunte ao usuário o numero de alunos a ser lido. O tamanho dos vetores
será o numero informado pelo usuário. Armazene num vetor as notas G1 destes alunos; num outro
vetor, armazene as notas G2 destes alunos. Ambas notas, G1 e G2, são informadas pelo usuário.
Calcule a media aritmética destes alunos e armazene num terceiro vetor. Ao final, mostre as 3 notas
dos alunos*/
 
int main(void)
{
    int alunos;
    int i;
    
    std::cout << "alunos = ";
    std::cin >> alunos;
    std::cout << "\nG1 e G2: \n";
    int G1[alunos]; int G2[alunos]; int media[alunos];
    for (i = 0; i < alunos; i++)
    {
        std::cout << "G1 nota " << i + 1 << ". :";
        std::cin >> G1[i];
        std::cout << "G2 nota " << i + 1 << ". :";
        std::cin >> G2[i];
        media[i] = ((G1[i] + G2[i]) / 2);
    }
    for( i = 0; i < alunos; i++)
        std::cout <<"Aluno " << i << ". -" <<  " G1: " << G1[i] << " G2: " << G2[i] << " media: " << media[i] <<"\n"; 
    return (0);
 }
