# !/bin/bash
read n
step=0
while [ $n -ne 1 ]
do
  step=$((step + 1))
  if [ $((n % 2)) -eq 0 ]
  then
    n=$((n / 2))
  else
    n=$(((3 * n  + 1) / 2))
  fi
done
echo $step