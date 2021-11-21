close all
clear all
a=dlmread('temp-test-20211113_1649.log',',');

v1 = []
v2 = []
v3 = []
v4 = []
v1i = 1
v2i = 1
v3i = 1
v4i = 1

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
hold on
for i=1:6
  plot(v1(:,1), v1(:,2+i))
end

figure
hold on
for i=1:6
  plot(v2(:,1), v2(:,2+i))
end

figure
hold on
for i=1:6
  plot(v3(:,1), v3(:,2+i))
end

figure
hold on
for i=1:6
  plot(v4(:,1), v4(:,2+i))
end
