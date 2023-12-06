#include "param.h"

void test() {
    // 生成示例数据
    f_32 in[32][32] = {
    #include "in1.h"
    };
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
    f_32 out[28][28][6];
    f_32 R1_out[28][28][6];
    f_32 P1_out[14][14][6];
    f_32 C2_out[10][10][16];
    f_32 R2_out[10][10][16];
    f_32 P2_out[5][5][16];
    f_32 C3_out[1][1][120];
    f_32 R3_out[1][1][120];
    f_32 Re_out[120];
    f_32 FC1_out[84];
    f_32 FC2_out[10];
    f_32 S_out[10];

    // 进行卷积操作
    conv1(in, K1_W, K1_B, out);
    relu1(out, R1_out);
    pool1(R1_out, P1_out);
    conv2(P1_out, K2_W,K2_B,C2_out);
    relu2(C2_out, R2_out);
    pool2(R2_out, P2_out);
    conv3(P2_out, K3_W, K3_B, C3_out);
    relu3(C3_out, R3_out);
    reshape(R3_out, Re_out);
    fc1(Re_out, FC1_W, FC1_B, FC1_out);
    fc2(FC1_out, FC2_W, FC2_B, FC2_out);
    softmax(FC2_out, S_out);

    // 输出结果应(在全连接层之前)
   /* for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 120; k++) {
                std::cout << "out[" << i << "][" << j << "][" << k << "] = " << R3_out[i][j][k] << std::endl;
            }
        }
    }*/

    
            for (int k = 0; k < 10; k++) {
                std::cout << "out[" << k << "] = " << S_out[k] << std::endl;
            }

}




void conv2_test() {
    // 生成示例数据
    f_32 in[14][14][6];
    f_32 Kw_2[16][6][5][5];
    f_32 Kb_2[16];
    f_32 out[10][10][16];

    // 假设输入特征图和卷积核均初始化为1，偏置项初始化为0.1
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            for (int k = 0; k < 6; k++)
            {
                in[i][j][k] = 1;
            }

        }
    }
    for (size_t k = 0; k < 16; k++)
    {
        for (int c = 0; c < 6; c++) {
            for (int x = 0; x < 5; x++) {
                for (int y = 0; y < 5; y++) {
                    Kw_2[k][c][x][y] = 1;
                }
            }          
        }
        Kb_2[k] = 0.1;
    }

    // 进行卷积操作
    conv2(in, Kw_2, Kb_2, out);

    // 输出结果为5*5*6+0.1=150.1
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 16; k++) {
                    std::cout << "out[" << i << "][" << j << "][" << k << "] = " << out[i][j][k] << std::endl;
            }
        }
    }
}


void conv3_test() {
    // 生成示例数据
    f_32 in[5][5][16];
    f_32 Kw_3[120][16][5][5];
    f_32 Kb_3[120];
    f_32 out[1][1][120];

    // 假设输入特征图和卷积核均初始化为1，偏置项初始化为0.1
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 16; k++) {
                in[i][j][k] = 1;
            }
        }
    }
    for (int k = 0; k < 120; k++) {
        for (int c = 0; c < 16; c++) {
            for (int x = 0; x < 5; x++) {
                for (int y = 0; y < 5; y++) {
                    Kw_3[k][c][x][y] = 1;
                }
            }
        }
        Kb_3[k] = 0.1;
    }

    // 进行卷积操作
    conv3(in, Kw_3, Kb_3, out);

    // 输出结果为5*5*16+0.1=401
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 120; k++) {
                std::cout << "out[" << i << "][" << j << "][" << k << "] = " << out[i][j][k] << std::endl;
            }
        }
    }
}
