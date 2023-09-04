# Untitled - By: 1 - 周三 8月 2 2023
'''
这是K210识别矩形所用的micropython代码
应该是用的原厂固件，如果报错的话就改刷maixpy固件
注意刷固件时应该在原厂固件的基础上直接覆盖maixpy固件
（只有maixpy固件才能跑训练出来的yolo v2模型）
'''
import sensor, image, time,lcd,utime
from fpioa_manager import fm
from machine import UART

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 2000)

sensor.set_jb_quality(100)
clock = time.clock()

lcd.init(freq=15000000, color=65535, invert=0)

#串口启动
fm.register(6,fm.fpioa.UART2_RX)
fm.register(8,fm.fpioa.UART2_TX)

uart=UART(UART.UART2, 115200, 8, 0, 0, timeout=1000, read_buf_len=4096)

def zeroFill(str):
   if len(str)==3:
        return str
   elif len(str)==2:
       return '0'+str
   elif len(str)==1:
       return '00'+str
   else:
       return '000'

while(True):
    clock.tick()
    img = sensor.snapshot()


    for r in img.find_rects(threshold = 10000):
        img.draw_rectangle(r.rect(), color = (255, 0, 0))
        cnt=0
        for p in r.corners():
            img.draw_circle(p[0], p[1], 5, color = (0, 255, 0))
            uart_str=''

            if cnt==3:
                uart_str='!'
            if cnt==2:
                uart_str='@'
            if cnt==1:
                uart_str='#'
            if cnt==0:
                uart_str='$'
            cnt=cnt+1
            uart_str+=zeroFill(str(p[0]))
            
            uart_str+=",,,"
            uart_str+=zeroFill(str(p[1]))
            #uart_str+='x'
            uart.write(uart_str)
            utime.sleep_ms(5)
            print(uart_str)
    img.draw_rectangle(53,12,96,97,thickness=1)



    lcd.display(img)
    #print(clock.fps())
