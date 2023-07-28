arr=(one two three four five)
echo ${arr[*]} # print whole arr
echo ${arr[0]} # print first item
unset arr[0] # del first item
arr[0]=10 # set first item

