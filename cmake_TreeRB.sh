echo "Rebuild TreeRB"
rm -r ./build/TreeRB/*
cd ./build/TreeRB/
cmake ../../src/TreeRB/ -DCMAKE_INSTALL_PREFIX=../../tmp/
make
make install

echo "Test TreeRB..."
./test-TreeRB
