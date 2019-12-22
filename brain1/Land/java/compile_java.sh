#!/bin/bash

problem=Land

rm -f grader.jar
javac grader.java $problem.java
jar cfe grader.jar grader *.class
