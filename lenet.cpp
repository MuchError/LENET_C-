#include "param.h"

f_32 C1_out[28][28][6];
f_32 C1_Rout[28][28][6];
f_32 P1_out[14][14][6];
f_32 C2_out[10][10][16];
f_32 C2_Rout[10][10][16];
f_32 P2_out[5][5][16];
f_32 C3_out[1][1][120];
f_32 C3_Rout[1][1][120];
f_32 Re_out[120];
f_32 FC1_out[84];
f_32 FC2_out[10];


void lenet(f_32 in[32][32], f_32 Cout[10])
{
	
	f_32 K1_W[6][5][5] = {
		#include "c1_weights.h"
	};
	f_32 K1_B[6] = {
		#include "c1_bias.h"
	};
	f_32 K2_W[16][6][5][5] = {
		#include "c2_weights.h"
	};
	f_32 K2_B[16] = {
		#include "c2_bias.h"
	};
	f_32 K3_W[120][16][5][5] = {
		#include "c3_weights.h"
	};
	f_32 K3_B[120] = {
		#include "c3_bias.h"
	};
	f_32 FC1_W[84][120] = {
		#include "fc1_weights.h"
	};
	f_32 FC1_B[120] = {
		#include "fc1_bias.h"
	};
	f_32 FC2_W[10][84] = {
		#include "fc2_weights.h"
	};
	f_32 FC2_B[10] = {
		#include "fc2_bias.h"
	};

	conv1(in, K1_W,	K1_B,C1_out);
	relu1(C1_out, C1_Rout);
	pool1(C1_Rout, P1_out);
	conv2(P1_out, K2_W, K2_B, C2_out);
	relu2(C2_out, C2_Rout);
	pool2(C2_Rout, P2_out);
	conv3(P2_out, K3_W, K3_B,C3_out);
	relu3(C3_out, C3_Rout);
	reshape(C3_Rout, Re_out);
	fc1(Re_out, FC1_W, FC1_B, FC1_out);
	fc2(FC1_out, FC2_W, FC2_B, FC2_out);
	softmax(FC2_out, Cout);

	
}

int main() {

	f_32 in[32][32] = {
		#include "in1.h"
	};
	
	f_32 Cout[10];
	lenet(in,Cout);
	for (int k = 0; k < 10; k++) {
		std::cout << "out[" << k << "] = " << Cout[k] << std::endl;
	}	
	return 0;
} 

//int main() {
//	//²âÊÔ
//	test();
//	return	0;
//}

