## 兼具蓝牙遥控和反射循迹功能的小车

io图：
![image](https://github.com/LiHuaOfficial/Car-for-EDC/assets/120998712/be72cb38-5b6c-46e0-9068-5c230625d074)

所用硬件：
+ 开发板         STM32f103RCT6  
+ 电机驱动       TB6612 精简板x2  
+ 蓝牙串口       HC05  
+ 循迹模块       YB-MVX01（四路红外循迹）  
+ 5V电源模块     SY8025  

蓝牙指令见/Core/Src/myIT 中的串口中断回调函数
