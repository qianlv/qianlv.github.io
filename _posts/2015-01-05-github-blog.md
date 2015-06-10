---
layout: post
title: 搭建github博客教程
tag: github, blog 
---
{{ page.title }}
================

1. 创建一个github帐号
---------------------
*****
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1. [Github网址](https://github.com)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2. github入门教程直接google吧  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3. [Git使用教程](http://blog.csdn.net/hcbbt/article/details/11651229)  


2. 使用github page创建blog
-------------------------
***
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1. 创建一个名称username.github.io(username为你的用户名)的项目,这个就你的博客项目.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2. 此时有两种方法生成博客(推荐第二种方法)  

3. 第一个方法步骤:
----------------
***

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1.在前面username.github.io项目中,进入settings(如下图)  

![Alt github-settings](/images/github-blog-settings.png)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.然后在Automatic page generator按钮就生成一个github博客  

![Alt github-automatic](/images/github-blog-automatic.png)

4. 第二个方法步骤
----------------
***
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1. 本地搭建一个jekll  

        #安装ruby(1.9.3以上)
        sudo apt-get install ruby1.9.3
        ruby -v 
        #安装bundler
        #切换ruby的源，否则可能无法安装(已被G_F_W)
        gem sources --remove http://rubygems.org/
        gem sources -a http://ruby.taobao.org/ 
        gem sources -l 
        sudo gem install bundler
        #[详细安装方法参考]
        #(https://www.brightbox.com/docs/ruby/ubuntu/)
        #安装jekll 
        sudo gem install jekyll
        sudo gem install rdiscount #markdown解释器

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2. 学习jekll的使用  

> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[教程](http://www.ruanyifeng.com/blog/2012/08/blogging_with_jekyll.html),通过这个教程了解jekll各种目录的功能和使用,
通过前面本地安装的jekll查看是否成功 `jekll server` ，其实不必要完全搭建整个项目,了解jekll一些基本使用后可以fork别人的jekll模板.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3. 学习markdown语法  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[Markdown语法](http://wowubuntu.com/markdown/)

