Summary:IGOS Nusantara SDK
Name:ignsdk
Version:1.0.9
Release:13.9.11
License:BSD
Group:System Environment/Base
URL:http://igos-nusantara.or.id
Source0:%{name}-qt-master.zip
BuildRoot:%{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
Requires:qt
Requires:qtwebkit
Requires:qjson
Requires:mysql-client
%description
IGOS Nusantara  Software Development Kit

%prep
%setup -q -n %{name}-qt-master

%install
install -d -m 755 $RPM_BUILD_ROOT/usr/bin
install -d -m 755 $RPM_BUILD_ROOT/usr/share/ign-sdk/test
install -d -m 755 $RPM_BUILD_ROOT/usr/share/ign-sdk/template
install -d -m 755 $RPM_BUILD_ROOT/usr/share/ign-sdk/bin
qmake-qt4
make
cp -rf ignsdk $RPM_BUILD_ROOT/usr/bin
cp -rf bin/ignsdk-app-creator $RPM_BUILD_ROOT/usr/bin
cp -rf bin/ignsdk-ign-creator $RPM_BUILD_ROOT/usr/share/ign-sdk/bin
cp -rf test/* $RPM_BUILD_ROOT/usr/share/ign-sdk/test
cp -rf template/* $RPM_BUILD_ROOT/usr/share/ign-sdk/template
%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
%dir 
/usr/bin
/usr/share/ign-sdk/test
/usr/share/ign-sdk/template
%config %attr(0755,root,root) /usr/share/ign-sdk/*

%changelog
* Tue Sep 10 2013 ibnu yahya <linux@toroo.org>
- Update version to 1.0.9
- Add ignsdk project builder
* Tue Jul 30 2013 ibnu yahya <linux@toroo.org>
- ADD dir API
- Update File API
* Mon Jul 29 2013 ibnu yahya <linux@toroo.org>
- ADD template
* Thu Jul 23 2013 ibnu yahya <linux@toroo.org>
- FIX Api
- change version build b2
* Sun Mar 22 2013 ibnu yahya <linux@toroo.org>
* Mon Feb 18 2013 ibnu yahya <linux@toroo.org>
- First Build
