linux基础命令



## 1. 文件权限



### 1.1 更改文件权限

`chmod u+x <filename>`

`chown usr <filename>`

`chgrp root <filename>`



`-rwxrwxr-x`

第一位含义：

* `-`普通文件
* `d`目录文件
* `l` 链接文件
* `c`串口

对于目录文件来说，`x`意味着能否进入这个目录作为工作目录。



### 1.2 注册新用户

`sudo adduser <username>`

* 伪终端的切换

  `ctrl+alt+f<num>`



### 1.3 获取文件名和目录名



* 文件名 `base name <file absolute path>`
* 目录名 `dirname <file absolute path>`





### 1.4 查看文件

* `cat [-n]`
* `more` `less`
* `head -n 10`
* `tail -n 10`

* `od -t c `

查看文件第11-20行

`cat -n 20 <filename> | tail -n 10`

非纯文本文件

`od -t c <filename>`

输出`password`对应ASCII码

`echo password | od -t c`

### 1.5 修改文件时间或创建新文件

`touch <filename>`



### 1.6 修改文件默认权限

`umask`

root权限默认022



### 1.7 文件隐藏属性

* 改变

`chattr [+-=] [ASacdistu]`

* 列出

`lsattr -[adR] <filename/dirname>`



### 1.8 文件特殊权限：SUID、SGID、SBIT

`-rwsr-xr-x`

s出现在文件拥有者的x权限上时，



#### 1.8.1 SUID

表示Set UID

* SUID权限仅对二进制程序有效
* 执行者需要对该程序具有x
* 本权限仅在执行程序的过程中有效
* 执行者将拥有该程序拥有者的权限

#### 1.8.2 SGID

表示Set GID



对于文件来说

* 对二进制程序有用
* 需要具备x权限
* 获得程序用户组的支持

对于目录来说

* 用户具有rx，则可进入
* 用户在此目录下的有效用户组变为该目录的用户组
* 在此目录下具有w权限，则新文件的用户组和此目录的用户组相同



#### 1.8.3 SBIT

表示Stricy Bit



只针对目录有效

* 有目录wx权限，即可有写入的权限
* 用户在该目录下创建的文件只有root与此用户能删除





使用`chmod 4755 <filename>` ==> SUID





### 1.9 查看文件类型

`file <filename>`



### 1.10 查找文件位置



1. 脚本文件的查找

   `whitch <file>`

2. 文件的查找

   `whereis -[lbmsu]`

   只查找几个特定的目录

   `whereis -l`

3. 在数据库中查找

   `locate -[iclSr]`

   数据库的更新

   `updatedb:` 根据/etc/updatedb.conf 设置查找系统硬盘内的文件，并更新/var/lib/mlocate内的数据库文件

   `locate:`依据/var/lib/mlocate/mlocate的数据库，找出用户所输入关键词的文件名

4. 全局查找

   `find [PATH] [option] [action]`





### 1.11 磁盘与目录容量



* `df -[ahikHTm]`

  列出磁盘与目录容量

* `du -[ahskm]`

  列出文件容量





































 