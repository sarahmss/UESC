/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/06 10:27:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*Deseja-se publicar o número de acertos de cada aluno em uma prova em forma de
testes. A prova consta de 5 questões, cada uma com cinco alternativas identificadas
por A, B, C, D e E. Para isso são dados:
• o cartão gabarito;
• o número de alunos da turma;
• o cartão de respostas para cada aluno, contendo o seu número e suas
respostas. */
 
int main(void)
{
	int	alunos;
	char gabarito[5];
	int	i;
	int	j;
	int	acertos;

	std::cout << "Numero de alunos: ";
	std::cin >> alunos;
	char	cartao_aluno[alunos][5];
	std::cout << "Gabarito: \n";
	for (i = 0; i < 5; i++)
	{
		std::cout << "Questão[" << i + 1 <<"]:";
		std::cin >> gabarito[i];
    }
	for (i = 0; i < alunos; i++)
	{
		std::cout << "INSIRA AS ALTERNATIVAS ASSINALADAS PARA O ALUNO " << i + 1 << "\n";
		for (j = 0; j < 5; j++)
		{
			std::cout << "Questão[" << j + 1 <<"]:";
			std::cin >> cartao_aluno[i][j];
		}
	}
	
	for (i = 0; i < alunos; i++)
	{
		acertos = 0;
		std::cout << "Quantidade de acertos do aluno " << i  + 1 << ": ";
		for (j = 0; j < 5; j++)
			if (cartao_aluno[i][j] == gabarito[j])
				acertos++;
		std::cout << acertos << "\n";
	}
}