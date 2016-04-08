#!/bin/bash

function do_test {
	ScriptName="$1"
	Input="$2"
	ExpectedOutput="$3"
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

do_test triangle_centers "" "" # TODO
