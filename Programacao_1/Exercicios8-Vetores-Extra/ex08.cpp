/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/06 12:35:44 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*  . Dados dois números naturais m e n e duas seqüências ordenadas com m e n números
inteiros, obter uma única seqüência ordenada contendo todos os elementos das
seqüências originais sem repetição.
Sugestão: Imagine uma situação real, por exemplo, dois fichários de uma
biblioteca*/

#include <iostream>
#include <string.h>
#define MAX 1000

int main(){
    int seq1[MAX], seq2[MAX], seq_ordenada[MAX];
    int m, n, num, i, j, k;

    std::cout << "Digite o numero de elementos da primeira sequencia: ";
    std::cin >> m;

    for (i = 0; i < m; i++){
        std::cout << "Digite o numero da primeira sequencia: ", i+1;
        std::cin >> num;
        seq1[i] = num;
    }

    std::cout << "Digite o numero de elementos da segunda sequencia: ";
    std::cin >> n;

    for (i = 0; i < n; i++){
        std::cout << "Digite o numero da segunda sequencia: ", i+1;
        std::cin >> num;
        seq2[i] = num;
    }

    j = i = k = 0;
    while (i < m && j < n) {
        if (seq1[i] < seq2[j]) {
            num = seq1[i];
            i++;
        }
        else {
            num = seq2[j];
            j++;
        }

        if (k == 0 || seq_ordenada[k-1] != num){
            seq_ordenada[k] = num;
            k++;
        }
    }

    while (i < m) {
        seq_ordenada[k] = seq1[i];
        i++;
        k++;
    }

    while (j < n) {
        seq_ordenada[k] = seq2[j];
        j++;
        k++;
    }

    std::cout << "A sequencia final ordenada e: \n";
    for (i = 0; i < k; i++)
            std::cout <<seq_ordenada[i];
    std::cout << "\n";

    return (0);
}
