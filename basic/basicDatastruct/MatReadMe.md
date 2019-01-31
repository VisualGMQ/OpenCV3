### Mat简述
***
Mat的构造函数最经典的是Mat(row,column,type)。其中type为CV_{8U,16S,16U,32S,32F,64F}[C{1,2,3}]
其中
```c++
8U-unsigned char;16U-unsigned short;32U-unsigned int
8S-char;16S-short;32S-int
32F-float
64F-double
```
后面如果加上Cx就是多少通道的(C-channel)
如果你想要创建更多的通道，可以使用类似CV_8UC(X)的宏.同样在16S,16U...后面加上C也可以构成类似的宏。

所谓通道，是指将多少列视为一列。比如3通道的2*4矩阵，其实列有4*3=12列。

Mat其实是有特化的：
* Mat{1,2,3,4}{b,d,f,i,s,2}用于简单构造一个可变向量

获得Mat内元素的方法有下面几个
* .at\<Type\>(row,column)获取一个元素
* .row(i);.col(i)获得一行或一列，返回Mat
* .row/colRange(start,end)返回一些行/列，返回Mat
* .diag(d),返回对角线元素，返回Mat。
* operator(Range rowrange,Range colrange)通过指定范围返回子矩阵。但是返回的矩阵不能修改
* .ptr()获取元素。
* 使用类似STL的迭代器(.begin\<\>(),.end\<\>())来迭代元素。对应迭代器类型Mat[Const]Iterator_\<\>
