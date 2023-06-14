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







## 2. shell变量



### 2.1 查询是否为内置命令

`type -[tpa] <name>`

* -t 选项
  * file： 外部命令
  * alias: 别名
  * builtin: bash内置命令 

* -p name
* -a 在$PATH中查找





### 2.2 变量的使用

1. 输出变量

   `echo $PATH` || `echo ${PATH}`

2. 设置变量

   `<var>=<val>`

3. 变量规则

   * 可使用`''` 或者 `" "`输出空格内容
   * `" "`内的`$`保持原样
   * `' '`内的`$`为变量
   * 可用转义字符`\`输入特殊字符(`\`,`'`, `$`)
   * 使用`$(cmd)`引用命令
   * `unset`取消变量
   * `export`来为子shell进程设置变量





### 2.3 环境变量

1. 常见环境变量

   * HOME
   * SHELL
   * HISTSIZE
   * MAIL
   * PATH
   * LANG
   * LC_ALL
   * RANDOM

2. 所有环境变量

   `set`查看

   重要环境变量

   * PS1: 命令输入后的提示字符
   * $: 进程号PID
   * ?: 上一个命令执行的返回值
   * export: 子进程继承父进程的自定义变量


### 2.4 变量的交互

1. `read -[pt] var`
   * -p 提示的字符
   * -t 接受的秒数
2. `declare|typeset -[-aixr] variable` 
   * -a 变量定义为arr
   * -i 变量定义为int
   * -x 与export一样将后面变量定义为环境变量
   * -r 将变量定义为readonly

> 变量默认为字符串类型，bash中的变量只能支持整数类型





### 2.5 程序的限制

`ulimit `

* -H 严格限制
* -S 警告设置
* -a 列出限制的额度
* -c 内核文件的限制
* -f shell可以建立的最大文件容量
* -d 最大段内存
* -l 可用于锁定的内存量
* -u 最大进程使用数目





### 2.6 变量内容删除、取代

1. 从前删除第一个

   `var=${PATH#/*bin/:}`

2. 从前删除所有匹配的

   `var=${PATH##/*bin/:}`

3. 从后删除第一个

   `var=${PATH%:*/bin}`

4. 从后删除所有

   `var=${PATH%%:*/bin}`

5. 替换第一个

   `var=${PATH/bin/BIN}`

   bin => BIN

6. 替换所有符合的字符串

   `var=${PATH//bin//BIN}`



### 2.7 变量内容的测试与内容替换（depin）

1. `var=${STR-root}`

   没有设置过变量，则`var`为root

2. `var=${STR:-root}`

   没有设置过或者`STR`为空字符串则设置为root

3. `var=${STR+root}`

   设置过变量处理为root

4. `var=${STR:+root}`

   在3基础上除去设置为空字符串

5. `var=${STR=root}`

   将var在STR不为空时设置为root

   STR为空时输出错误信息

6. `var=${STR:=root}`

   在5的基础上除去空的字符串





### 2.8 别名与历史

命令太常不想输入的时候，用这个取个小名好记忆。

1. `alias`

   `alias lm='ls -al | more'`

2. `unalias`

   `unalias lm`

历史命令`history`

* [n] 最近n条命令
* ![num]执行第几条



### 2.9 Bash Shell的操作环境



#### 2.9.1 命令的运行顺序

1. 相对或者绝对路径执行命令 [/bin/ls]，[./ls]
2. 由alias找到该命令来执行
3. 由bash内置的命令执行
4. 通过$PATH变量的顺序查找这个命令执行





#### 2.9.2 bash的登陆与欢迎信息

1. `/etc/issue`

   * \d 本地时间
   * \l 显示第几个终端画面
   * \m 显示硬件的等级
   * \n 显示主机的网络名称
   * \O 显示主机的domain name
   * \r 操作系统的版本
   * \t 显示本地端时间的时间
   * \S 操作系统的名称
   * \v 操作系统的版本

2. `/etc/motd`

   > ubuntu下并未发现该文件

   

#### 2.9.3 bash的环境配置文件



> login-shell 和 non-login-shell: 需要用户名和密码的就是login-shell

配置文件的读取

```
`source <file>` or `./file`

读取配置文件

两者的区别是，`source`是在当前shell中执行，而`.`是再开一个子shell进行
```

1. `/etc/profile`（login-shell）系统环境变量

   * PATH、MAIL、USER、HOSTNAME、umask环境变量的设置

   * 读取`/etc/profile.d/`下的.sh文件
   * 调用`/etc/locale.conf`
   * 调用`/usr/share/bash-completion/completions/*` 命令补全

2. `~/.bash_profile` （login-shell）用户环境变量

   * `~/.bash_profile`
   * `~/.bash_login`
   * `~/.profile`
   * 顺序读取只读取其中一个文件

