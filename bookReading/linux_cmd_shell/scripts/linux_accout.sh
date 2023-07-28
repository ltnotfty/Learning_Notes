
# /etc/passwd
# usr_name passwd uid gid usr_acct_desc home_dir shell_type 
# x indicate encrypt



# /etc/shadow
# encry_passwd pass_last_day can_mod_day must_mod_day notify_out_day aband_day




# add user test by default 
useradd -m test



# mod  default for user

useradd -m test -s /bin/basho



# del user
userdel -r test 


# mod user login name or freeze user
usermod 


# passwd
passwd test 


# many user:pass
chpass < user.txt

# user.txt content:
# ltnotfty:ltnotfty
# usr:usr



# change shell for user
chsh -s /bin/bash

# change user
chfn 

# lookup info for user
finger test 

# set expiry time
chage -d


# group files 
# /etc/group
# group_name g_pass gid user_list 



# create new group 
groupadd shared


# add user to group
usermod -G shared test 


# mod group
groupmod -g -n



# file acl
getfacl file


# set file acl
setfacl -m g:sales:rw test 

setfacl -x g:sales test 


