Summary:IGOS Nusantara SDK
Name:ignsdk
Version:1.1.1
Release:13.10.13
License:BSD
Group:System Environment/Base
URL:http://igos-nusantara.or.id
Source0:https://github.com/anak10thn/ignsdk-qt/archive/master.zip
BuildRoot:%{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
Requires:qt5-qtwebkit
BuildRequires:qt5-qtwebkit-devel
BuildRequires:gcc-c++
%description
IGOS Nusantara  Software Development Kit

%package devtools
Summary:IGOS Nusantara SDK developer tools
Group:Development/Other
Requires:ignsdk
Requires:rpm-build

%description devtools
IGOS Nusantara  Software Development Kit developer tools

%prep
%setup -q -n %{name}-qt-master

%install
install -d -m 755 $RPM_BUILD_ROOT/usr/bin
install -d -m 755 $RPM_BUILD_ROOT/etc
install -d -m 755 $RPM_BUILD_ROOT/usr/share/ign-sdk/test
install -d -m 755 $RPM_BUILD_ROOT/usr/share/ign-sdk/template
install -d -m 755 $RPM_BUILD_ROOT/usr/share/ign-sdk/bin
qmake-qt5
make
cp -rf ignsdk $RPM_BUILD_ROOT/usr/bin
cp -rf bin/ignsdk-app-creator $RPM_BUILD_ROOT/usr/bin
cp -rf bin/ignsdk-ign-creator $RPM_BUILD_ROOT/usr/share/ign-sdk/bin
cp -rf bin/ignsdk-app-builder $RPM_BUILD_ROOT/usr/bin
cp -rf bin/ignsdk-ign-builder $RPM_BUILD_ROOT/usr/share/ign-sdk/bin
echo "ign" > $RPM_BUILD_ROOT/etc/ignsdk-dist
cp -rf test/* $RPM_BUILD_ROOT/usr/share/ign-sdk/test
cp -rf template/main.tpl $RPM_BUILD_ROOT/usr/share/ign-sdk/template
cp -rf template/app.spec $RPM_BUILD_ROOT/usr/share/ign-sdk/template
cp LICENSE.BSD $RPM_BUILD_ROOT/usr/share/ign-sdk/
cp third-party.txt $RPM_BUILD_ROOT/usr/share/ign-sdk/
%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
/usr/bin/ignsdk
/usr/share/ign-sdk/LICENSE.BSD
/usr/share/ign-sdk/third-party.txt
/usr/share/ign-sdk/test/calculator.ign/assets/440-280-tile.png
/usr/share/ign-sdk/test/calculator.ign/assets/calculator_1280-800.png
/usr/share/ign-sdk/test/calculator.ign/assets/icon-128x128.png
/usr/share/ign-sdk/test/calculator.ign/assets/promo.png
/usr/share/ign-sdk/test/calculator.ign/controller.js
/usr/share/ign-sdk/test/calculator.ign/ignsdk.json
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
/usr/share/ign-sdk/test/calculator.ign/jquery/jquery.min.js
/usr/share/ign-sdk/test/calculator.ign/main.js
/usr/share/ign-sdk/test/calculator.ign/model.js
/usr/share/ign-sdk/test/calculator.ign/README.md
/usr/share/ign-sdk/test/calculator.ign/style.css
/usr/share/ign-sdk/test/calculator.ign/tests/calculator_test.html
/usr/share/ign-sdk/test/calculator.ign/tests/calculator_test.js
/usr/share/ign-sdk/test/calculator.ign/view.js
/usr/share/ign-sdk/test/config-test.ign/ignsdk.json
/usr/share/ign-sdk/test/config-test.ign/index.html
/usr/share/ign-sdk/test/config-test.ign/main.html
/usr/share/ign-sdk/test/kuma.ign/chara1.png
/usr/share/ign-sdk/test/kuma.ign/enchant.js
/usr/share/ign-sdk/test/kuma.ign/ignsdk.json
/usr/share/ign-sdk/test/kuma.ign/index.html
/usr/share/ign-sdk/test/kuma.ign/main.js
/usr/share/ign-sdk/test/widget.ign/index.html

%files devtools
%defattr(-,root,root,-)
/usr/bin/ignsdk-app-creator
/usr/bin/ignsdk-app-builder
/usr/share/ign-sdk/bin/ignsdk-ign-creator
/usr/share/ign-sdk/bin/ignsdk-ign-builder
/usr/share/ign-sdk/template/main.tpl
/usr/share/ign-sdk/template/app.spec
/etc/ignsdk-dist

%changelog
* Mon Oct 13 2013 ibnu yahya <linux@toroo.org>
- Build nightly
- Fix spec file dependency
* Sat Oct 12 2013 ibnu yahya <linux@toroo.org>
- Porting ignsdk 1.1.1 to Qt 5
* Wed Sep 25 2013 ibnu yahya <linux@toroo.org>
- Add SQL API stable 1
- Release stable minor nightly
* Wed Sep 11 2013 ibnu yahya <linux@toroo.org>
- Add ignsdk-dist
- Add test file
- Add devtools package
- Add IGNSDK Builder script
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