3. `~/.bashrc`(non-login shell)

   * 根据不同UID设置umask
   * 根据不同UID设置提示字符
   * 调用`/etc/profile.d/*.sh`

4. 其他配置文件的读取
   * `/etc/man_db.conf` : man路径的设置
   * `~/bash_history：` 命令的历史记录
   * `~/bash_logout：`登出后执行的命令



#### 2.9.4 终端环境设置



1. `stty [-a]`

   查看终端设置的按键有哪些

2. `set -[ucxhHmBC]`

   * -u 错误信息
   * -v 信息的原始内容
   * -x 显示命令的内容
   * -h 历史命令
   * -H 历史命令
   * -m 任务管理
   * -B 与中括号有关
   * -C 文件覆盖

3. 通配符与特殊符号

   * *
   * ?
   * []
   * [ - ]
   * [^]
   * #
   * \
   * |
   * !
   * & 后台执行
   * '>','>>' 输出重定向
   * '<','<<' 输入重定向
   * `''`
   * `()`子shell
   * `{}`命令区块的组合



#### 2.9.5 数据流重定向

* 标准输入 0  `<` , `<<`
* 标准输出 1 `>`, `>>`
* 标准错误信息 2 `2>` , `2>>`



查找结果，标准信息写到文件

`find /home -name .bashrc > list`

出错信息写到另一个文件

`find /home -name .bashrc > list 2 > list_err`

标准输出、出错信息写到同一个文件

`find /home -name .bashrc > list 2>&1`

标准输入的重定向

`cat > catfile < ~/.bashrc`

建立文件

`cat > <newfile>`



> /dev/null 输出信息的无底洞



为什么需要输入输出重定向？

* 屏幕输出信息很重要
* 后台执行的程序，不希望干扰屏幕正常的输出结果
* 系统的计划任务命令执行结果，希望它可以保留下来
* 错误的信息需要丢弃
* 错误信息与正确信息需要分别输出



#### 2.9.6 命令执行的判断

1. `$?`为命令执行的返回值

2. `cmd1 && cmd2`

   `cmd1`正确执行并正确返回才执行`cmd2`

3. `cmd1 || cmd2`

   `cmd1`执行完毕错误返回才执行`cmd2`

4. 使用顺序

   `cmd1 && cmd2 || cmd3`



#### 2.9.7 管道命令

* 管道命令仅仅会处理标准输出，忽略标准出错信息
* 管道命令必须接受前一个命令的数据成为标准输入处理

1. `cut`

   按行分割文件内容，缺点无法处理多空格的情况

   `echo ${PATH} |cut -d ':' -f 1,4`

2. `grep`

   * -a 二进制

   * -c 计算匹配字符次数

   * -i 忽略大小写

   * -n 输出行号

   * -v 反向选择

     简单正则： `last | grep 'root' | cut -d ' ' -f1 

3. `sort`

   * -f忽略大小写

   * -b忽略前导空格

   * -M 以月份名字排序

   * -n 纯数字

     `cat /etc/password | sort -t ':' -k 3`

4. `uniq`

   取唯一值

   * -i 忽略大小写

   * -c 计数

   * `last | cut -d ' ' -f1 | sort | uniq`

     last取出账号，仅取出账号栏，进行排序后取出一位。

5. `wc`

   统计数目

   * -l 列出多少行
   * -w 列出多少字
   * -m 多少字符

   * `last | grep [a-zA-Z] | grep -v 'wtmp' | grep -v 'reboot | \ grep -v 'unknown' | wc -l`

     取出账号中非空白行、wtmp、reboot、unknown等

6. `tee`

   * `-a` 附加到文件后面

   同时将数据流分送到文件和屏幕

   `last | tee  -a last.file | cut -d ' ' -f1 `

7. `tr`

   删除或者替换一段字符

   * 小写替换为大写

   `last | tr '[a-z]' '[A-Z]'`

   * 删除冒号

   `last | tr -d ':'`

8. `col`

   * -x tab转换空格

   `cat /etc/man_db.conf | col -x | cat -A | more`

9. `join [-ti12] file1 file2`

   处理两个文件的

   `join -t ':' -1 4 /etc/password -2 3 /etc/group | head -n 3`

10 .`paste file1 file2`

​		两行沾在一起

11. `expand`

    [tab]转空格

12. `split`

    划分命令

    * -b size
    * -l line

    `ls -al / | split -l 10 - lsroot`

13. `xargs [-0epn] command`

    产生某个命令的参数

    `cut -d ':' -f 1 /etc/passwd | head -n 3 | xargs -p -n 1 id`

14. `-`

    表示`stdin`, `stdout`

    
    
    
    
    
    
    

​    

## 3. 正则表达式





### 3.1 基础正则

* [:alphanum:]
* [:alpha:]
* [:blank:]
* [:cntrl:]
* [:digit:]
* [:graph:]
* [:lower:]
* [:print:]
* [:punct:] 标点符号
* [:upper:]
* [:space:]

