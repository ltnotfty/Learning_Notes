# - file 
# d dir
# l link 
# c character dev
# b block dev
# p pipeline
# s socket 

#-rwxr-xr-x
#-owner_restrict owner_group_restrict other_user_restrict



#default restrict

umask 022


#change mod 
chmod u+x newfile 

# u user
# g group
# o other
# a all



# change owner

chown dan.shared newfile 


# change group of file 
chgrp shred newfile



# suid: when user excute file , will run in owner restrict
# sgid: when user excute file , will run in owner group restrict
# sticky bit: when apply to dir, only file owner can del or rename file 

# suid sgid sticky_bit




