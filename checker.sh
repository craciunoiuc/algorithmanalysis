#!/bin/bash

radix="RadixSort"
shell="ShellSort"
tim="TimSort"
input_dir="./in"
ref_dir="./out"
tests_passed=0
input_type="int"
files="ls -l $input_dir | egrep -c '^-'"
files_number=$(eval "$files")
tests_number=$(($files_number*3))

make RadixSort
make ShellSort
make TimSort

check_sort() {
	test_no=$1
	algo_name=$2
	printf "Testing $algo_name with input $1..."
	"./$algo_name" "${input_dir}/test$test_no.in" "${input_type}"> "aux.out"
	diff -bBq "aux.out" "${ref_dir}/test$test_no.out" > "test.out"
        if [ -s "test.out" ]
	then
		echo "FAILED"
	else
		echo "SUCCESS"
		#let "tests_passed++"
		#(($tests_passed++))
		tests_passed=$((tests_passed+1))
	fi
	rm "test.out"
	rm "aux.out"
}
#files_number=eval "$files_number_command"
printf "Etapa 2 AA - Sortare\n"
for algo in "$radix" "$shell" "$tim";
do
	for counter in `seq 0 $(($files_number - 1))`;
	do
		check_sort $counter $algo
	done
done

printf "Tests passed $tests_passed/$tests_number\n"
make clean

