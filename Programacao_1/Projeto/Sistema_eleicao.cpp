/*	    1.  Etapa 1: informar quantidade de candidatos
	            a) Preencher lista dos n candidatos
	                -->candidatos[n][2]: [n][0]= Nº do candidato; [n][1]: Nome do candidato
	                I)candidato 1:
	                II)candidato ...:
	                III)candidato n:
	            b) Exibir lista dos candidatos
	            c) Confirmar dados
	                I)Não: 1: sair 2: reiniciar eleição
	                II)Sim...
	            d) Cadastrar senha para autorizar votos.
	                I)!IMPORTANTE! O sistema requisitara a senha pra autorizar cada um dos votos.
	                II)Cadastre a senha agora
	                III)Repita a senha
	                IV) Senhas diferentes: senhas não coicidem!!  [1-sair | 2-reinserir senha]
	        2.  Etapa 2: Votação Em andamento
	            a) Senha para autorizar deposito do voto
	                I) Errada: [1-sair | 2-reinserir senha]
	                II) Correta:
	        3.  Etapa 3. --------CEDULA ELEITORAL------------------
	            a) Exibe nome e Número dos n candidatos
	            b) Insira o número do seu candidato:
	            c) Confirmar
	                I) Não: a) --> b) --> c)
	                II)Sim: Voto confirmado.
	            d) Encerrar votação?
	                I) Não: Etapa 2
	                II)Sim: 
	        4.  Etapa 4. --------Resultado da eleição------------------
*/

#include <iostream>
#include <string.h>
#include <locale.h>
#include <stdio.h>

int main(void)
{
	setlocale(LC_ALL,"portuguese");
	int 	n_cdt;
	int		i;
	char	option;
	char	senha1[20];
	char	senha2[20];

	option = 'n';
	std::cout << "------------SISTEMA DE VOTACAO ELETRONICA-------------\n";
	std::cout << "------------ETAPA 1: CADASTRO DE CANDIDATOS-------------------------\n";
	std::cout << "	Informe a quantidade de candidatos: ";
	std::cin >> n_cdt;
	char	lst_nome_cdts[n_cdt][20];
    int 	lst_num_cdts[n_cdt];
	while (option != 's')
	{	
		std::cout << "Agora preencha a lista dos " << n_cdt << " candidatos\n";
		for (i = 0; i < n_cdt; i++)
		{
			std::cout << "Nome do candidato: ";
			std::cin >> lst_nome_cdts[i];
			std::cout << "Número do candidato: ";
			std::cin >> lst_num_cdts[i];
		}
		std::cout << "ATENÇÃO: LISTA DOS CANDIDATOS\n";
		for (i = 0; i < n_cdt; i++)
			std::cout << "Candidato[" << i  +1 << "]: "<<"Nome: "<< lst_nome_cdts[i]<< " Número: " << lst_num_cdts[i] << "\n";
		std::cout << "Confirma os dados? (s/n)";
		std::cin >>option;
	}
	i = 0;
	while (strcmp(senha1, senha2))
	{
		if (i > 0)
			std::cout << "------SENHA NAO CONFERE!\n";
		std::cout << "Agora cadastre uma senha para autorizacao do voto \n";
		std::cout << "IMPORTANTE! O sistema requisitara a senha para autorizar cada um dos votos!\n";
		std::cout << "Cadastre a senha agora:\n";
		std::cin >>senha1;
		std::cout << "Repita a senha:\n";
		std::cin >>senha2;
		i++;
	}
	std::cout << "Votacao em andamento!!!!\n"; 
	std:: cout<<"Digite a senha para autorizar o deposito do voto:\n"; 
}