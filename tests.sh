#!/bin/bash

FAILURES=0

function do_test {
	ScriptName="$1"
	Input="$2"
	ExpectedOutput=$(printf "$3")
	TailLines="${4:-1}"
	echo -n Compiling "$ScriptName"...
	g++ -std=c++0x "$ScriptName".cpp -o "$ScriptName".obj
	echo -n " Executing..."
	GotOutput=$(printf "$Input" | ./"$ScriptName".obj | tail -n "$TailLines")
	if [ "$GotOutput" != "$ExpectedOutput" ]
	then
		printf " Failed\n    Expected: $ExpectedOutput\n    Got: $GotOutput\n"

		((FAILURES++))
	else
		echo " Passed"
	fi
}

function finalize {
	if [ "$FAILURES" -gt 0 ]
	then
		printf "There are %d failed tests!\n" "$FAILURES"
		exit 1
	fi

	exit 0

}

do_test triangle_centers "0\n6\n3\n0\n0\n0\n" "Centroid: (1, 2)\nOrthocenter: (2.1333, 0.6667)\nCircumcenter: (-0.2333, 3)\nIncenter: (1.1819, 0.8971)" 4

# repeated real root
do_test surd_quadratic "4\n12\n9\n" "One real root: -1.5"
# 2 distinct real roots
do_test surd_quadratic "0.5\n-5\n-774\n" "Two real roots: 44.6611 OR -34.6611\nSurd form: 5 +- 11 sqrt( 13 )" 2
# 2 distinct imaginary roots
do_test surd_quadratic "0.5\n-5\n799\n" "Two imaginary roots: 5 +- sqrt( 1573 ) i\nSurd form: 5 +- 11i sqrt( 13 )" 2

finalize
