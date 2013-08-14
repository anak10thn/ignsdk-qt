#!/bin/bash
echo 'Pastikan Anda Telah Memasang IGNSDK' 
cp bin/* /usr/sbin/
mkdir -p  /opt/ignsdk/ign-sudoers.ign/
cp -rf ../ign-sudoers.ign/* /opt/ignsdk/ign-sudoers.ign/
chmod 644 /opt/ignsdk/ign-sudoers.ign/logo.png
cp  -rf ignsdk-ignsudoers.desktop /usr/share/applications/
echo 'Selesai';
exit 0
