## 黑月核心静态库

[![BlackMoon Krnln](https://github.com/TheSnowfield/BlackMoonKernelStaticLib/workflows/BlackMoon%20Krnln/badge.svg)](#)
[![BlackMoon Krnln OBJ](https://github.com/TheSnowfield/BlackMoonKernelStaticLib/workflows/BlackMoon%20Krnln%20OBJ/badge.svg)](#)
[![BlackMoon MFC](https://github.com/TheSnowfield/BlackMoonKernelStaticLib/workflows/BlackMoon%20MFC/badge.svg)](#)

## 编译与安装
  1. 根据你电脑上所安装的VS版本，打开对应的工程文件
  2. 打开工程后能看见三个方案：krnln、krnln_Obj、MFCBlackMoon。  
    通常情况下你不需要理会后两者，除非你知道它的作用。选中krnln方案，切换配置为Release，并编译。
  3. 编译后，将release目录下的kernel.lib替换到易语言安装目录的  
  \BlackMoon\obj\kernel.lib。(黑月4.0以上版本)  
  \BlackMoon\lib\kernel.lib。(黑月4.0以下版本)

## 源码使用事项
  原则上，只要不是商业用途及非法用途，源码可以任意使用及传播，
  编译后的静态库文件kernel.lib可以用于编译链接到商业作品中。  
  在复制与传播时，必须注明开源地址：  
  https://github.com/zhongjianhua163/BlackMoonKernelStaticLib (国外服务器)  
  https://gitee.com/zhongjianhua163/BlackMoonKernelStaticLib (国内服务器)

## 代码编写规范
  如果你想参与更新、优化或修复BUG，请仔细阅读以下事项：
  1. 代码的必须能让所有版本的VS通过编译，若需要使用特定版本的VS的特性，
    则需要合理使用宏 _MSC_VER 来进行兼容。
  2. 变量、常量、函数等命名时尽量能准确表达其属性及用途。
  3. 少用或尽量不要用内联汇编。
    如果必须要用到内联汇编，则尽量不要使用新的指令集，如SSE\AVX等。
    如果必须要用到新的指令集，请务必做好自适配代码，确保老的CPU及远古级别的
    32位CPU能正常运行，并实现指定效果。(常规做法是编写两份代码，一份使用新
    的指令集，另一份使用常规指令集，并根据用户的CPU所支持的指令集来进行调用)
  4. 确保代码的简洁美观、高效、稳定及安全性。
  5. 确保函数的参数、返回值及运行效果与易语言原生核心库保持一致。
  6. 编辑的源代码文件的时候，请使用ANSI和GB2312编码，切勿使用UTF8或其他编码。
  7. 使用git来push前，请将自动替换换行符功能: autoCRLF 设置为 false。

## 参与贡献
  1. 可以加入此开源项目的管理团队
  2. 可以在GitHub或Gitee中通过Issues页面提交错误和改进建议
  3. 可以在GitHub或Gitee中`Fork`, 修改后通过`Pull Request`合并代码


## 许可证
原作者：云外归鸟  
后续升级：泪闯天涯(邓学彬)  
后续优化：被封七号  
  
根据 `BSD 3-Clause` 获得许可
