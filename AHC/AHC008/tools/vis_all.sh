#! /bin/bash
exefile=../../../sample

in_files="./in/*"

num=0

for in_file in $in_files; do
  out_file=./test_results/out$(printf "%04d" $num).txt
  echo input file is $in_file , output_file is $out_file...
  cargo run --release --bin vis  $in_file  $out_file
  mv vis.html ./vis_results/vis$(printf "%04d" $num).html
  # cargo run --release --bin vis $in_file $out_file
  let num++
done

echo The vis all is finished...
# echo The test score is $score_sum.
