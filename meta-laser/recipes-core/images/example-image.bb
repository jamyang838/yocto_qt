# Base this image on core-image-base
require recipes-core/images/core-image-base.bb


#Be able to generate qt5 SDK
inherit populate_sdk_qt5

#Add rsync (for qt creator deployment)
IMAGE_INSTALL += "rsync"


#install kernal modules 
IMAGE_INSTALL += "kernel-modules"

#
KERNEL_MODULE_AUTOLOAD += "i2c_dev"

#add ssh
IMAGE_FEATURES += "ssh-server-dropbear"

#Install i2c-tools
IMAGE_INSTALL += "i2c-tools"

#Install vim
IMAGE_INSTALL += "vim"

#install package manage
EXTRA_IMAGE_FEATURES += "package-management"
PACKAGE_CLASSES = "package_deb"
#PACKAGE_CLASSES = "package_rpm"

IMAGE_FSTYPE = "rpi-sdimg"
RM_OLD_IMAGE = "1"

#print 
#do_image_complete_append() {
# bb.warn("yang's image")
#}

#install tzdata
#IMAGE_INSTALL += "tzdata tzdata-europe"

#install Network Manager
#IMAGE_INSTALL += "networkmanager"

# Add support for wifi and bluetooth
IMAGE_INSTALL += "linux-firmware linux-firmware-bcm43430"

# Use Network Manager
IMAGE_INSTALL += "networkmanager networkmanager-bash-completion networkmanager-nmtui ncurses"

#install Qt5/ cinematicexperience
IMAGE_INSTALL += "cinematicexperience"

#install QT module
IMAGE_INSTALL += "qtquickcontrols qtquickcontrols2 qtserialport"
