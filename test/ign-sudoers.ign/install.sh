#!/bin/bash
echo 'Pastikan Anda Telah Memasang IGNSDK' 
cp bin/* /usr/sbin/
mkdir -p  /usr/share/ign-sdk/test/ign-sudoers.ign/
cp -rf ../ign-sudoers.ign/* /usr/share/ign-sdk/test/ign-sudoers.ign/
chmod 644 /usr/share/ign-sdk/test/ign-sudoers.ign/logo.png
cp  -rf ignsdk-ignsudoers.desktop /usr/share/applications/
echo 'Selesai';
exit 0
