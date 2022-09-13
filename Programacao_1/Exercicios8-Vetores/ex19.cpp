/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex19.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:19:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/25 00:17:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

typedef struct s_contatos
{
    int     index;
    char    name[50];
    int     telefone;
    int     celular;
    char    email[50];
    int     nascimento[3];
} t_contatos;


int main(void)
{
    t_contatos agenda[1000];
    int         option = 0;
    int         i = 0; int  j = 0;
    char        nome[50];
    int         aniversario; 
   
    std::cout << "\n-------------Bem Vindo a agenda-------------\n";
    while(1)
    {
        while (option != 1 && option != 2 && option != 3)
        {
            std::cout << "Para: \n-adicionar um novo contato: digite [1] \n-Fazer uma consulta: digite [2] \n-sair: digite [3]";
            std::cin >> option;    
        }
        if (option == 1)
        {
            agenda[i].index = i; 
            std::cout << "Nome: \" entre aspas \" ";
            std::cin >> agenda[i].name;
            std::cout << "telefone: ";
            std::cin >> agenda[i].telefone;
            std::cout << "celular: ";
            std::cin >> agenda[i].celular;
            std::cout << "email: ";
            std::cin >> agenda[i].email;
            std::cout << "dia do nascimento: ";
            std::cin >> agenda[i].nascimento[0];
            std::cout << "mês do nascimento: ";
            std::cin >> agenda[i].nascimento[1];
            std::cout << "ano do nascimento: ";
            std::cin >> agenda[i].nascimento[2];
            option = 0;
            i++;
        }
        if (option == 2)
        {
            option = 0;
            while (option != 1 && option != 2 && option != 3 && option != 4)
            {
                std::cout << "\n- Buscar por nome e sobrenome: digite [1] \n- Buscar por niversario do mês: digite [2] \n -Gerar relatório com todos os contatos: digite [3] \n- Voltar: digite [4]";
                std::cin >> option;
            }
            if (option == 1)
            {
                std::cout << "\n Digite o nome e o sobrenome:";
                std::cin >> nome;
                j = 0;
                while (j < i)
                {
                    if (strcmp(nome, agenda[j].name) == 0)
                        std::cout << "\n nome: " << agenda[j].name << " celular: " << agenda[j].celular << " telefone: " << agenda[j].telefone << " email: " << agenda[j].email << " nascimento: " << agenda[j].nascimento[0] << "\\" << agenda[j].nascimento[1] << "\\"<< agenda[j].nascimento[2] << "\\";
                    j++;
                }
                if (i == 0)
                    std::cout << "Agenda Vazia."; 
            }
            if (option == 2)
            {
                std::cout << "\n Digite o mês doa aniversario:";
                std::cin >> aniversario;
                j = 0;
                while (j < i)
                {
                    if (agenda[j].nascimento[1] ==  aniversario)
                        std::cout << "\n nome: " << agenda[j].name << " celular: " << agenda[j].celular << " telefone: " << agenda[j].telefone << " email: " << agenda[j].email << " nascimento: " << agenda[j].nascimento[0] << "\\" << agenda[j].nascimento[1] << "\\"<< agenda[j].nascimento[2] << "\\";
                    j++;
                }
                if (i == 0)
                    std::cout << "Agenda Vazia."; 
            }
            if (option == 3)
            {
                for (j = 0; j < i; j++)
                    std::cout << "\n nome: " << agenda[j].name << " celular: " << agenda[j].celular << " telefone: " << agenda[j].telefone << " email: " << agenda[j].email << " nascimento: " << agenda[j].nascimento[0] << "\\" << agenda[j].nascimento[1] << "\\"<< agenda[j].nascimento[2] << "\\";
                if (i == 0)
                    std::cout << "Agenda Vazia."; 
            }
            if (option == 4)
            {
                option = 0;
                return (0);
            }
            option = 0;            
        }
        if (option == 3)
        {
            std::cout << "Atenção!! Sair agora resultara na perda de todos os contatos\n";
            std::cout << "\n-------------Até a próxima-------------\n";
            break;    
        }
    } 
    return (0);
}