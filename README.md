# lifecat-stm32

> 基于STM32(秉火指南者开发板)+LCD显示屏，实现电子相册功能，循环播放SD卡中图片

## Instructions

> 基于stm32芯片进行开发，采用480*320分辨率内置显存模块的LCD显示屏模块，使用stm32芯片内置的FSMC模拟8080接口时序从而驱动LCD。通过FatFS文件系统进行SD存储空间的管理。

## Functions
```
1 通过FatFS方式读取Fat32格式SD卡中的jpg图片数据。通过FatFS系统从已格式化为Fat32文件系统的SD卡中读取图片数据流，通过二进制流方式按照FSMC时序，以行的方式传输到LCD显示屏内置的显存中，传输完成后刷新缓冲区从而实现显示图片的功能。

2 通过stm32的FSMC模拟8080时序驱动LCD显示屏显示图片。通过循环进行图片的刷新播放，实现了自动循环播放的功能。程序使用C语言编写，使用stm32提供的库函数进行硬件配置与操作。

3 通过循环函数以及延时函数实现循环播放图片功能

4 通过KEY1按键复位程序
```

  ![image](https://github.com/kevinten10/Stm32-lifecat/blob/master/show.png)
  
## Demo

![image](https://github.com/kevinten10/Stm32-lifecat/blob/master/show1.png)

## LifeCat系列总览

[LifeCat系列学习项目](https://github.com/kevinten10/LifeCat)

如果觉得有用，可以帮忙点一下star，谢谢啦！