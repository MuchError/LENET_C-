# LENET_C+
base on Visual Studio@2022
使用C/C++实现了lenet5网络模型的前向传播
## 训练模型并提取参数
权重参数weights/bias由pytorch框架训练后使用netron进行提取，导出为.npy,再通过python脚本进行转换，最终保存为..._weights/bias.h
