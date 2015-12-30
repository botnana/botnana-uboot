# Requirements

* ARM Cross Compiler: GCC

# ARM Cross Compiler: GCC

This is a pre-built (32bit) version of Linaro GCC that runs on generic linux, so 64bit users need to make sure they have installed the 32bit libraries for their distribution.

# Debian OS 7, 8

    sudo dpkg --add-architecture i386
    sudo apt-get update
    sudo apt-get install libstdc++6:i386 libgcc1:i386 zlib1g:i386 libncurses5:i386

# Download and extract:

    wget -c https://releases.linaro.org/14.09/components/toolchain/binaries/gcc-linaro-arm-linux-gnueabihf-4.9-2014.09_linux.tar.xz
    tar xf gcc-linaro-arm-linux-gnueabihf-4.9-2014.09_linux.tar.xz
    export CC=`pwd`/gcc-linaro-arm-linux-gnueabihf-4.9-2014.09_linux/bin/arm-linux-gnueabihf-

# Configure and Build:

Booring from MicroSD card

    make ARCH=arm CROSS_COMPILE=${CC} distclean
    make ARCH=arm CROSS_COMPILE=${CC} am335x_evm_config
    make ARCH=arm CROSS_COMPILE=${CC}

Booting from eMMC

    make ARCH=arm CROSS_COMPILE=${CC} distclean
    make ARCH=arm CROSS_COMPILE=${CC} am335x_evm_emmc_config
    make ARCH=arm CROSS_COMPILE=${CC}

# Install Bootloader:

    sudo cp -v u-boot.img /media/boot/
    sudo cp -v MLO /media/boot/

# Install uEnv.txt:

    sudo cp -v uEnv.txt /media/boot/

