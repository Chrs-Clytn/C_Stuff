#!/bin/bash

#Need to ssh in here

# check maps device
cat /ver/etc/maps-device

if $ = /dev/mapsSD 
check_map_package();
else 
printf("Maps Device is not SD");
return;
#need to check for valid map package on which bank
check_map_package()
{
    ls -la /var/nav | grep navigon_partition
#   drwxr-xr-x 2 root root 4096 Jul 29 02:52 filesync.d 
#   lrwxrwxrwx 1 root root 13 Jul 29 02:52 navigon_partition -> /dev/mapsSDp1
if $ == mapsSDp1
{
ls -l /dev/maps* | grep mapsSDp1; # need to implement cut or sed on the output here to get a good answer for the next if statement
#	lrwxrwxrwx 1 root root 7 Sep 25 09:36 /dev/mapsSD -> mmcblk1 
#	lrwxrwxrwx 1 root root 9 Sep 25 09:36 /dev/mapsSDp1 -> mmcblk1p1 
#   lrwxrwxrwx 1 root root 9 Sep 25 09:36 /dev/mapsSDp2 -> mmcblk1p2
    if $ == mmcblk1p1
    {
    printf("navigon is mounted to p1 ");
    return;
    }
} 
else if ($ == mapsSDp2)
{
    printf("maps is mounted on offline bank, continuing with copy");
    copy_map_banks;
}
# sfdisk -l /dev/mmcblk1

copy_map_banks() 
{
# keep tegra alive
keep-tegra-alive 60;
# stop export-nfs
stop export-nfs;
#need to copy map package from bank2 to bank1
nohup dd if=/dev/mmcblk1p2 of=/dev/mmcblk1p1 status=progress > /tmp/ddstatus.txt & tail -f /tmp/ddstatus.txt;
# need to copy bank sizes
cp /var/etc/map-updater/BANK_B.size /var/etc/map-updater/BANK_A.size;
#start export-nfs
start export-nfs
}