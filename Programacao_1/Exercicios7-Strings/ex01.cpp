/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/12 19:28:47 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

/*Faça um programa que leia uma senha e a armazene. Em seguida peça ao usuário que digite a
senha e diga se está correta ou errada*/
 
int main(void)
{
    char    password[15];
    char    password_verify[15];
    
    std::cout << "Senha: ";
    std::cin >> password;
    std::cout << "Senha: ";
    std::cin >> password_verify;
    if (strcmp(password, password_verify) == 0)
        std::cout << ("Senha correta\n");
    else
        std::cout << ("Senha errada\n");
    return (0);
 }