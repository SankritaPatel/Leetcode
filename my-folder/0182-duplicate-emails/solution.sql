# Write your MySQL query statement below
SELECT email AS EMAIL from Person group by email having count(email)>1 ;
