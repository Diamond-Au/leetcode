arr=()
echo "请输入要排序的数组 一行输入 空格分开"
read line
begin=0
index=0
for val in $line; do
  arr[$begin]=$val
  begin=$(expr $begin + 1)
done
index=$begin
begin=0
echo "before sort"
while [ $begin -lt $index ]; do
  echo ${arr[$begin]}
  begin=$(expr $begin + 1)
done
i=0
j=0
while [ $i -lt $(expr $index - 1) ]; do
  j=$(expr $i + 1)
  while [ $j -lt $index ]; do
    if [ ${arr[$i]} -gt ${arr[$j]} ]; then
      tem=${arr[$((j))]}
      arr[$j]=${arr[$i]}
      arr[$i]=$tem
    fi
    j=$(expr $j + 1)
  done
  i=$(expr $i + 1)
done
echo "after sort"
i=0
while [ $i -lt $index ]; do
  echo ${arr[$i]}
  i=$(expr $i + 1)
done
