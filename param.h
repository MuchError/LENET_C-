#ifndef _PARAM_H
#define	_PARAM_H
//////////////////头文件//////////////////
#include <iostream>
#include <math.h>
#include <iostream>
#include <stdio.h>

//////////////////自定义//////////////////
typedef float f_32;		// 数据类型
using namespace std;	// 命名空间

void conv1(f_32 in[32][32], f_32 Kw_1[6][5][5], f_32 Kb_1[6], f_32 out[28][28][6]);
void relu1(f_32 a[28][28][6], f_32 b[28][28][6]);
void pool1(f_32 in[28][28][6], f_32 out[14][14][6]);
void conv2(f_32 in[14][14][6], f_32 Kw_2[16][6][5][5], f_32 Kb_2[16], f_32 out[10][10][16]);
void relu2(f_32 a[10][10][16], f_32 b[10][10][16]);
void pool2(f_32 in[10][10][16], f_32 out[5][5][16]);
void conv3(f_32 in[5][5][16], f_32 Kw_3[120][16][5][5], f_32 Kb_3[120], f_32 out[1][1][120]);
void relu3(f_32 a[1][1][120], f_32 b[1][1][120]);
void reshape(f_32 in[1][1][120], f_32 out[120]);
void fc1(f_32 in[120], f_32 fc1_w[84][120], f_32 fc1_b[84], f_32 out[84]);
void fc2(f_32 in[84], f_32 fc2_w[10][84], f_32 fc2_b[10], f_32 out[10]);
void softmax(f_32 in[10], f_32 out[10]);

void test();
void conv2_test();
void conv3_test();


#endif // !_PARAM_H

