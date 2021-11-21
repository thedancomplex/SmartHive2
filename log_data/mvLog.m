close all
clear all
a=dlmread('temp-test-20211113_1649.log',',');

v1 = [];
v2 = [];
v3 = [];
v4 = [];
v1i = 1;
v2i = 1;
v3i = 1;
v4i = 1;

tt = a(1,1);
kk = 60*60*24;
sh = 1649/2400.0;

for i=1:length(a)
  ii = a(i,2);
  if (ii == 1)
    v1(v1i,:) = a(i,:);
    v1i += 1;
  elseif (ii == 2)
    v2(v2i,:) = a(i,:);
    v2i += 1;
  elseif (ii == 3)
    v3(v3i,:) = a(i,:);
    v3i += 1;
  elseif (ii == 4)
    v4(v4i,:) = a(i,:);
    v4i += 1;
  end
end

figure


for i=1:6
  subplot(4,1,1)
  hold on
  x = ((v1(:,1)-tt)/kk+sh);
  plot(x, v1(:,2+i))
  xticks([0:0.5:ceil(max(x))]);
  title("Frame 1 (No Paint)")
end
%lgd = legend({'Sensor 1', 'Sensor 2', 'Sensor 3', 'Sensor 4', 'Sensor 5', 'Sensor 6'},'FontSize',8);
%set(gca,'XTick',[]);

for i=1:6
  subplot(4,1,2)
  hold on
  x = ((v2(:,1)-tt)/kk+sh);
  plot(x, v2(:,2+i))
  xticks([0:0.5:ceil(max(x))]);
  title("Frame 2 (No Paint)")
end
%lgd = legend({'Sensor 1', 'Sensor 2', 'Sensor 3', 'Sensor 4', 'Sensor 5', 'Sensor 6'},'FontSize',10);
%set(gca,'XTick',[]);

for i=1:6
  subplot(4,1,3)
  hold on
  x = ((v3(:,1)-tt)/kk+sh);
  plot(x, v3(:,2+i))
  xticks([0:0.5:ceil(max(x))]);
  title("Frame 3 (With Paint)")
end
%lgd = legend({'Sensor 1', 'Sensor 2', 'Sensor 3', 'Sensor 4', 'Sensor 5', 'Sensor 6'},'FontSize',10);
%set(gca,'XTick',[]);

for i=1:6
  subplot(4,1,4)
  hold on
  x = ((v4(:,1)-tt)/kk+sh);
  plot(x, v4(:,2+i))
  xticks([0:0.5:ceil(max(x))]);
  title("Frame 4 (With Paint)")
end
%lgd = legend({'Sensor 1', 'Sensor 2', 'Sensor 3', 'Sensor 4', 'Sensor 5', 'Sensor 6'},'FontSize',10);
%suptitle("Temp Test 2021-11-13 to 2021-11-20")

print -color -depsc plots_test_2021-11-13_to_2021-11-20.eps
