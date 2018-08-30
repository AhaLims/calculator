<center> <h1> caculator </center>
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br />
<br /><br />
<br />
<br />
<br />
<br />

C++ project
<br />
<br />
Author:Lin Moxin
<br />
<br />
2018.9
<br />
<br />
<br />
<br />
<br />
<br />


## 本文档包括
> * caculator 的功能介绍
> * 如何使用caculator
> * 技术栈以及类
> * 关于caculator

### caculator 的功能介绍
<br />
caculator包括6个模块<br />

####  矩阵计算器
<br />
可以计算基本的矩阵性质 矩阵之间的运算，包括

> * 矩阵之间的加减乘除
> * 行列式
> * 逆矩阵（高斯消元法）
> * 转置矩阵
> * 秩
> * 对角矩阵
> * 三角矩阵
> * 特征向量 特征值 （雅可比....求的是正定矩阵）
> * 数乘
> * 矩阵的幂（使用快速幂加快运算速度）
####  科学计算器
<br />
实现数字运算，以及支持一些简单函数的运算，利用文件读写存储历史记录

#### 解线性方程
<br />

#### 多项式计算
<br />

#### 函数图像计算器（2D）
<br />
利用OpenGL绘制二维函数，可实现函数的平移缩放变换<br />

#### 24点计算器
<br />


### 如何使用caculator
点击.exe文件运行
#### 各模块的使用方法

##### 矩阵计算器
输入矩阵 每个元素之间用空格隔开，之后再点击界面的按钮，以计算使用者需要的功能

##### 科学计算器
输入计算式计算答案，不能省略符号

##### 2D函数图像计算器
输入变量 以及函数表达式，可以使用 'A' 'D' 'W' 'S'来进行图像的移动，使用'J' 'K'进行图像的缩放，'R'还原


**注意**：科学计算器和函数计算器中的函数表达式括号要配对，且括号需要是英文输入法下的括号


### 技术栈以及类
caculator是利用QT编写的软件，运用了线性代数的相关知识，以及栈，二叉树的数据结构编写
#### 类
1. 各个界面生成的类（caculator_gui, help_window，main_window，QT_OpenGL，SicenticCaculator_gui）
2. 2.Matrix class 进行矩阵的各种运算
3. Expression class:支持多个可自定义的参数，计算函数，通过外部接口getAns()得到答案
4. Function_2D class:传递OpenGL所需要的命令行参数，利用Express 类分析函数，由getAns()接口获得函数各点的数据，再利用OpenGL绘图
4. scientic_calculator：利用Expression类计算

### 关于caculator
这是一个暑期完成的学生作业，gitee地址(https://gitee.com/AhaLims/caculator)
