# Write your MySQL query statement below
SELECT 
    C.Name AS Department,
    B.Name AS Employee,
    B.Salary
FROM (
    SELECT DepartmentId, MAX(Salary) Salary_MAX
    FROM Employee
    GROUP BY DepartmentId) A
INNER JOIN Employee B ON A.Salary_MAX = B.Salary AND A.DepartmentId = B.DepartmentId
INNER JOIN Department C ON B.DepartmentId = C.Id
