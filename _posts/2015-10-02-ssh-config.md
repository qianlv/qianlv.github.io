---
layout: post
title: SSH跳板机和SSH配置
tag: ssh
---

{{ page.title }}
===============

国庆放假回家但游戏行业放假回家也要盯着线上，这就需要用到跳板机.跳板机
就是一个中转的服务器: 本机->跳板机->线上服务器，这个过程基本都是使用ssh来
连接的。如果使用密钥来验证就会有ssh密钥转发的问题，因为跳板机上没有你的私
钥，这就需要使用到ssh的密钥转发和ssh-agent，简单说明一下ssh配置和ssh-agent。

## 1. ssh 配置文件

系统全局的ssh配置文件为/etc/ssh/ssh_config文件，用户的在~/.ssh/config(如果
没有这个文件可以自己新建。
ssh 配置的格式:

```
    Host alias_host_name
        option1 value
        option2 value
    或是
    Host alias_host_name
        option1=value
        option2=value
        # option3=value 注释符号'#'
```

一些常用的配置项(man ssh_config 查看详细配置):

```
    Host: 支持linux终端的模式
    HostName: 主机地址
    Port: 指定端口
    User: 用户名
    IdentityFile: 指定验证使用的私钥
    IdentitiesOnly: Yes， 阻止ssh的默认行为:使用~/.ssh/id_rsa私钥验证(如果有)，
        在IdentityFile使用指定私钥之前
    ForwardAgent: 密钥转发到连接的主机上
    ForwardX11: 远程主机图形界面是否显示
```

使用配置文件就可以实现使用不同私钥登录不同的主机，也可以根据主机的不同使用不同的配置
连接远程主机也可以使用名称，而不是容易忘记的ip地址，下面是我的配置:

```
    Host github.com
        User git
        IdentityFile ~/.ssh/github_rsa
    Host proxy
        HostName 127.0.0.1
        User root
        Port 10540
        IdentityFile ~/.ssh/proxy_rsa
        ForwardAgent Yes
```

## 2. ssh-agent

ssh-agent 一个私钥管理程序，通过ssh-add添加私钥。
ssh连接是通过ssh-agent来完成认证，这样如果私钥本身有密码，就不需要每次连接时都输入。
[如何启动ssh-agent](http://stackoverflow.com/questions/17846529/could-not-open-a-connection-to-your-authentication-agent)  
[ssh-agent needs to start each time on my server](http://serverfault.com/questions/593040/ssh-agent-needs-to-start-each-time-on-my-server)  
一个启动ssh-agent的脚本:

```
    function set_ssh_agent()
    {
        for P in /tmp/ssh-*/agent.*
        do  
            if [ -O "$P" ] && [ -O "$(dirname "$P")" ];
            then
                pid=${P#*agent.}
                echo "$P"
                SSH_AUTH_SOCK=$P; export SSH_AUTH_SOCK;
                SSH_AGENT_PID=$pid; export SSH_AGENT_PID;
                return 0
            fi  
        done
        return 1
    }

    set_ssh_agent
    if [ $? == "1" ]; then
        eval `ssh-agent -s`
        set_ssh_agent
        ssh-add # You key
    fi    
```

## 3. 跳板机密钥问题

由于安全原因不可能将私钥放置到公共使用的跳板机上。
使用ssh-agent进行ssh私钥验证，同时ssh配置允许私钥转发，就可以通过密钥在跳板机上登录远程主机。
