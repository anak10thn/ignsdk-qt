#!/bin/bash
echo 'Pastikan Anda Telah Memasang IGNSDK' 
cp bin/* /usr/sbin/
mkdir -p  /usr/share/ign-sdk/test/IGN-sudoers/
cp -rf ../IGN-sudoers/* /usr/share/ign-sdk/test/IGN-sudoers/
chmod 644 /usr/share/ign-sdk/test/IGN-sudoers/logo.png
cp  -rf ign-sudoers.desktop /usr/share/applications/
echo 'Selesai';
exit 0
