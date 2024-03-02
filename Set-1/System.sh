#Program to show various system configurations 
#!/bin/bash

echo "-----a)OS version,release number,Kernel Version----"
lsb_release -a
uname -a
echo "-----b)Available Shells:-"
cat /etc/shells
echo "-----c)Computer CPU Information:-"
lscpu
echo "-----d)Memory Information:-"
free -m
echo "-----e)Hard Disk Information:-"
fdisk -l
echo "-----f)File System(Mounted):-"
df -h
