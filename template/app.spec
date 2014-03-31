%define name <name>
%define release <release>
%define version <version>
%define license <license>
%define url http://<url>
%define group System Environment/Base

Summary:IGOS Nusantara SDK Application
Name:%{name}
Version:%{version}
Release:%{release}
License:%{license}
Group:%{group}
URL:%{url}
Source0:%{name}.tar.gz
Source1:%{name}.txt
BuildRoot:%{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
Requires:ignsdk
BuildArch:noarch
%description
%{description}
<desc>

%prep
%setup -q -n %{name}

%install
%include %{SOURCE1}

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
%dir
%config %attr(0755,root,root) 
/opt/ignsdk/*
/usr/share/applications/*

%changelog

* Mon Feb 18 2013 foo <foo@bar.org>
- First Build
