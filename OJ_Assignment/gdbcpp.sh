if test -e ./$1.cpp
then
	echo g++ -g -std=c++14 $1.cpp -lm -o $1
	g++ -g -std=c++14 $1.cpp -lm -o $1
	if [ $? -eq 0]
	then
		echo running gdb
		gdb $1
		echo delete output file
		rm $1
	fi
else
	echo Error: illegal source file name.
	echo Usage: ./gdbcpp.sh 10xx.x.xx
fi
