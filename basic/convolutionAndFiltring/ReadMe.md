### 关于Sobel的注意事项
***
Sobel函数虽然规定xorder,yorder可以取值0,1,2，但是这是受到核大小的限制的：
* ksize=3:需要满足xorder+yorder=1
* ksize=5:需要满足xorder+yorder<=3
* ksize=7:需要满足xorder+yorder<=4
