#include "param.h"

void conv1(f_32 in[32][32], f_32 Kw_1[6][5][5], f_32 Kb_1[6], f_32 out[28][28][6])
{
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) { 
            for (int x = 0; x < 5; x++) {              
                for (int y = 0; y < 5; y++) {
                    for (int k = 0; k < 6; k++) {
                        out[i][j][k] += in[i + x][j + y] * Kw_1[k][x][y];                       
                    }
                }            
            }
        }
    }
    
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                out[i][j][k] += Kb_1[k];
            }
        }
    }
}

void conv2(f_32 in[14][14][6], f_32 Kw_2[16][6][5][5], f_32 Kb_2[16], f_32 out[10][10][16])
{
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            for (int x = 0; x < 5; x++) 
                {
                 for (int y = 0; y < 5; y++) 
                    {
                     for (int set = 0; set < 2; set++)
                     {
                         for (int k = 0; k < 8; k++)
                         {
                             for (int c = 0; c < 6; c++)
                             {
                                 out[i][j][k + set * 8] += in[i + x][j + y][c] * Kw_2[k + set * 8][c][x][y];
                             
                             }
                         }                              
                     }
                 }
            }
        }
    }


    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int set = 0; set < 2; set++)
            {
                for (int k = 0; k < 8; k++)
                {
                    out[i][j][k + set * 8] += Kb_2[k + set * 8];
                }
            }
        }
    }

}

void conv3(f_32 in[5][5][16], f_32 Kw_3[120][16][5][5], f_32 Kb_3[120], f_32 out[1][1][120])
{
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            for (int x = 0; x < 5; x++)
            {
                for (int y = 0; y < 5; y++)
                {
                    for (int set = 0; set < 15; set++)
                    {
                        for (int k = 0; k < 8; k++)
                        {
                            for (int c = 0; c < 16; c++)
                            {
                                out[i][j][k + set * 8] += in[i + x][j + y][c] * Kw_3[k + set * 8][c][x][y];

                            }
                        }
                    }
                }
            }
        }
    }


    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            for (int set = 0; set < 15; set++)
            {
                for (int k = 0; k < 8; k++)
                {
                    out[i][j][k + set * 8] += Kb_3[k + set * 8];
                }
            }
        }
    }

}

