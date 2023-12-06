#include "param.h"

void reshape(f_32 in[1][1][120],f_32 out[120])
{	

	int m = 0;
			for (int k = 0; k < 120; k++)
			{
				out[m] = in[0][0][k];
				m++;
			}	
}

//void fc1(f_32 in[120],f_32 fc1_w[84][120], f_32 fc1_b[84],f_32 out[84])
//{
//
//	for (int i = 0; i < 84; i++)
//	{
//		out[i] = 0; 
//		for (int set=0 ; set < 15; set++)
//		{
//			for (int j = 0; j < 8; j++)
//			{
//				out[i] += in[j + set * 15] * fc1_w[i][i + set * 15];
//			}
//		}
//	}
//
//	for (int i = 0; i < 84; i++)
//	{
//		out[i] += fc1_b[i];
//		if (out[i]<0)
//		{
//			out[i] = 0;
//		}
//	}
//}
// 
// 
//void fc2(f_32 in[84], f_32 fc2_w[10][84], f_32 fc2_b[10], f_32 out[10])
//{
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int set=0; set < 21; set++)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				out[i] += in[j + set * 21] * fc2_w[i][i + set * 21];
//			}
//		}
//	}
//
//	for (int i = 0; i < 84; i++)
//	{
//		out[i] += fc2_b[i];
//		if (out[i] < 0)
//		{
//			out[i] = 0;
//		}
//	}
//}

void fc1(f_32 in[120], f_32 fc1_w[84][120], f_32 fc1_b[84], f_32 out[84])
{
	for (int i = 0; i < 84; i++)
	{
		out[i] = 0; // 将 out[i] 初始化为0

		for (int j = 0; j < 120; j++)
		{
			out[i] += in[j] * fc1_w[i][j]; // 累加和计算
		}
	}

	for (int i = 0; i < 84; i++)
	{
		out[i] += fc1_b[i];
		if (out[i] < 0)
		{
			out[i] = 0;
		}
	}
}


void fc2(f_32 in[84], f_32 fc2_w[10][84], f_32 fc2_b[10], f_32 out[10])
{
	for (int i = 0; i < 10; i++)
	{
		out[i] = 0; // 将 out[i] 初始化为0

		for (int j = 0; j < 84; j++)
		{
			out[i] += in[j] * fc2_w[i][j]; // 累加和计算
		}
	}

	for (int i = 0; i < 10; i++)
	{
		out[i] += fc2_b[i];
		if (out[i] < 0)
		{
			out[i] = 0;
		}
	}
}

void softmax(f_32 in[10], f_32 out[10])
{

	
	f_32 max_val = in[0];
	f_32 sum = 0.0;


	// 找到in中的最大值
	for (int i = 1; i < 10; i++)
	{
		if (in[i] > max_val)
			max_val = in[i];
	}

	// 计算softmax值，并累加求和
	for (int i = 0; i < 10; i++)
	{
		out[i] = expf(in[i] - max_val);
		sum += out[i];
	}

	// 归一化处理，得到最终的softmax输出
	for (int i = 0; i < 10; i++)
	{
		out[i] /= sum;
	}
}