### 3.2 特殊符号

* `^`

  [^ ]表示不使用这些字符集，在括号外表示行首

  `^the`： 表示以the开头的字符串

  `[^a-z]:` 表示不匹配小写字母，也可以写作`[^[:lower:]]`

* `$`

  表示行尾巴

  `'\.$':`表示匹配以`.`结尾的行

* `^$`

  表示匹配空行！

* `*`

  匹配任意前一个字符任意次数

  `'g.*g':`以`g`开头，以`g`结尾的行

* `.`

  匹配任意字符一次





### 3.3 sed

#### 3.3.1 删除

`nl /etc/passwd | sed '2,5d'`

删除2-5行

`nl /etc/passwd | sed -e '5,$d'`

删除最后第5（包含）行以后的内容

#### 3.3.2 增加

在行后增加

`nl /etc/passwd | sed -e '2a Drink tea or Coffee ....\n newline charcter'`

ubuntu里是`\n`换行

在行前增加

`nl /etc/passwd | sed -e '2i' Dog insert tree \n Cat look at this scenary`



#### 3.3.3 替换

`nl /etc/passwd | sed -e '2,5c No 2-5 number'`

将第2-5行内容替换为`No 2-5 number`

`nl /etc/passwd | sed  -n -e '2,5p'`

显示2-5行的内容！

`/sbin/ifconfig lo | grep 'inet ' | sed -e 's/^.*inet //g' | sed -e 's/ netmask.*$//g'`

取出`lo`网卡接口中的ip地址，删除掉子网掩码



字符的替换与`vi`下的替换一样

`sed -e 's/old_string/new_string/g'`



直接修改

`sed -i 's/\.$/\!/g' regular_express.txt`

将行尾的`.`替换为`!`

`sed -i '$a \n #This is a test' regular_express.txt`

在最后一行加上`#This is a test`



### 3.4 扩展正则

1. `+`

   匹配一次或以上

2. `?`

   零个或者一个前一个重复字符

3. `|`

   或者

4. `()`

   群组字符

5. `()+`

   多个重复群组判定

`egrep -v '^$|^#' regular_express.txt`

列出文件中所有的不包含注释的非空行



### 3.5 awk（TODO）

字段处理

`awk 'condition1 [op1] condition2 [op2] ...' filename`

变量

* NF每行拥有的字段数目
* NR目前处理到第几行
* FS分割的字符



`last -n 5 | awk '{print $1 "\t lines: " NR "\t columns" NF}'`

登陆中取出名字，显示行号和列数

`cat /etc/passwd | awk 'BEGIN {FS=":"} $3 < 10 {print $1 "\t" $3}'`

使用BEGIN设置FS分割符号





### 3.6 文件对比



1. `diff -[bBi] file1 file2`
2. `cmp [-l] file1 file2 `
3. `patch`打包
4. `pr` 文件打印







## 4 shell语法



### 4.1 第一个shell脚本

```shell
 #!/bin/bash

[ -d ~/bin ] || mkdir ~/bin
cd ~/bin
echo `pwd`

PATH=/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
echo -e "hello world! \a \n"
exit 0
```



### 4.2 脚本执行方式的差异

1. `sh <scrip_name> or ./<scrip_name>`

   开子窗口执行

2. `source <scrip_name>`

   直接在父窗口执行



### 4.3 判断表达式



#### 4.3.1 存在性检测

* `-e` 文件存在
* `-f`普通文件存在
* `-d`目录文件存在
* `-b`设备存在
* `-c`字符设备存在
* `-S` socket文件
* `-p`管道文件
* `-L` 链接文件

#### 4.3.2 权限检测

* `-r`可读
* `-w`
* `-x`
* `-u` suid
* `-g` sgid
* `-k` strcky bit
* `-s` 文件名存在且非空

#### 4.3.3 文件比较

* `-nt` 比新
* `-ot` 比旧
* `-ef` 是否为同一文件



#### 4.3.4 整数比较

* `-eq`
* `-ne`
* `-gt`
* `-lt`
* `-ge`
* `-le`



#### 4.3.4 字符串比较

* `test -z string`
* `test -n string`
* `test str1==str2`
* `test str1!=str2`



#### 4.3.5 多条件

* `test -r filename -a -x filename` and
* `test -r file -o -x file` or
* `test !-x file`



#### 4.3.6 中括号的使用



* `[ "${var1}" == "${var2}" ]`
* ` [ -z "${str}" ]`







### 4.4 shell默认变量

* `$#` 参数个数
* `$@` 所有参数不包含分割符号
* `$*` 所有参数包含分割符号
* `$0`脚本名



`shift <num>:` 从第几个变量开始，读取参数





#### 4.5 程序结构设计

#### 4.5.1 if...then



















