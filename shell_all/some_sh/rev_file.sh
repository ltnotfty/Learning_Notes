cols=`head -n1 file.txt | wc -w`


for i in `seq 1 $cols`
do
echo `cut -d' ' -f$i file.txt`
done




