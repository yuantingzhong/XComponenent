#！/bin/bash

TOPDIR=$(cd `dirname $0`;pwd)

echo $TOPDIR

cd $TOPDIR/build

cmake -DCMAKE_INSTALL_PREFIX=../output ..

make

make install

cd $TOPDIR/output/bin/

./CompoentDemo.out





