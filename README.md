# UCAS-Data-Structure

#### 介绍
source codes for UCAS CS data structure course, including ADTs, OJ assignments and projects

#### ADT

ADT的编写主要参考课程所用教材^[严蔚敏，吴伟民：数据结构（C语言版），清华大学出版社]中的ADT要求，但不完全根据教材进行编写，视需求选择性编写函数/方法。ADT的push与本地编写情况同步。

#### OJ assignments

**此部分仅供参考，请勿用于不良行为。** 

数据结构课程的算法设计作业，上传代码为OJ系统中Accepted的代码，通常采用C++编写。

由于课程仍在进行、OJ题目仍在更新、OJ完成情况因人而异，本部分代码push频率将远低于ADT部分。

#### Projects

课程大作业，见[仓库](https://gitee.com/linzheng735803373/Data-Structure)

目前进度为：
1. 马踏棋盘：developing
2. 平衡二叉树(AVL树)：初版完成

#### About C++ and modern C++

本仓库更新的过程其实也是笔者不断学习C++语言乃至现代C++的过程，此处记录一部分在本仓库中的语言约定^[同时此部分也是笔者学习《C++ Primer Plus》、《Effective C++》等书的简要笔记]。

##### C++^[由于OJ Judger选用的C++标准为C++14，以下内容包括modern C++部分在内都会尽量以C++14为准]

1. C++的面向对象部分一般只应用`struct`，即所有成员默认都是`public`
2. 模板的编写一般仅用于ADT内，不在OJ Assignments和Projects中应用。

##### Modern C++

1. 字符串常量赋值给`const char *`而非`char *`
2. 不对`bool`类型使用`++`操作
3. 避免使用一些 C++ 弃用的 C 标准库，如`<ccomplex>`、`<cstdalign>`、`<cstdbool>`、`<ctgmath>`
4. 避免使用 C 风格的类型转换方式，而使用`static_cast`、`reinterpret_cast`、`const_cast`
   * 一个示例为：已有`int a = 10, b = 3;`
   * 则应使用`double result = static_cast<double>(a) / static_cast<double>(b);`
   * 而非`double result = (double)a / (double)b;`
5. 避免使用`void *`等 C 程序风格
6. 空指针使用`nullptr`而非`NULL`
    * 此处略加注解并作为学习笔记
    * 在 C 语言中，`NULL`被定义为`(void *)0`，而 C 语言支持将`void *`类型隐式地转换为其他类型的指针，故而事实上在 C 语言中使用`malloc`分配内存时无需强制类型转换
    * 在 C++ 中对类型转换有更为严格的要求，通常会将`NULL`定义为`0`，这将会导致支持重载的C++发生混乱，故而C++11引入`nullptr`常量来表示空指针
7. 数组长度常量的声明用`constexpr`修饰而非`const`
   * C++ 标准要求声明数组时长度为常量表达式，`const`为声明常数（“只读”），`constexpr`修饰常量表达式。

#### author

Gerald-Gui