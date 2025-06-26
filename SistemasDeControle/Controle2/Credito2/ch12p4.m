'(ch12p4) Exemplo 12.5' % Exibe o título.
numg=[1 4]; % Define o numerador de G(s).
deng=poly([-1 -2 -5]); % Define o denominador de G(s).
'G(s)' % Exibe o título.
G=tf(numg,deng) % Cria e exibe G(s).
[Ac,Bc,Cc,Dc]=tf2ss(numg,deng);
% Transforma G(s) para a
% forma canônica controlável,
% no espaço de estados.
Ao=Ac'; % Transforma Ac para a forma
% canônica observável.
Bo=Cc'; % Transforma Bc para a forma
% canônica observável.
Co=Bc'; % Transforma Cc para a forma
% canônica observável.
Do=Dc; % Transforma Dc para a forma
% canônica observável.
r=roots([1 2 5]) % Obtém os polos do sistema
% compensado com controlador.
polos=10*[r' 10*real(r(1))] % Faz os polos do observador
% 10x maiores.
lp=acker(Ao',Co',polos)' % Obtém os ganhos do observador
% na forma canônica observável.
pause