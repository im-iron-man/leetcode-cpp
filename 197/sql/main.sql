# Write your MySQL query statement below
SELECT w2.Id FROM Weather w1 INNER JOIN Weather w2 ON DATE_ADD(w1.recordDate, INTERVAL 1 DAY) = w2.recordDate WHERE w1.Temperature < w2.Temperature;
