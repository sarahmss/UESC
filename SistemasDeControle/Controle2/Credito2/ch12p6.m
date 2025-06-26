'(ch12p6) Exemplo 12.8' % Exibe o título.
A=[-5 1 0;0 -2 1;0 0 -1]; % Define a matriz de sistema A.
B=[0;0;1]; % Define a matriz de entrada B.
C=[1 0 0]; % Define a matriz de saída C.
D=0; % Define a matriz D.
polos=roots ([1 120 2.500 50.000])
% Especifica a posição
% de todos os polos.
l=acker(A',C',polos)' % Calcula os ganhos do observador.
pause