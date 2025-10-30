#!/bin/bash

# Compile the C++ code
g++ -c -o math.o math.cpp
if [ $? -eq 0 ]; then
  # Run the compiled executable
  ar rcs libmath.a math.o
  	if [ $? -eq 0 ]; then
		g++ main.cpp -L. -lmath -o my_program
		# Check if compilation was successful
		if [ $? -eq 0 ]; then
  		# Run the compiled executable
  		./my_program
		else
  			echo "Linking failed."
		fi
	else
		echo "Static library creation failed"
	fi
  
else
  echo "object file creation failed."
fi




