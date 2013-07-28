Summary:IGOS Nusantara SDK
Name:ignsdk
Version:1.0.7b2
Release:13.4.22
License:BSD
Group:System Environment/Base
URL:http://igos-nusantara.or.id
Source0:%{name}-qt-master.zip
BuildRoot:%{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
Requires:qt
Requires:qtwebkit
Requires:qjson
%description
IGN Software Development Kit

%prep
%setup -q -n %{name}-qt-master

%install
install -d -m 755 $RPM_BUILD_ROOT/usr/bin
install -d -m 755 $RPM_BUILD_ROOT/usr/share/ign-sdk/test
install -d -m 755 $RPM_BUILD_ROOT/usr/share/ign-sdk/template
qmake-qt4
make
cp -rf ignsdk $RPM_BUILD_ROOT/usr/bin
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
* Mon Jul 29 2013 ibnu yahya <linux@toroo.org>
- ADD template
* Thu Jul 23 2013 ibnu yahya <linux@toroo.org>
- FIX Api
- change version build b2
* Sun Mar 22 2013 ibnu yahya <linux@toroo.org>
* Mon Feb 18 2013 ibnu yahya <linux@toroo.org>
- First Build
