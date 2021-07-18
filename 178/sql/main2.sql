# Write your MySQL query statement below
/*
select score Score, @cnt := @cnt + 1 `Rank` 
from scores, (select @cnt := 0) B 
order by score desc;
*/

/*
SELECT Score, `Rank` FROM (
    SELECT score Score,  @cnt := @cnt + 1, @rank := IF(@pre <> (@pre := Score), @cnt, @rank) `Rank`
    FROM Scores, (SELECT @rank := 0, @cnt := 0, @pre := -1) B
    ORDER BY Score DESC
) TB;
*/

SELECT score Score, @rank := @rank + (@pre <> (@pre := Score)) `Rank`
FROM Scores, (SELECT @rank := 0, @pre := -1) B 
ORDER BY Score DESC;

