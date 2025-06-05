up_ideal = 0.15;
Ts_ideal = 0.5;

qsi = -log(up_ideal) / sqrt(pi^2 + (log(up_ideal))^2);
sigma = 4/Ts_ideal;
w_n = sigma/qsi;
W_d = w_n* sqrt(1-qsi^2);
Sd = -sigma + W_d * 1j