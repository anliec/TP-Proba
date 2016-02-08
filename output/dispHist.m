function [ x ] = dispHist( bean )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

hist(randValue(), bean);
hist(aesValue(), bean);
hist(vnValue(), bean);
hist(mtValue(), bean);

end

