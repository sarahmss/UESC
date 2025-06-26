'(ch12p5) Exemplo 12.6' % Exibe o título.
A=[0 1 0;0 0 1;-4 -3 -2] % Define a matriz A compensada.
C=[0 5 1] % Define a matriz C compensada.
Om=obsv (A,C) % Cria a matriz de observabilidade.
Posto=rank (Om) % Determina o posto da matriz de
% observabilidade.
pause