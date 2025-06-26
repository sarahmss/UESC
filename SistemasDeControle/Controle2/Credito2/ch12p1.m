'(ch12p1) Exemplo 12.1' % Exibe o título.
clf % Apaga o gráfico na tela.
numg=20*[1 5]; % Define o numerador de G(s).
deng=poly([0 -1 -4]); % Define o denominador de G(s).
'G(s) sem compensação' % Exibe o título.
G=tf (numg,deng) % Cria e exibe G(s).
pup=input ('Digite %UP desejada');
% Entra a ultrapassagem
% percentual desejada.
Ts=input('Digite o tempo de acomodação desejado');
% Entra o tempo de acomodação desejado.
z=(-log(pup/100))/(sqrt(pi^2+log(pup/100)^2));
% Calcula o fator de amortecimento
% requerido.
wn=4/(z*Ts); % Calcula a frequência natural
% requerida.
[num,den]=ord2(wn,z); % Produz um sistema de
% segunda ordem que atende aos
% requisitos de resposta transitória.
r=roots(den); % Usa o denominador para
% especificar os polos dominantes.
polos=[r(1) r(2) -5.1]; % Especifica a posição de todos
% os polos.
eq_caracteristica_desejada=poly(polos)
% Cria o polinômio característico
% desejado para exibir na tela.
[Ac Bc Cc Dc]=tf2ss(numg,deng);
% Obtém a forma canônica
% controlável da representação
% no espaço de estados de G(s).
P=[0 0 1;0 1 0;1 0 0]; % Matriz de transformação
% da forma canônica controlável
% para a forma de variáveis de fase.
Ap=inv (P)*Ac*P; % Transforma Ac para a
% forma de variáveis de fase.
Bp=inv (P)*Bc; % Transforma Bc para a
% forma de variáveis de fase.
Cp=Cc*P; % Transforma Cc para a
% forma de variáveis de fase.
Dp=Dc; % Transforma Dc para a
% forma de variáveis de fase.
Kp=acker(Ap,Bp,polos) % Calcula os ganhos do controlador
% na forma de variáveis de fase.
Apnew=Ap-Bp*Kp; % Cria a matriz A compensada.
Bpnew=Bp; % Cria a matriz B compensada.
Cpnew=Cp; % Cria a matriz C compensada.
Dpnew=Dp; % Cria a matriz D compensada.
[numt,dent]=ss2tf (Apnew,Bpnew,Cpnew,Dpnew);
% Cria o numerador e o denominador
% de T(s).
'T(s)' % Exibe o título.
T=tf (numt,dent) % Cria e exibe T(s).
polos=roots (dent) % Exibe os polos de T(s).
Tee=ss (Apnew,Bpnew,Cpnew,Dpnew)
% Cria e exibe Tee, um
% objeto espaço de estados LTI.
step(Tee) % Produz a resposta ao degrau
% compensada.
title('Resposta ao Degrau Compensada')
% Adiciona um título à resposta
% ao degrau compensada.
pause