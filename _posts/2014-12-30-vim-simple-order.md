---
layout: post
title: Vim 学习
tag: vim, note
---
{{ page.title }}
============

1.  移动
--------------

1.  CTRL-U 向下滚半屏  
2.  CTRL-D 向上滚半屏  
3.  CTRL-F 向下滚全屏  
4.  CTRL-B 向上滚全屏  
5.  CTRL-E 向上滚  
6.  CTRL-Y 向下滚  
7.  "*" 向下查找当前光标下的word, "#" 向上查找  
8.  "\<word\>" 查找整个word  
9.  "\`\`" 最新的两个跳转点之间切换  
10. 跳转定义:执行一个命令使光标定位于当前行之外的某行上去,这都叫一个跳转,"j","k"不是跳转  
11. -------1------2----3-----时间线上的跳转点, CTRL-O跳转到更早时间的光标位置, CTRL-I(或tab)跳转  
12. "m{mark}"标记位置, "\`{mark}"  

2.  小幅改动
------------

更改文本三种方式:    
1.  操作符+位移命令  
2.  Visual模式   
3.  操作符+文本对象  

0. d{count}w, d$ = D删除到相应位移的终点, c{count}w, c$ 删除并切换置插入模式  
1. dd 删除整行, cc 删除整行但保留缩进  
2. x = dl, X = dh, D = d$, C = c$, s = cl, S = cc;  
3. visual模式下"o"光标在所选区域角线之间切换, "O"左右切换  
4. daw: 删除一个单词 cis: 删除一个句子然后Insert.  
5. 文本对象: aw, iw, as, is  
6. 在Replace模式下<backspace>键, 可以恢复原来的字符  
7. '~' 切换大小写  
8. 'I' 所在行第一个非空白字符处并Insert模式, 'A' 行末Insert  
9.  di[标记], di( 删除圆括号内的内容, 类似di{, di", di' 
10. dt[标记], 删除当前光标到标记之间的内容
11. :w !sudo tee % 以root方式保存
12. guu 行小写 gUU 行大写 g~~ 行翻转, gUw/gUe 字大写, guw/gue 字小写
13. g是大小写转换命令(greate), u/U/~(小写/大写/翻转)

3.  定制vimrc
-------------

1.  `set nocompatible` vim增强模式，不完全兼容vi
2.  `set backspace=indent, eol, start` Insert模式下backspace键何时可以删除字符,   
    indent:删除set indent; set ai等自动缩进, eol:删除断行, start:用于删除进入Insert模式之前的字符  

