#!/bin/bash

function do_test {
	ScriptName="$1"
	Input="$2"
	ExpectedOutput=$(printf "$3")
	TailLines="${4:-1}"
	g++ -std=c++0x "$ScriptName".cpp -o "$ScriptName".o
	GotOutput=$(printf "$Input" | ./"$ScriptName".o | tail -n "$TailLines")
	if [ "$GotOutput" != "$ExpectedOutput" ]
	then
		echo "Test $ScriptName failed: Expected: $ExpectedOutput; got: $GotOutput"
		exit 1
	fi
	echo Test "$ScriptName" passed
}

do_test triangle_centers "0\n6\n3\n0\n0\n0\n" "Centroid: (1, 2)\nOrthocenter: (0, 0)\nCircumcenter: (3, 3)\nIncenter: (2, 2)" 4
