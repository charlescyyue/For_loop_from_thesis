# Psychec环境配置与初步使用指南（20230805）

Psychec是现有的唯一具有面向C语言类型推断功能的工具。由于该工具目前已经相对较老，而新版本正在开发中，暂不能使用类型推断功能，所以部分现在的编译器版本不支持该工具，导致编译运行过程中容易出现问题。本文件整理了psychec original branch环境配置的方法，方便后续使用psychec。

## Psychec运行需要：
- Cmake
- C++14 compiler
- Haskell stack toolchain

Cmake安装即可，版本没有明确限制。
C++14 compiler即gcc或clang
Haskell stack toolchain包含ghc-7.10.3、cabal（工具创建者推荐1.22.5版本）、stack。由于这些版本过于老旧，linux操作系统中通过apt指令可能无法安装到合适版本的ghc和cabal，可通过安装ghcup来管理版本。

## Ghcup
Ghcup安装分国外源、国内源两种方法。能够保证外网下载速度的可以考虑使用国外源，否则容易下载失败。
国外源：在https://www.haskell.org/ghcup/中获得安装指令，包含windows和linux两大类。安装过程中各选项可参考国内源安装方法。
国内源：仅查找了linux安装方法，参考https://zhuanlan.zhihu.com/p/455688955安装。注意安装命令和ghcup源配置中ghcup-0.0.6.yaml应改为ghcup-0.0.7.yaml。

安装成功后新建终端，输入ghcup tui。选择ghc 7.10.3安装。cabal我选择了2.4.1.0安装。安装成功后即可尝试运行psychec了。方法如original branch (https://github.com/ltcmelo/psychec/tree/original)中给出的方法。