# STM32-Album
Lifecat系统之STM32开发--STM32读取SD卡显示JPG图片实现

## 嵌入式相册系统

基于stm32芯片进行开发，采用480*320分辨率内置显存模块的LCD显示屏模块，使用stm32芯片内置的FSMC模拟8080接口时序从而驱动LCD。通过FatFS文件系统进行SD存储空间的管理。

### 主要功能

  1.通过FatFS方式读取Fat32格式SD卡中的jpg图片数据。通过FatFS系统从已格式化为Fat32文件系统的SD卡中读取图片数据流，通过二进制流方式按照FSMC时序，以行的方式传输到LCD显示屏内置的显存中，传输完成后刷新缓冲区从而实现显示图片的功能。

  2.通过stm32的FSMC模拟8080时序驱动LCD显示屏显示图片。通过循环进行图片的刷新播放，实现了自动循环播放的功能。程序使用C语言编写，使用stm32提供的库函数进行硬件配置与操作。

  3.通过循环函数以及延时函数实现循环播放图片功能

  4.通过KEY1按键复位程序

![image](https://img-blog.csdn.net/20180510171637866?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dzaDU5NjgyMzkxOQ==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

![image](https://img-blog.csdn.net/20180510171458670?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dzaDU5NjgyMzkxOQ==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

![image](https://img-blog.csdn.net/20180510171458670?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dzaDU5NjgyMzkxOQ==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
