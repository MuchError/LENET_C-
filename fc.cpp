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
		out[i] = 0; // �� out[i] ��ʼ��Ϊ0

		for (int j = 0; j < 120; j++)
		{
			out[i] += in[j] * fc1_w[i][j]; // �ۼӺͼ���
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
		out[i] = 0; // �� out[i] ��ʼ��Ϊ0

		for (int j = 0; j < 84; j++)
		{
			out[i] += in[j] * fc2_w[i][j]; // �ۼӺͼ���
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


	// �ҵ�in�е����ֵ
	for (int i = 1; i < 10; i++)
	{
		if (in[i] > max_val)
			max_val = in[i];
	}

	// ����softmaxֵ�����ۼ����
	for (int i = 0; i < 10; i++)
	{
		out[i] = expf(in[i] - max_val);
		sum += out[i];
	}

	// ��һ�������õ����յ�softmax���
	for (int i = 0; i < 10; i++)
	{
		out[i] /= sum;
	}
}