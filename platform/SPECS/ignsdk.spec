Summary:IGOS Nusantara SDK
Name:ignsdk
Version:b1.0.1
Release:13.4.22
License:WTFPL
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
qmake-qt4
make
cp -rf ignsdk $RPM_BUILD_ROOT/usr/bin
cp -rf test/* $RPM_BUILD_ROOT/usr/share/ign-sdk/test
%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
%dir 
/usr/bin
/usr/share/ign-sdk/test
%config %attr(0755,root,root) /usr/share/ign-sdk/*

%changelog
* Sun Mar 22 2013 ibnu yahya <linux@toroo.org>
* Mon Feb 18 2013 ibnu yahya <linux@toroo.org>
- First Build
