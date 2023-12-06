#include "param.h"

void pool1(f_32 in[28][28][6], f_32 out[14][14][6]) 
{

	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				f_32 max = 0;
				for (int x = 0; x < 2; x++)
				{
					for (int y = 0; y < 2; y++)
					{
						if (in[2*i+x][2*j+y][k]>max)	//步长为2
						{
							max = in[2 * i + x][2 * j + y][k];
						}
					}
				}
				out[i][j][k] = max;
			}
		}
	}

}

void pool2(f_32 in[10][10][16], f_32 out[5][5][16])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				f_32 max = 0;
				for (int x = 0; x < 2; x++)
				{
					for (int y = 0; y < 2; y++)
					{
						if (in[2 * i + x][2 * j + y][k] > max)	//步长为2
						{
							max = in[2 * i + x][2 * j + y][k];
						}
					}
				}
				out[i][j][k] = max;
			}
		}
	}
}

