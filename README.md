# Kernel-Module-test-version-
//这是操作系统第一次实验的测试内容，只是验证了编写内核模块-撰写应用测试程序-使用strace跟踪调试的过程，内核模块本体只是hello world的程度（囧）。

# 前置
  在进行本次实验之前，我们需要先下载对应Linux版本的源码并配置，我这里的版本是5.15.0-139-generic，Ubuntu的版本是20.04。
  示例过程：
  ```
sudo apt update
sudo apt install build-essential libncurses-dev bison flex libssl-dev libelf-dev
uname -r  # 查看自己的版本，比如输出 5.15.0-139-generic
cd /usr/src
sudo wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.15.139.tar.xz
sudo tar -xJf linux-5.15.139.tar.xz # 解压
cd linux-5.15.139
sudo cp /boot/config-5.15.0-139-generic .config # 复制当前配置
sudo make olddefconfig # 适配配置
  ```
  如果接下来出现了HOSTCC一大串的话，大概就是成功啦，可以正式进入了！

# 正式实验
  ```
mkdir kernel_exp_test
cd kernel_exp_test
gedit hello.c # 这是内核代码
gedit Makefile
make # 这个时候出来的.ko结尾的文件就是内核模块了
sudo insmod hello.ko # 加载模块（要输密码）
dmesg | tail -5 # 看结果（根据这里的hello.c，会输出 Kernel module loading successful！）
gedit test.c # 这是测试程序
gcc test.c -o test
strace ./test > strace_log.txt 2>&1 # 生成strace日志到文件，错误也一块保存
  ```
这样走下来就是这里叽里咕噜的一大串文件了。
