#
# Copyright (c) 2013 SUSE LINUX Products GmbH, Nuernberg, Germany.
#
# All modifications and additions to the file contributed by third parties
# remain the property of their copyright owners, unless otherwise agreed
# upon. The license for this file, and modifications and additions to the
# file, is the same license as for the pristine package itself (unless the
# license for the pristine package is not an Open Source License, in which
# case the license is the MIT License). An "Open Source License" is a
# license that conforms to the Open Source Definition (Version 1.9)
# published by the Open Source Initiative.

# Please submit bugfixes or comments via http://bugs.opensuse.org/
#

Summary:    IGOS Nusantara SDK
Name:     ignsdk
Version:    1.1.3
Release:    1
License:    BSD
Group:      Development/Tools/IDE
Url:      http://igos-nusantara.or.id
Source0:    https://github.com/anak10thn/ignsdk-qt/archive/master.tar.gz
BuildRoot:    %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
BuildRequires:    libQt5WebKit5-devel
BuildRequires:    libQt5WebKitWidgets-devel
BuildRequires:    gcc-c++
Requires:   libQt5WebKit5

%description
IGOS Nusantara  Software Development Kit

%package devtools
Summary:    IGOS Nusantara SDK developer tools
Group:      Development/Other
Requires:   ignsdk

%description devtools
IGOS Nusantara Software Development Kit developer tools

%prep
%setup -q -n %{name}-qt-master

%install
install -d -m 755 $RPM_BUILD_ROOT/usr/bin
install -d -m 755 $RPM_BUILD_ROOT/etc
install -d -m 755 $RPM_BUILD_ROOT/usr/share/ign-sdk/test
install -d -m 755 $RPM_BUILD_ROOT/usr/share/ign-sdk/template
install -d -m 755 $RPM_BUILD_ROOT/usr/share/ign-sdk/bin
install -d -m 755 $RPM_BUILD_ROOT/usr/share/man/man1
qmake-qt5
make
cp -rf ignsdk $RPM_BUILD_ROOT/usr/bin
cp -rf bin/ignsdk-app-creator $RPM_BUILD_ROOT/usr/bin
cp -rf bin/ignsdk-ign-creator $RPM_BUILD_ROOT/usr/share/ign-sdk/bin
cp -rf bin/ignsdk-app-builder $RPM_BUILD_ROOT/usr/bin
cp -rf bin/ignsdk-ign-builder $RPM_BUILD_ROOT/usr/share/ign-sdk/bin
cp -rf doc/ignsdk.1.gz $RPM_BUILD_ROOT/%{_mandir}/man1
cp -rf doc/ignsdk-app-builder.1.gz $RPM_BUILD_ROOT/%{_mandir}/man1
cp -rf doc/ignsdk-app-creator.1.gz $RPM_BUILD_ROOT/%{_mandir}/man1
echo "ign" > $RPM_BUILD_ROOT/etc/ignsdk-dist
cp -rf test/* $RPM_BUILD_ROOT/usr/share/ign-sdk/test
cp -rf template/main.tpl $RPM_BUILD_ROOT/usr/share/ign-sdk/template
cp -rf template/app.spec $RPM_BUILD_ROOT/usr/share/ign-sdk/template

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)

%dir /usr/share/ign-sdk
/usr/bin/ignsdk
/usr/share/ign-sdk/test
/usr/share/ign-sdk/test/calculator.ign
/usr/share/ign-sdk/test/calculator.ign/assets
/usr/share/ign-sdk/test/calculator.ign/assets/440-280-tile.png
/usr/share/ign-sdk/test/calculator.ign/assets/calculator_1280-800.png
/usr/share/ign-sdk/test/calculator.ign/assets/icon-128x128.png
/usr/share/ign-sdk/test/calculator.ign/assets/promo.png
/usr/share/ign-sdk/test/calculator.ign/controller.js
/usr/share/ign-sdk/test/calculator.ign/ignsdk.json
/usr/share/ign-sdk/test/calculator.ign/img
/usr/share/ign-sdk/test/calculator.ign/img/1x
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_0_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_1_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_2_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_3_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_4_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_5_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_6_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_7_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_8_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_9_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_ac_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_addition_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_division_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_equals_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_multiplication_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_point_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_positivenegative_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/normal/52112_calculator_subtraction_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_0_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_1_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_2_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_3_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_4_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_5_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_6_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_7_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_8_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_9_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_ac_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_addition_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_division_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_equals_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_multiplication_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_point_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_positivenegative_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/1x/pressed/52112_calculator_subtraction_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/052312_close_btn_onclick-04.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/052312_close_btn_onclick.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_0_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_1_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_2_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_3_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_4_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_5_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_6_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_7_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_8_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_9_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_ac_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_addition_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_bottom_dropshadow.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_division_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_equals_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_multiplication_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_point_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_positivenegative_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_right_shadow.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_screen.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/normal/52312_calculator_subtraction_btn.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_0_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_1_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_2_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_3_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_4_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_5_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_6_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_7_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_8_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_9_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_ac_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_addition_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_division_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_equals_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_multiplication_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_point_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_positivenegative_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/img/2x/pressed/52312_calculator_subtraction_btn_pressed.png
/usr/share/ign-sdk/test/calculator.ign/index.html
/usr/share/ign-sdk/test/calculator.ign/jquery
/usr/share/ign-sdk/test/calculator.ign/jquery/jquery.min.js
/usr/share/ign-sdk/test/calculator.ign/main.js
/usr/share/ign-sdk/test/calculator.ign/model.js
/usr/share/ign-sdk/test/calculator.ign/README.md
/usr/share/ign-sdk/test/calculator.ign/style.css
/usr/share/ign-sdk/test/calculator.ign/tests
/usr/share/ign-sdk/test/calculator.ign/tests/calculator_test.html
/usr/share/ign-sdk/test/calculator.ign/tests/calculator_test.js
/usr/share/ign-sdk/test/calculator.ign/view.js
/usr/share/ign-sdk/test/config-test.ign
/usr/share/ign-sdk/test/config-test.ign/ignsdk.json
/usr/share/ign-sdk/test/config-test.ign/index.html
/usr/share/ign-sdk/test/config-test.ign/main.html
/usr/share/ign-sdk/test/kuma.ign
/usr/share/ign-sdk/test/kuma.ign/chara1.png
/usr/share/ign-sdk/test/kuma.ign/enchant.js
/usr/share/ign-sdk/test/kuma.ign/ignsdk.json
/usr/share/ign-sdk/test/kuma.ign/index.html
/usr/share/ign-sdk/test/kuma.ign/main.js
/usr/share/ign-sdk/test/widget.ign
/usr/share/ign-sdk/test/widget.ign/index.html
%doc LICENSE.BSD third-party.txt README.md
%doc %{_mandir}/man1/ignsdk.1.gz

%files devtools
%defattr(-,root,root,-)
/usr/bin/ignsdk-app-creator
/usr/bin/ignsdk-app-builder
/usr/share/ign-sdk/bin
/usr/share/ign-sdk/bin/ignsdk-ign-creator
/usr/share/ign-sdk/bin/ignsdk-ign-builder
/usr/share/ign-sdk/template
/usr/share/ign-sdk/template/main.tpl
/usr/share/ign-sdk/template/app.spec
/etc/ignsdk-dist
%doc %{_mandir}/man1/ignsdk-app-builder.1.gz
%doc %{_mandir}/man1/ignsdk-app-creator.1.gz

%changelog
