set -e

# make sure gcov & g++ version
sudo apt install lcov -y

if [ ! -d build ] ; then
	mkdir build
fi

cd build
cmake ..
make VERBOSE=1
ASAN_OPTIONS='detect_leaks=1' ./tests/tests || true

cd ..
rm -rf coverage
mkdir coverage
cd coverage
lcov --directory ../build --capture --output-file ut-coverage.info
lcov -e ut-coverage.info '*source*' --output-file ut-cov-filtered.info
genhtml ut-cov-filtered.info --output-directory ut-coverage-report
