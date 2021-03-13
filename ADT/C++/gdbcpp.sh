echo g++ -g -std=c++14 $1.cpp -o $1
g++ -g $1.cpp -o $1
echo running gdb
gdb $1
echo delete output file
rm $1