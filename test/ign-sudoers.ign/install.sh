#!/bin/bash
echo 'Pastikan Anda Telah Memasang IGNSDK' 
cp bin/* /usr/sbin/
mkdir -p  /opt/ign-sudoers.ign
cp -rf ../ign-sudoers/* /opt/ign-sudoers.ign
chmod 644 /usr/share/ign-sdk/test/IGN-sudoers/logo.png
cp  -rf ign-sudoers.desktop /usr/share/applications/
echo 'Selesai';
exit 0
