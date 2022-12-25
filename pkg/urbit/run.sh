../../sh/update-brass-pill
rm build/urbit
CPU_DEBUG=1 ./configure
make -j 8
# make
cd build
rm -rf zod
./urbit -F zod -B ../../bin/brass.pill
