## 添加字体
1. /usr/share/fonts 文件夹下添加字体
2. 生成字体信息:

        sudo mkfontscale   
        sudo mkfontdir   
        sudo fc-cache -fv   

## 关闭启用触摸屏

    sudo rmmod psmouse  # 关闭
    sudo modprobe psmouse # 启用

## Python pip 源修改

    
    国内源:
    http://pypi.douban.com/
    http://pypi.douban.com/
    http://pypi.hustunique.com/
    http://pypi.mirrors.ustc.edu.cn/ 
    pip install package -i "http://pypi.douban.com/simple"
    or ~/.pip/pip.conf 文件下
    [global]
    index-url = http://pypi.douban.com/simple

## Remove ubuntu ppa

    sudo add-apt-repository --remove ppa:whatever/ppa

## Ubuntu unity 显示网速工具
    
    sudo add-apt-repository ppa:nilarimogard/webupd8
    sudo apt-get update
    sudo apt-get install indicator-netspeed
