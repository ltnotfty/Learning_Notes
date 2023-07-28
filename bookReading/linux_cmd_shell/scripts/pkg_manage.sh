#debian: dpkg

#redhat: rpm

apt --installed list 


apt show vim

# list all file installed 
dpkg -L vim

# reverse search
dpkg --search /bin/sh 


apt search zsh 


# no grep
apt --name-only search zsh 


# upgrade
apt upgrade 


# del
apt remove zsh


# del related file
apt purge zsh 




# snap container
snap version


# snap find
snap find some

#list
snap list 

#del
snap remove user



