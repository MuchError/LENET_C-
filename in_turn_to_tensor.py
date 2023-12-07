###
# 此代码用于读取Mnist数据集的图片
# 并将其转换为tensor张量
# 以行的形式存储在txt文本中
###

import torchvision
from torchvision import transforms
import numpy as np

# 加载MNIST测试集
test_dataset = torchvision.datasets.MNIST(root='./data', train=False,
                                          transform=transforms.Compose([
                                              transforms.Resize((32, 32)),
                                              transforms.ToTensor(),
                                          ]), download=True)

# 获取第几张测试图片及其标签
image, label = test_dataset[9]
print("标签: ", label)

# 将图像转换为数组形式并重塑为2D数组
image_array = image.numpy()
image_array = image_array.reshape((32, 32))

# 存储图像为.txt文件，元素以逗号分隔
np.savetxt('9.txt', image_array, delimiter=',\n', fmt='%f')

with open('9.txt', 'r') as f:
    lines = f.readlines()
    for i in range(-1, 992, 32):
        lines[i] = lines[i].rstrip() + ',\n'
    lines[1023] = lines[1023].rstrip(',\n')
with open('9.txt', 'w') as f:
    f.writelines(lines)
