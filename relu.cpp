#include "param.h"

void relu1(f_32 in[28][28][6], f_32 out[28][28][6]) 
{
	for (int i = 0; i < 28; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				if (in[i][j][k] < 0)
				{
					out[i][j][k] = 0;
				}
				else
				{
					out[i][j][k] = in[i][j][k];
				}
			
			}
		}
	}

}

void relu2(f_32 in[10][10][16], f_32 out[10][10][16])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				if (in[i][j][k] < 0)
				{
					out[i][j][k] = 0;
				}
				else
				{
					out[i][j][k] = in[i][j][k];
				}

			}
		}
	}

}

void relu3(f_32 in[1][1][120], f_32 out[1][1][120])
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			for (int k = 0; k < 120; k++)
			{
				if (in[i][j][k] < 0)
				{
					out[i][j][k] = 0;
				}
				else
				{
					out[i][j][k] = in[i][j][k];
				}

			}
		}
	}

}