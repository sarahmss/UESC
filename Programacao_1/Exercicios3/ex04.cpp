/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/19 13:46:07 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

/*Escrever um algoritmo para ler e imprimir três números. Se o primeiro for positivo,
imprimir sua raiz quadrada, caso contrário, imprimir o seu quadrado; se o segundo número
for maior que 10 e menor que 100, imprimir a mensagem: “Número está entre 10 e 100 –
intervalo permitido”; se o terceiro número for menor que o segundo, calcular e imprimir a
diferença entre eles, caso contrário, imprimir o terceiro número adicionado de 1.*/
 
int main(void)
{
    int n1;
    int n2;
    int n3;
    
    std::cout << "n1: \n";
    std::cin >> n1;
    std::cout << "n2: \n";
    std::cin >> n2;
    std::cout << "n3: \n";
    std::cin >> n3;
    if  (n1 > 0)
        std::cout << sqrt(n1);
    else
        std::cout << pow(n1, 2);
    if ((n2 > 10) && (n2 < 100))
       std::cout << "Número está entre 10 e 100 – intervalo permitido";
    if  (n3 < n2)
        std::cout << (n2 - n3);
    else
        std::cout << (1 + n3);       
    return (0);
 }