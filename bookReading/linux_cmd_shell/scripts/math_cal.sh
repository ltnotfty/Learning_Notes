# expr 

expr 5 \* 2
expr 5 \/ 2


# []

v1=10
v2=20

v3=$[$v1 + $v2]
echo $v3





# cal float number bc

v1=10
v2=100.12

v3=$(echo "scale=4;$v1 + $v2" | bc)
v4=$(echo "scale=4;$v1 * $v2" | bc)

echo "v1 + v2 = $v3"
echo "v1 * v2 = $v4"


# more line for bc

v5=$(bc << EOF
scale = 6
a1 =($v3 + $v4)
a2 =($v3 * $v4)
a1 * a2
EOF
)

echo "v5 = v3 * v4 = $v5"
