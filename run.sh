rm -rf output *.o
gcc -c *.c
gcc -o output *.o
./output
rm -rf output *.o