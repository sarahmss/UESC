clear
close all
clc
%% Discretização "exata"
Ts = 0.002; % periodo de amostragem
A = [0 -2;1 -3];
B = [2;0];
C = [0 3];
sys = ss(A,B,C,[]);

sysd = c2d(sys,Ts,'zoh');
Ad = sysd.A; Bd = sysd.B; Cd = sysd.C;

%% Simulação
uk = 1; % valor da entrada
nsim = 5000; % nº de instantes de simulação 
xk = [1; 1];% condição inicial do modelo exato
xk_ap = [1; 1]; % condição inicial do modelo aproximado
y(1) = C*xk;
y_ap(1) = C*xk_ap;
for i=1:nsim
    
    % Solução exata
    xk = Ad*xk + Bd*uk;
    yk = Cd*xk;
    y(i+1) = yk; % armazena a saida exata
    
    % Solução aproximada
    xk_ap = (eye(2)+(Ts*A))*xk_ap + Ts*B*uk;
    yk_ap = C*xk_ap;
    y_ap(i+1) = yk_ap; %armazena a saida aproximada
end
t = 0:Ts:nsim*Ts;
figure()
plot(t,y,'LineWidth',1.5)
hold on
plot(t,y_ap,'r:','LineWidth',1.5)
xlabel('tempo (s)')
ylabel('amplitude')
grid on
