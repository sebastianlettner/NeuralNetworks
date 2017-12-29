function [] = plot_NN_function()

y1 = dlmread('file.txt');


x1 = -10:0.01:10;

hold on
plot(x1,y1);
%plot(x2,y2);

axis([-10 10 -50 50]);
hold off

end