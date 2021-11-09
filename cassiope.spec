Name:           cassiope
Version:        0
Release:        0.1%{?dist}
Summary:        Probe build environment

License:        GPLv2+
URL:            https://github.com/omajid/cassiope
Source0:        cassiope.tar.gz

BuildRequires:  make gcc

%description
A tiny program to probe its envionment. Prints its environment.

%prep
%autosetup -n %{name}


%build
export CFLAGS=-g
%make_build

./cassiope


%install
mkdir -p %{buildroot}%{_bindir}
cp cassiope %{buildroot}%{_bindir}/


%files
%license LICENSE
%doc README
%{_bindir}/cassiope



%changelog
* Tue Nov 09 2021 Omair Majid <omajid@redhat.com>
- Initial package
