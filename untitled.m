data = [1,1,0,1,1,0,0,0,0,1,1,0,1,0,1,1,0,1,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,1,1,0,1,1,1,1]';
enc_data = nrPolarEncode(data, 144, 10, false);
gg = [1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,0,1,0,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,1,0,1,1,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,0,0,0,0,1,1,1,0,1,1,0,0,0,1,0,1]';
% modIn = nrRateMatchPolar(enc_data, 72, 144, false);
