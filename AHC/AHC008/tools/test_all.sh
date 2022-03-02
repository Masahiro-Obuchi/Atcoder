#! /bin/bash
exefile=../../../sample

in_files="./in/*"

score_sum=0

num=0

for in_file in $in_files; do
  out_file=./test_results/out$(printf "%04d" $num).txt
  echo input file is $in_file , output_file is $out_file...
  score=$((cargo run --release --bin tester $exefile < $in_file > $out_file) |&  grep "Score" |& grep -o "[0-9]*")
  echo test $num score is $score
  score_sum=$(echo "$score_sum+$score" | bc)
  # cargo run --release --bin vis $in_file $out_file
  let num++
done

echo The result of test: Score sum is $score_sum.
echo The test is finished...
# echo The test score is $score_sum.
