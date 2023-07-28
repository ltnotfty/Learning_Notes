
# fdisk
fdisk /dev/sdb


# gdisk 
gdisk /dev/sda


#gnu parted
parted 


# mkfs

# is supported create

type mkfs.ext3


# make filesystem
mkfs.ext3 /dev/sda


# make a mount point

mkdir /home/tom/part



# mount it
# mount in every boot in /etc/fstab

mount -t ext3 /dev/sda /home/tom/part 



# LVM 

# 1. Physical Volume PV
# 2. Volume Group VG
# 3. Logical Volume LV



# create PV
pvcreate /dev/sda1 /dev/sda2


# create VG

# show vg
vgdisplay 


# create vg
vgcreate vg00 /dev/sda1 /dev/sda1 


# create LV
lvcreate -L 1g -v vg00


# show 
lvdisplay /dev/vg00/lvo10


# mount
mkfs.ext4 /dev/vg00/lvo10



# add pv to vg
vgextend

# del pv from vg
vgreduce

# extend capacity of lv
lvextend

# reduce capacity of lv
lvreduce 





