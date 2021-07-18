# Write your MySQL query statement below
select s1.score as Score, (select count(distinct s2.score) from scores as s2 where s2.score >= s1.score) `Rank` from scores as s1 order by s1.score desc;
