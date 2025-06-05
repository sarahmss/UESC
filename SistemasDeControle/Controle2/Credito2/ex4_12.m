s = tf('s');
si = s * eye(2); 
A = [0 1;
    -8 -6];

B = [   0;
        1];
C = [1 3]; 

u = 1/(s+1);

x_0 =  [    1;
            0];

si_A = inv(si - A)
X_s = si_A* (x_0 + B * u);
zpk(X_s)
y =  C  * X_s
% yt = ilaplace(y)