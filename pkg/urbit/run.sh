rm build/urbit
CPU_DEBUG=1 ./configure
make -j 8
# make
cd build

./urbit -F zod
