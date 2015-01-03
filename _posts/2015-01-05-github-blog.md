---
layout: post
title: 搭建github博客教程
tag: github, blog 
---
{{ page.title }}
================

1. 创建一个github帐号
---------------------
1. [github](https://github.com)
2. github入门教程直接google吧
3. [Git使用教程](http://blog.csdn.net/hcbbt/article/details/11651229)

2. 使用github page创建blog
-------------------------
1. 创建一个名称username.github.io(username为你的用户名)的项目，这个就你的博客项目。
2. 此时有两种方法生成博客(推荐第二种方法)
    `
    1. 使用github自动生成一个blog项目,
    2. 自己配置一个jekll项目(__github page使用的就是jekll生成静态页面__)
    `
3. 第一个方法步骤:
1. 在前面username.github.io项目中,进入settings(如下图红圈位置)
[!Alt github-settings](/images/github-blog-settings.png)
2. 然后在Automatic page generator按钮就生成一个github博客
[!Alt github-automatic](/images/github-blog-automatic.png)
4. 第二个方法步骤:
1. 本地搭建一个jekll
    
    #安装ruby(1.9.3以上)
    sudo apt-get install ruby1.9.3
    ruby -v 
    #安装bundler
    #切换ruby的源，否则可能无法安装(已被G_F_W)
    gem sources --remove https://rubygems.org/
    gem sources -a https://rubygems.org/
    gem sources -l 
    sudo gem install bundler
    #[详细安装方法参考](https://www.brightbox.com/docs/ruby/ubuntu/)
    #安装jekll 
    sudo gem install jekyll
    sudo gem install rdiscount #markdown解释器

2. 学习jekll的使用
[教程](http://www.ruanyifeng.com/blog/2012/08/blogging_with_jekyll.html), 通过这个教程了解jekll各种目录的
功能和使用,通过前面本地安装的jekll查看是否成功`jekll server`，其实不必要完全搭建整个项目,了解jekll一些基本使用后可以fork别人的jekll模板.
3. 学习markdown语法
[Markdown语法](http://wowubuntu.com/markdown/)

