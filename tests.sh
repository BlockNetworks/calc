#!/bin/bash

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

