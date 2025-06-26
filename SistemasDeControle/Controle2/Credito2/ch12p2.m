'(ch12p2) Exemplo 12.2' % Exibe o título.
A=[-1 1 0;0 -1 0;0 0 -2] % Define a matriz A compensada.
B=[0;1;1] % Define a matriz B compensada.
Cm=ctrb(A,B) % Calcula a matriz de controlabilidade.
Rank=rank(Cm) % Determina o posto da matriz de
% controlabilidade.
pause