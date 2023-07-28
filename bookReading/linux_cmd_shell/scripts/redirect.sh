
# std err and std out will output to /dev/null
echo Hello > /dev/null 2>&1
# or 
echo Hello &> /dev/null


# stderr output to terminal and rescard stdoutput
echo hello 2>&1 >/dev/null
