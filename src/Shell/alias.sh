#!/bin/bash -li

echo There are ${#BASH_ALIASES[*]} aliases define.

for ali in "${#BASH_ALIASES[@]}"; do
	printf "alias: %-10s triggers: %s\n" "$ali" "${BASH_ALIASES[$ali]}"
done
