DESCRIPTION = "Command line and full screen utilities for browsing procfs, a \"pseudo\" file system dynamically generated by the kernel to provide information about the status of entries in its process table."
HOMEPAGE = "https://gitlab.com/procps-ng/procps"

COMPATIBLE_HOST_ARCHS = ".*linux"

require conf/fetch/sourceforge.conf
SRC_URI = "${SOURCEFORGE_MIRROR}/procps-ng/procps-ng-${PV}.tar.xz"

DEPENDS = "libncurses"

inherit autotools pkgconfig

EXTRA_OECONF = "--disable-numa --disable-whining"

inherit auto-package-libs
AUTO_PACKAGE_LIBS = "procps"
LIBRARY_VERSION = "6"

DEPENDS_${PN}-libprocps = "libc libncurses"

inherit auto-package-utils
AUTO_PACKAGE_UTILS = "free kill pgrep pidof pkill pmap ps pwdx slabtop tload \
	top uptime vmstat w watch sysctl"
AUTO_PACKAGE_UTILS_DEPENDS = "libc libncurses libprocps"
AUTO_PACKAGE_UTILS_RDEPENDS = "libc libncurses libprocps"