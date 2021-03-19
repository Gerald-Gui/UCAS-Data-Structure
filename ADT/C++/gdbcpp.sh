if test -e ./$1.cpp
then
	echo g++ -g -std=c++14 $1.cpp -o $1
	g++ -g $1.cpp -o $1
	echo running gdb
	gdb $1
	echo delete output file
	rm $1
else
	echo Error: illegal source file name.
	echo Usage: ./gdbcpp.sh <file_name_without_.cpp>
fi
