my_v = 1
my_str = "Hello"

# set global variable for son shell
export my_str

# or

export my_str = "hello"

# unset env varaible
unset my_str


# sub shell can't change behavior of parent shell

# HISTFILESIZE : in memory size ~/bash_history file 
# HISTSIZE: in hard disk size
# write HISTFILESIZE > HISTSIZE ? HISTSIZE : HISTFILESIZE items to hard disk


# set path
export PATH=$PATH:$PWD




# login shell :  
#    at begin:    (1) /etc/profile 
#                (2) ~/.bash_profile -> ~/.bash_login -> ~/.profile  read excute and exit in this order if it exists 
#    at end: ~/.bash_logout
# no login shell:
#    at begin:  (1) /etc/bash_bashrc
#               (2) ~/.bashrc
