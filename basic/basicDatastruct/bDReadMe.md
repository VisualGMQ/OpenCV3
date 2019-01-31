### 关于opencv3中基础数据结构的说明
***
**Point类**
Point类的根模板是Point2_\<T\>模板和Point3_\<T\>模板。这两个模板分别对应平面点和空间点
传统的Point2_\<\>有
* Point2d
* Point2f
* Point2i
* Point2l

Point3_\<\>也是如此

需要注意的成员函数为ddot和dot。两个都表示点积。区别在于dot返回值类型是和Point的类型一样的。ddot则是一定返回double类型。
Point可以由对应的Vec转换过来
***
**Scalar**
Scalar的根模板是Scalar_\<T\>。Scalar_\<\>只能包含4个成员，并且每个成员类型必须一样。你可以只指定前两个成员，这样后面两个默认为0.
Scalar_\<\>只能够由Scalar_\<\>转换过来。
Scalar其实是Scalar_<double>
Scalar自己的成员函数只有下面几个:
* conj
* isReal
* mul
但是由于继承了Vec_\<\>，所以有很多继承的操作。

Scalar_\<\>是继承Vec\<\>的
***
**Size**
Size类的根模板是Size_\<T\>。其内部维护一个Point_\<\>来实现。
Size类由一些特化：
* Size2d
* Size2f
* Size2i==Size
* Size2l
Size_\<\>的操作也很简单：
* area
* empty
另外可以通过height,width属性获得信息。
***
**Rect**
根模板为Rect_\<T\>。
特化为:
* Rect2i==Rect
* Rect2d
* Rect2f
***
**RotatedRect**
RotateRect旋转矩形类，没有根模板。
***
**Matx<>**
Matx\<\>固定矩阵类，是Vec\<\>和Scalar_\<\>的根类。继承关系为：
```Scalar_<>-->Vec<T,4>-->Matx<T,cn,1>```
Matx类最多可以接受16个参数作为矩阵（或者向量，因为他存储矩阵是行优先的）的元素。最少0个。
Matx也可以使用这样的方法来构造任意大小的矩阵:Matx<Type,Rol,Column>
Matx的特化很多:
* Matx12d
* Matx22f
* Matx66d
等等等其中两个数字最大取6.但是不是这之间的所有搭配都存在的，比如Matx65f。
获得Matx元素的方法只有通过成员变量val。这个变量将元素按行排列成数组返回（数组类型为double）。
***
**Vec\<\>类**
Vec\<\>继承自Matx\<T,n,1\>，为固定向量类。
Vec重载了了operator[]，你可以通过下标访问它的成员。
Vec也有特化：
* Vec3b
* Vec2i
* Vec3s
* Vec3w 
等等等
w-unsigned short;b-usigned char;s-short
***
**Range**
Range类用来生成一个[start,end]的整数序列。其构造函数为Range(start,end)。操作也只有:
* empty()
* size()
属性也只有end,start
***
**RNG随机数发生器**
RNG虽然是个类，但是其实是一个随机数发生器。
这个类可以直接生成随机数：
* gaussian(sigma)通过sigma获得一个高斯分布随机数
* next()获得下一个随机数
* fill()用随机数填充mat
* uniform(a,b)通过均匀分布获得一个随机数。
还可以进行各种强制转换从而产生随机数，因为其重写了operator double()等函数

