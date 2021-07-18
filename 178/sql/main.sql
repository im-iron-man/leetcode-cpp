# Write your MySQL query statement below
# select score as Score, rank() over(order by score desc) `Rank` from scores;
select score as Score, dense_rank() over(order by score desc) `Rank` from scores;
