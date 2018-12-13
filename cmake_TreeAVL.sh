echo "Rebuild TreeAVL"
rm -r ./build/TreeAVL/*
cd ./build/TreeAVL/
cmake ../../src/TreeAVL/ -DCMAKE_INSTALL_PREFIX=../../tmp/
make
make install

echo "Test TreeAVL..."
./test-TreeAVL
