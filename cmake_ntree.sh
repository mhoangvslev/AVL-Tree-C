echo "Rebuild ntree"
rm -r ./build/ntree/*
cd ./build/ntree/
cmake ../../src/ntree/ -DCMAKE_INSTALL_PREFIX=../../tmp/
make
make install

echo "Test ntree..."
./test-ntree
