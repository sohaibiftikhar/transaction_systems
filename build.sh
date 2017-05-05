git clone https://github.com/sohaibiftikhar/transaction_systems.git ts_03681005
cd ts_03681005
mkdir build
cd build
cmake ..
make
echo "Initiating first run with input file ../inputs/input1\n"
cat ../inputs/input1 |  xargs build/trans_system
echo "Initiating second run with input file ../inputs/input2\n"
cat ../inputs/input2 |  xargs build/trans_system
