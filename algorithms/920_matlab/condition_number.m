A = [0 1/2; 1/2 0];
x1 = [10^10; 10^10];
x2 = [10^10; 1];
X = {x1, x2};

for i = 1:2
    x = X{i};
    Ax = A * x;              
    norm_Ax = norm(Ax, 2);     
    norm_x = norm(x, 2);       
    f_x = x' * A * x;          
    K = (2 * norm_Ax * norm_x) / abs(f_x);
    disp(['Relative condition number K for x', num2str(i), ' = ', num2str(K)]); 
end
