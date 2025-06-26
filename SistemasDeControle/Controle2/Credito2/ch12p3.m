'(ch12p3) Exemplo 12.4' % Exibe o título.
clf % Apaga o gráfico na tela.
A=[-5 1 0;0 -2 1;0 0 -1]; % Define a matriz de sistema A
B=[0;0;1]; % Define a matriz de entrada B.
C=[-1 1 0]; % Define a matriz de saída C.
D=0; % Define a matriz D.
pup=input ('Digite %UP desejada');
% Entra a ultrapassagem
% percentual desejada.
Ts=input('Digite o tempo de acomodação desejado');
% Entra o tempo de acomodação desejado.
z=(-log(pup/100))/(sqrt(pi^2+log(pup/100)^2));
% Calcula o fator de amortecimento
% requerido.
wn=4/(z*Ts); % Calcula a frequência natural requerida.
[num,den]=ord2(wn,z); % Produz um sistema de segunda ordem que
% atende aos requisitos do transitório.
r=roots(den); % Usa o denominador para
% especificar os polos dominantes.
polos=[r(1) r(2) -4]; % Especifica a posição de todos os polos.
K=acker(A,B,polos) % Calcula os ganhos do controlador.
Anew=A-B*K; % Cria a matriz A compensada.
Bnew=B; % Cria a matriz B compensada.
Cnew=C; % Cria a matriz C compensada.
Dnew=D; % Cria a matriz D compensada.
Tee=ss(Anew,Bnew,Cnew,Dnew); % Cria um objeto espaço de estados LTI.
'T(s)' % Exibe o título.
T=tf (Tee); % Cria T(s).
T=minreal (T) % Cancela termos comuns e exibe T(s).
polos=pole (T) % Exibe os polos de T(s).
step (Tee) % Produz a resposta ao degrau compensada.
title ('Resposta ao Degrau Compensada')
% Adiciona um título à resposta
% ao degrau compensada.
pause